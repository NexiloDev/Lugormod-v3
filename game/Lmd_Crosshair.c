#include "Lmd_Crosshair.h"

void lmd_crosshairEntText(const gentity_t* ent)
{
    if (ent->client->Lmd.lmdMenu.entityNum != 0) return;
    
    const int lastEntNum = ent->client->Lmd.crosshairText.entNum;
    
    const int tracedEntNum = ent->client->Lmd.crosshairEntNum;
    const char* tracedText = (tracedEntNum != ENTITYNUM_NONE) ? g_entities[tracedEntNum].Lmd.crosshairText : NULL;

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
    
    if (newEntNum && ent->client->Lmd.crosshairText.debounceTime < level.time)
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
    vec3_t tfrom, tto, fwd;

    VectorCopy(ent->client->ps.origin, tfrom);
    tfrom[2] += ent->client->ps.viewheight;
    AngleVectors(ent->client->ps.viewangles, fwd, NULL, NULL);

    tto[0] = tfrom[0] + fwd[0] * 9999;
    tto[1] = tfrom[1] + fwd[1] * 9999;
    tto[2] = tfrom[2] + fwd[2] * 9999;

    trap_Trace(&tr, tfrom, NULL, NULL, tto, ent->s.number, MASK_ALL);
    ent->client->Lmd.crosshairEntNum = tr.entityNum;
}
