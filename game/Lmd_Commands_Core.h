
#ifndef LMD_COMMANDS_CORE_H
#define LMD_COMMANDS_CORE_H

#include "Lmd_Commands_Public.h"

#define RATIO_KILL_DEATH 1
#define RATIO_DUEL_WIN_LOSS 2
#define RATIO_HIT_MISS 3

cmdEntry_t *Commands_GetEntry(const char *name);
cmdCategory_t *Commands_GetCategory(const char *name);
qboolean Commands_PlayerCanUseCommand(gentity_t *ent, cmdEntry_t *cmd);
extern cmdCategory_t Categories[];


#endif