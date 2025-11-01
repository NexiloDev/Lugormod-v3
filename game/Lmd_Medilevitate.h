#ifndef LMD_MEDILEVITATE
#define LMD_MEDILEVITATE

#pragma once
#include "gentity_t.h"

void lmd_meditate_levitate_update(gentity_t* self);
qboolean lmd_meditate_levitate_abort(gentity_t* self);
void lmd_meditate_levitate_end(gentity_t* self);

#endif