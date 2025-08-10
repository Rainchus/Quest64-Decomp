#ifndef _VARIABLES_H_
#define _VARIABLES_H_

#include "ultra64.h"
#include "common_structs.h"

extern OSMesgQueue gSIMessageQ;
extern Gfx* gMasterGfxPos;
extern u8 gInventory[INVENTORY_SIZE];
extern OSPfs gPFS[];
extern s8 gCurrControllerNum;
extern OSMesgQueue gSIMessageQ;
extern Unk3 D_80092A38[4];
extern OSMesgQueue D_80092880;
extern OSContPad gPad[4];
extern OSContStatus D_80092A90[4];
extern OSMesg D_80092AA0;
extern s8 gPadStickX;
extern s8 gPadStickY;
extern u16 gPadButtonPressed;
extern u16 D_80092876;
extern u16 D_80092878;
extern u8 D_80092A88;
//unsorted symbols
extern s32 gGameState;
extern u16 gGameMode;
extern s32 gNextMap;
extern s32 gNextSubmap;
extern s32 D_80084EF8;
extern s32 D_80084F04;
extern u16 D_80084F14;
extern f32 D_80086E44;
extern u16 D_800859E2;
extern s32 gCurrentMap;
extern s32 gCurrentSubmap;
extern s32 D_80085370;
extern u16 D_8007BA60;
extern u16 D_8007BA62;
extern u16 D_8007BA64;
extern u16 D_8007B2E8;
extern s16 D_8007B2F0;
extern u8 D_8007B344;
extern u8 D_8007B345;
extern s32 D_8007B348;
extern f32 D_8007BA40;
extern f32 D_8007BA44;
extern f32 D_8007BA48;
extern s32 D_8007BA4C;
extern s32 gCurrentTime;
extern s32 gDayLength;
extern u16 gCurrentDay; 
extern s32 D_8008C634;
extern s32 D_800859D8;

#endif //_VARIABLES_H_
