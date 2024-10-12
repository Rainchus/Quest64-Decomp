#include "common.h"
#include "1850.h"
#include "map_ids.h"
#include "33D0.h"

#pragma GLOBAL_ASM("asm/nonmatchings/1850/func_80000C50.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/1850/func_80000EEC.s")
void func_80000EEC(void) {
    gGameState = 0x160;
    gGameMode = 4;
    gNextMap = -1;
    D_80084EF8 = -1;
    D_80084F04 = -1;
    D_80084F14 = 0xFFFF;
    D_80086E44 = 0.0f;
    D_800859E2 = 0;
    gCurrentMap = MAP_MONASTERY;
    gCurrentSubmap = SUBMAP_ABBOTS_CHAMBER;
    D_80085368.unk8 = -1;
    D_8007BA60 = 0xD;
    D_8007BA62 = 0x11;
    D_8007BA64 = 0;
    D_8007BA40 = -26.0f;
    D_8007BA44 = 0.0f;
    D_8007BA48 = M_PI/2;
    D_8007BA4C = 0x108;
    gPlayerMainData.unk3E = 0;
    D_8007B2E8 = 1;
    D_8007B2F0 = 0;
    D_8007B344 = 0;
    D_8007B345 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/1850/func_80000FE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1850/func_8000111C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1850/func_800011DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1850/func_80001800.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1850/func_800020B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1850/func_8000227C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1850/func_80002428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1850/func_800025E8.s")
