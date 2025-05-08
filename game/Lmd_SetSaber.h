#ifndef LMD_SETSABER_H
#define LMD_SETSABER_H
#include "g_local.h"

typedef struct {
    char saber1[MAX_QPATH];
    char saber2[MAX_QPATH];
    qboolean initialized;
} clientSaberInfo_t;

static clientSaberInfo_t clientSaberHistory[MAX_CLIENTS];

void lmd_checkSaberChanges(gentity_t* ent);

#endif