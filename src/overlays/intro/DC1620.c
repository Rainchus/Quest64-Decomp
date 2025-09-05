#include "common.h"
#include "intro.h"
#include "os.h"
#include "gbi.h"
#include "mbi.h"

typedef struct {
    s16 unk0;
    char unk2[0x4E];
}struct_80166284;

extern struct_80166284 D_80166284;
extern s32 gIntroFadeTimer;

void func_80101148_ovl_intro(void);

void func_80100000_ovl_intro(void) {
    func_80101148_ovl_intro();
    gIntroBGTextureXPosition = 0xA;
    D_80166224 = 1;
    D_80166228 = 0x12C;
    D_8016622C = 0xDF;
    D_8016623C = 0;
    D_80166240 = 0;
    D_80166230 = 0;
    D_80166234 = 0;
    D_80166244 = 0;
    D_80166248 = 0;
    D_8016624C = 0;
    gIntroFadeTimer = 0;
    gIntroFadeAlpha = 0;
    D_80166238 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC1620/func_8010009C_DC16BC_ovl_intro.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC1620/func_80100634_ovl_intro.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC1620/func_80101004_ovl_intro.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC1620/func_80101080_ovl_intro.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC1620/func_80101148_ovl_intro.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC1620/func_8010126C_ovl_intro.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC1620/func_80101310_ovl_intro.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC1620/func_801013C0_ovl_intro.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC1620/func_80101470_ovl_intro.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC1620/func_80101558_ovl_intro.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC1620/func_801016BC_ovl_intro.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC1620/func_80101818_ovl_intro.s")
void func_80101818_ovl_intro(s32 arg0) {
    unk80166250* temp_v0;

    temp_v0 = &D_80166250[arg0];
    temp_v0->unk2E = temp_v0->unk4 + temp_v0->unk8;
    temp_v0->unk30 = temp_v0->unk6 + temp_v0->unkA;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC1620/func_80101854_ovl_intro.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC1620/func_80101958_ovl_intro.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC1620/func_80101A5C_ovl_intro.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC1620/func_80101CD8_ovl_intro.s")
void func_80101CD8_ovl_intro(s32 arg0, s32 arg1, s32 arg2) {
     unk80166250* temp_v0;

    temp_v0 = &D_80166250[arg0];
    temp_v0->unk2A = arg1;
    temp_v0->unk2C = arg2;
    temp_v0->unk26 = temp_v0->unk4;
    temp_v0->unk28 = temp_v0->unk6;
    
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC1620/func_80101D0C_ovl_intro.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC1620/func_80101E8C_ovl_intro.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC1620/func_8010200C_ovl_intro.s")
s32 func_8010200C_ovl_intro(s32 arg0) {
    if (++D_80166250[arg0].unk34 >= D_80166250[arg0].unk38) {
        return 0xFF;
    }
    return 0;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC1620/func_80102058_ovl_intro.s")
void func_80102058_ovl_intro(s32 arg0) {
    (&D_80166284)[arg0].unk0 = 0;
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC1620/func_80102074_ovl_intro.s")
