#ifndef _COMMON_H_
#define _COMMON_H_

#include "ultra64.h"
#include "functions.h"

//until I can use proper n64 libs
typedef u8 Addr[];
typedef unsigned short uint16_t;
typedef uint16_t  qu102_t;
typedef short int16_t;
typedef int16_t  qs510_t;

#define qs510(n)		((qs510_t)((n) * 0x0400))
#define qu102(n)                      ((qu102_t)((n)*0x0004))

extern Gfx* gMasterGfxPos;
extern u8 gInventory[150];

#include "common_structs.h"
#include "ld_addrs.h"

#endif

