#include "common.h"

typedef struct {
    s32 unk0;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s32 unk14;
    s32 unk18;
    f32 unk1C;
    f32 unk20;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    s16 unk2E;
    s16 unk30;
    s16 unk32;
    s16 unk34;
    s16 unk36;
    s32 unk38;
    s32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    s16 unk4C;
    s16 unk4E;
}unk80166250;

extern unk80166250 D_80166250[];

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC1620/func_80100000_ovl_intro.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC1620/func_8010009C_DC16BC.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC1620/func_80101818_ovl_intro.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC1620/func_80101854_ovl_intro.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC1620/func_80101958_ovl_intro.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC1620/func_80101A5C_ovl_intro.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC1620/func_8010200C_ovl_intro.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC1620/func_80102058_ovl_intro.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC1620/func_80102074_ovl_intro.s")
