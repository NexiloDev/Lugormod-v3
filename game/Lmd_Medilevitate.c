#include "Lmd_Medilevitate.h"

#include "g_local.h"

#include <math.h>

#include "Lmd_Professions.h"
#include "Lmd_Prof_Jedi.h"

extern vmCvar_t lmd_levitateInitialUpVelocity;
extern vmCvar_t lmd_levitateInitialBounceMultiplier;
extern vmCvar_t lmd_levitateHealAmount;
extern vmCvar_t lmd_levitateHealInterval;
extern vmCvar_t lmd_levitateBreathSway;
extern vmCvar_t lmd_levitateJediFx;
extern vmCvar_t lmd_levitateSithFx;
extern vmCvar_t lmd_levitateAscentSound;
extern vmCvar_t lmd_levitateDescentSound;
extern vmCvar_t lmd_levitateJediSound;
extern vmCvar_t lmd_levitateSithSound;
extern vmCvar_t lmd_levitateFinish;
extern vmCvar_t lmd_levitateMaxHealth;
extern vmCvar_t lmd_levitateMaxForcePoints;
extern vmCvar_t lmd_levitateRegen;

extern int rageLoopSound;
extern int protectLoopSound;
void lmd_meditate_levitate_update(gentity_t* self)
{
    if (!self || !self->client || !self->inuse || !self->client->Lmd.mediLevitate.enabled ||
        lmd_meditate_levitate_abort(self)) return;

    vec3_t savedVelocity;
    VectorCopy(self->client->ps.velocity, savedVelocity);
    VectorClear(self->client->ps.velocity);

    self->client->Lmd.customSpeed.time = level.time + FRAMETIME;
    self->client->Lmd.customGravity.time = level.time + FRAMETIME;
    self->client->ps.weaponTime = FRAMETIME;
    self->client->ps.forceHandExtendTime = level.time + FRAMETIME;
    self->client->ps.torsoTimer = FRAMETIME;
    self->client->ps.legsTimer = FRAMETIME;

    switch (self->client->Lmd.mediLevitate.state)
    {
    case 0:
        {
            self->client->Lmd.customGravity.value = 1;
            self->client->Lmd.customSpeed.value = 0;
            self->client->ps.saberHolstered = 2;
            self->client->ps.saberMove = LS_NONE;
            self->client->ps.saberBlocked = 0;
            self->client->ps.saberBlocking = 0;
            self->client->Lmd.mediLevitate.runTime = level.time;
            self->client->Lmd.mediLevitate.state = 1;
            self->client->Lmd.mediLevitate.phase = 0.0f;
            VectorCopy(self->client->ps.origin, self->client->Lmd.mediLevitate.startOrigin);
            break;
        }
    case 1:
        {
            self->client->Lmd.customGravity.time = level.time + FRAMETIME;
            self->client->Lmd.customSpeed.time = level.time + FRAMETIME;
            G_SetAnim(self, SETANIM_BOTH, BOTH_FORCE_RAGE,
                      SETANIM_FLAG_OVERRIDE | SETANIM_FLAG_HOLD | SETANIM_FLAG_HOLDLESS, 500);

            if (!self->client->Lmd.mediLevitate.soundStarted)
            {
                self->client->Lmd.mediLevitate.soundStarted = qtrue;

                // Play the initial "rising" sound
                if (lmd_levitateAscentSound.integer)
                {
                    G_Sound(self, CHAN_AUTO, G_SoundIndex("sound/weapons/force/jumpbuild.mp3"));
                }

                // Start the "hum" sound loop (if not yet started)
                const int isSith = (Jedi_GetAccSide(self->client->pers.Lmd.account) == FORCE_DARKSIDE);
                if (lmd_levitateSithSound.integer > 0 && isSith)
                {
                    G_Sound( self, TRACK_CHANNEL_3, rageLoopSound );
                    // Will be stopped by G_MuteSound() in lmd_meditate_levitate_end()
                }
                else if (lmd_levitateJediSound.integer > 0 && !isSith)
                {
                    G_Sound( self, TRACK_CHANNEL_3, protectLoopSound );
                    // Will be stopped by G_MuteSound() in lmd_meditate_levitate_end()
                }
            }

            if (level.time > self->client->Lmd.mediLevitate.runTime + 1500)
            {
                self->client->Lmd.mediLevitate.state = 2;
            }
            break;
        }
    case 2:
        {
            self->client->Lmd.customGravity.time = level.time + FRAMETIME;
            self->client->Lmd.customSpeed.time = level.time + FRAMETIME;
            self->client->ps.velocity[2] = lmd_levitateInitialUpVelocity.value;
            if (level.time > self->client->Lmd.mediLevitate.runTime + 2000)
            {
                self->client->Lmd.mediLevitate.state = 3;
            }
            break;
        }
        
    case 3:
        {
            self->client->Lmd.customGravity.time = level.time + FRAMETIME;
            self->client->Lmd.customSpeed.time = level.time + FRAMETIME;

            const int isSith = (Jedi_GetAccSide(self->client->pers.Lmd.account) == FORCE_DARKSIDE);

            if (lmd_levitateSithFx.integer > 0 && isSith)
            {
                if (level.time > self->client->Lmd.mediLevitate.sithFxTimer)
                {
                    self->client->Lmd.mediLevitate.sithFxTimer = level.time + FRAMETIME;
                    G_PlayEffectID(G_EffectIndex("force/kothos_recharge"), self->client->ps.origin, self->client->ps.viewangles);
                }
            }
            else if (lmd_levitateJediFx.integer > 0 && !isSith)
            {
                self->client->pushEffectTime = level.time + FRAMETIME;
            }
            
            self->client->Lmd.mediLevitate.phase += FRAMETIME / 1000.0f * lmd_levitateInitialBounceMultiplier.
                value;
            if (self->client->Lmd.mediLevitate.phase > 2.0f * M_PI)
                self->client->Lmd.mediLevitate.phase -= 2.0f * M_PI;

            float amplitude = 40.0f;
            float verticalVelocity = sinf(self->client->Lmd.mediLevitate.phase) * amplitude;
            self->client->ps.velocity[2] = savedVelocity[2] + (verticalVelocity - savedVelocity[2]) * 0.1f;

            float swayAmplitude = lmd_levitateBreathSway.value;
            float swayOffset = cosf(self->client->Lmd.mediLevitate.phase) * swayAmplitude;
            self->client->ps.origin[0] += (swayOffset - (self->client->ps.origin[0] - self->client->Lmd.mediLevitate.startOrigin[0])) * 0.1f;

            if (lmd_levitateRegen.integer && self->client->Lmd.mediLevitate.autoHealTimer < level.time)
            {
                if (!isSith && self->health < lmd_levitateMaxHealth.integer)
                {
                    self->health += lmd_levitateHealAmount.integer;
                    if (self->health > lmd_levitateMaxHealth.integer)
                    {
                        self->health = lmd_levitateMaxHealth.integer;
                    }

                    self->client->ps.stats[STAT_MAX_HEALTH] = self->health;
                }
                else if (isSith && self->client->ps.fd.forcePower < lmd_levitateMaxForcePoints.integer)
                {
                    self->client->ps.fd.forcePower += lmd_levitateHealAmount.integer;
                    if (self->client->ps.fd.forcePower > lmd_levitateMaxForcePoints.integer)
                    {
                        self->client->ps.fd.forcePower = lmd_levitateMaxForcePoints.integer;
                    }
                }
                
                float jedi_level = (float)Accounts_Prof_GetLevel(self->client->pers.Lmd.account);
                jedi_level *= 0.5f;
                if (jedi_level < 1.0f)
                    jedi_level = 1.0f;

                int heal_interval = (int)((float)lmd_levitateHealInterval.integer / jedi_level);
                if (heal_interval < 300)
                    heal_interval = 300;

                self->client->Lmd.mediLevitate.autoHealTimer = level.time + heal_interval;
            }
            
            if (lmd_levitateRegen.integer && !self->client->Lmd.mediLevitate.effectFullFxPlayed)
            {
                if (!isSith && self->health >= lmd_levitateMaxHealth.integer)
                {
                    self->client->Lmd.mediLevitate.effectFullFxPlayed = qtrue;
                    G_PlayEffectID(G_EffectIndex("force/heal2"), self->client->ps.origin, vec3_origin);
                    G_Sound(self, CHAN_AUTO, G_SoundIndex("sound/weapons/force/absorb.mp3"));

                    if (lmd_levitateFinish.integer)
                    {
                        lmd_meditate_levitate_end(self);
                        break;
                    }
                }

                if (isSith && self->client->ps.fd.forcePower >= lmd_levitateMaxForcePoints.integer)
                {
                    self->client->Lmd.mediLevitate.effectFullFxPlayed = qtrue;
                    G_PlayEffectID(G_EffectIndex("force/rage2"), self->client->ps.origin, vec3_origin);
                    G_Sound(self, CHAN_AUTO, G_SoundIndex("sound/weapons/force/drain.mp3"));

                    if (lmd_levitateFinish.integer)
                    {
                        lmd_meditate_levitate_end(self);
                        break;
                    }
                }
            }

            G_SetAnim(self, SETANIM_BOTH, BOTH_STAND5TOSIT2,
                      SETANIM_FLAG_OVERRIDE | SETANIM_FLAG_HOLD | SETANIM_FLAG_HOLDLESS, 100);
            break;
        }
    case 4:
        {
            self->client->Lmd.customGravity.time = level.time + FRAMETIME;
            self->client->Lmd.customSpeed.time = level.time + FRAMETIME;
            
            float descendSpeed = -500.0f;
            self->client->ps.velocity[2] += (descendSpeed - self->client->ps.velocity[2]) * 0.05f;
            
            trace_t tr;
            vec3_t start, end;

            VectorCopy(self->client->ps.origin, start);
            VectorCopy(start, end);
            end[2] -= 64;

            trap_Trace(&tr, start, NULL, NULL, end, self->s.number, MASK_PLAYERSOLID);

            if (tr.fraction < 1.0f)
            {
                lmd_meditate_levitate_end(self);
            }

            break;
        }


    default:
        break;
    }
}

qboolean lmd_meditate_levitate_abort(gentity_t* self)
{
    if (!self || !self->client || !self->inuse)
        return qfalse;

    if (self->client->pers.cmd.buttons & BUTTON_ATTACK
        || self->client->pers.cmd.buttons & BUTTON_ALT_ATTACK
        || self->client->pers.cmd.buttons & BUTTON_FORCEPOWER
        || self->client->pers.cmd.buttons & BUTTON_FORCEGRIP
        || self->client->pers.cmd.buttons & BUTTON_FORCE_LIGHTNING
        || self->client->pers.cmd.buttons & BUTTON_FORCE_DRAIN
        || self->client->pers.cmd.upmove)
    {
        lmd_meditate_levitate_end(self);
        return qtrue;
    }

    return qfalse;
}

void lmd_meditate_levitate_end(gentity_t* self)
{
    G_SetAnim(self, SETANIM_BOTH, BOTH_MEDITATE_END, SETANIM_FLAG_OVERRIDE | SETANIM_FLAG_HOLD, 100);

    G_MuteSound(self->client->ps.fd.killSoundEntIndex[TRACK_CHANNEL_3-50], CHAN_VOICE);
    if (
        lmd_levitateDescentSound.integer
        && !(lmd_levitateFinish.integer && self->client->Lmd.mediLevitate.effectFullFxPlayed)
    ) {
        // Play the sound for the descending phase,
        // if enabled AND not currently playing the "full" sound effect because of lmd_levitateFinish,
        // (to avoid playing both sounds at the same time).
        G_Sound(self, CHAN_AUTO, G_SoundIndex("sound/effects/woosh1.mp3"));
    }

    self->client->ps.stats[STAT_MAX_HEALTH] = 100;
    self->client->ps.forceHandExtendTime = level.time + self->client->ps.legsTimer;
    self->client->ps.weaponTime = self->client->ps.legsTimer;
    self->client->Lmd.customSpeed.time = level.time + self->client->ps.legsTimer;
    self->client->Lmd.mediLevitate.soundStarted = qfalse;
    self->client->Lmd.mediLevitate.effectFullFxPlayed = qfalse;
    self->client->Lmd.mediLevitate.enabled = qfalse;
    self->client->Lmd.mediLevitate.state = 0;
}