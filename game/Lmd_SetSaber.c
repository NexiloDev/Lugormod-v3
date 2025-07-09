#include "Lmd_SetSaber.h"

extern qboolean G_SetSaber(gentity_t *ent, int saberNum, char *saberName, qboolean siegeOverride);
extern qboolean G_SaberModelSetup(gentity_t* ent);
extern qboolean WP_SaberStyleValidForSaber(saberInfo_t *saber1, saberInfo_t *saber2, int saberHolstered, int saberAnimLevel);
extern qboolean WP_UseFirstValidSaberStyle(saberInfo_t *saber1, saberInfo_t *saber2, int saberHolstered, int *saberAnimLevel);

extern vmCvar_t lmd_allow_set_saber;
extern vmCvar_t lmd_set_saber_duels;
extern vmCvar_t lmd_set_saber_delay;
void lmd_checkSaberChanges(gentity_t* ent)
{
    if (!ent || !ent->client || !ent->inuse) return;

    if (!lmd_allow_set_saber.integer
            || (ent->client->ps.duelInProgress && !lmd_set_saber_duels.integer)
            || level.time - ent->client->ps.forceHandExtendTime < 750
            || ent->client->ps.saberMove != LS_READY
            || ent->client->ps.saberInFlight) return;
    
    int clientNum = ent - g_entities;
    
    char userinfo[MAX_INFO_STRING];
    char saber1[MAX_QPATH];
    char saber2[MAX_QPATH];

    trap_GetUserinfo(clientNum, userinfo, sizeof(userinfo));
    Q_strncpyz(saber1, Info_ValueForKey(userinfo, "saber1"), sizeof(saber1));
    Q_strncpyz(saber2, Info_ValueForKey(userinfo, "saber2"), sizeof(saber2));
    
    if (!clientSaberHistory[clientNum].initialized)
    {
        Q_strncpyz(clientSaberHistory[clientNum].saber1, saber1, sizeof(clientSaberHistory[clientNum].saber1));
        Q_strncpyz(clientSaberHistory[clientNum].saber2, saber2, sizeof(clientSaberHistory[clientNum].saber2));
        clientSaberHistory[clientNum].initialized = qtrue;
        return;
    }
    
    if (Q_stricmp(saber1, clientSaberHistory[clientNum].saber1) ||
        Q_stricmp(saber2, clientSaberHistory[clientNum].saber2))
    {
        if (ent->client->ps.saberHolstered == 0) ent->client->Lmd.setSaber.openAgain = qtrue;
        ent->client->ps.saberHolstered = 2;
        
        G_SetSaber(ent, 0, saber1, qfalse);
        G_SetSaber(ent, 1, saber2, qfalse);

        // Make sure userinfo is updated properly
        trap_SetUserinfo(clientNum, userinfo);
        ClientUserinfoChanged(clientNum);

        G_SaberModelSetup(ent);

        // Update saber style
        if (ent->client->saber[0].model[0] && ent->client->saber[1].model[0])
        {
            // dual
            ent->client->ps.fd.saberAnimLevelBase = ent->client->ps.fd.saberAnimLevel = ent->client->ps.fd.
                saberDrawAnimLevel = SS_DUAL;
        }
        else if (ent->client->saber[0].saberFlags & SFL_TWO_HANDED)
        {
            // staff
            ent->client->ps.fd.saberAnimLevel = ent->client->ps.fd.saberDrawAnimLevel = SS_STAFF;
        }
        else
        {
            // single
            if (ent->client->sess.saberLevel < SS_FAST)
            {
                ent->client->sess.saberLevel = SS_FAST;
            }
            else if (ent->client->sess.saberLevel > SS_STRONG)
            {
                ent->client->sess.saberLevel = SS_STRONG;
            }
            ent->client->ps.fd.saberAnimLevelBase = ent->client->ps.fd.saberAnimLevel = ent->client->ps.fd.
                saberDrawAnimLevel = ent->client->sess.saberLevel;
            if (ent->client->ps.fd.saberAnimLevel > ent->client->ps.fd.forcePowerLevel[FP_SABER_OFFENSE])
            {
                ent->client->ps.fd.saberAnimLevelBase = ent->client->ps.fd.saberAnimLevel = ent->client->ps.fd.
                    saberDrawAnimLevel = ent->client->sess.saberLevel = ent->client->ps.fd.forcePowerLevel[
                        FP_SABER_OFFENSE];
            }
        }
        
        if (!WP_SaberStyleValidForSaber(&ent->client->saber[0], &ent->client->saber[1], ent->client->ps.saberHolstered,
                                        ent->client->ps.fd.saberAnimLevel))
        {
            WP_UseFirstValidSaberStyle(&ent->client->saber[0], &ent->client->saber[1], ent->client->ps.saberHolstered,
                                       &ent->client->ps.fd.saberAnimLevel);
            ent->client->ps.fd.saberAnimLevelBase = ent->client->saberCycleQueue = ent->client->ps.fd.saberAnimLevel;
        }
        
        Q_strncpyz(clientSaberHistory[clientNum].saber1, saber1, sizeof(clientSaberHistory[clientNum].saber1));
        Q_strncpyz(clientSaberHistory[clientNum].saber2, saber2, sizeof(clientSaberHistory[clientNum].saber2));

        ent->client->Lmd.setSaber.delayTime = level.time +  lmd_set_saber_delay.integer;
        ent->client->ps.weaponTime = lmd_set_saber_delay.integer;
        ent->client->Lmd.setSaber.newRequest = qtrue;
    }
}
