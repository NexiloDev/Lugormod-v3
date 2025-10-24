#include "Lmd_Crosshair.h"

void lmd_crosshairEntText(const gentity_t* ent)
{
    if (!ent
        || !ent->client
        || ent->client->Lmd.lmdMenu.entityNum != 0
        || ent->client->ps.torsoAnim == 1328) // lumaya: thats the USE anim lol
            return;
    
    const int lastEntNum = ent->client->Lmd.crosshairText.entNum;
    
    const int tracedEntNum = ent->client->Lmd.crosshairEntNum;
    
    if (tracedEntNum == ENTITYNUM_NONE || tracedEntNum >= MAX_GENTITIES)
        return;
    
    const gentity_t* tracedEnt = &g_entities[tracedEntNum];
    const char* tracedText = tracedEnt->Lmd.crosshairText;

    const qboolean hasNewValidText = tracedText && tracedText[0];
    const int newEntNum = hasNewValidText ? tracedEntNum : 0;
    
    if (lastEntNum != newEntNum && lastEntNum != 0)
    {
        trap_SendServerCommand(ent - g_entities, "cp \"\"");
    }
    
    ent->client->Lmd.crosshairText.entNum = newEntNum;
    
    if (lastEntNum != newEntNum)
    {
        ent->client->Lmd.crosshairText.debounceTime = 0;
    }

    vec3_t tracedEntOrigin;

    if (tracedEnt->r.bmodel)
    {
        vec3_t temp;
        vec3_t center;
        VectorAverage(tracedEnt->r.mins, tracedEnt->r.maxs, center);
        VectorCopy(center, temp);

        RotatePointAroundVector(temp, axisDefault[0], center, tracedEnt->r.currentAngles[2]);
        RotatePointAroundVector(temp, axisDefault[1], center, tracedEnt->r.currentAngles[0]);
        RotatePointAroundVector(temp, axisDefault[2], center, tracedEnt->r.currentAngles[1]);
        
        VectorAdd(temp, tracedEnt->r.currentOrigin, tracedEntOrigin);
    }
    else
    {
        VectorCopy(tracedEnt->r.currentOrigin, tracedEntOrigin);
    }
        
    
    if (newEntNum && ent->client->Lmd.crosshairText.debounceTime < level.time
        && Distance(ent->client->ps.origin, tracedEntOrigin) <= tracedEnt->Lmd.crosshairTextRange)
    {
        trap_SendServerCommand(ent - g_entities, va("cp \"%s\n\"", tracedText));
        ent->client->Lmd.crosshairText.debounceTime = level.time + 1000;
    }
}


void lmd_crosshairEntTrace(const gentity_t* ent)
{
    if (!ent->client)
        return;
    
    trace_t tr;
    vec3_t fPos,maxs,mins;

    AngleVectors(ent->client->ps.viewangles, fPos, 0, 0);
    VectorSet( mins, -8, -8, -8 );
    VectorSet( maxs, 8, 8, 8 );

    fPos[0] = ent->client->renderInfo.eyePoint[0] + fPos[0]*9999;
    fPos[1] = ent->client->renderInfo.eyePoint[1] + fPos[1]*9999;
    fPos[2] = ent->client->renderInfo.eyePoint[2] + fPos[2]*9999;

    trap_Trace(&tr,ent->client->renderInfo.eyePoint, mins, maxs, fPos, ent->s.number, ent->clipmask);

    ent->client->Lmd.crosshairEntNum = tr.entityNum;
}
