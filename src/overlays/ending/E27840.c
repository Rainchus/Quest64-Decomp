#include "common.h"
#include "ovl_ending.h"

//#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ending/E27840/func_80100000_ovl_ending.s")
void func_80100000_ovl_ending(void) {
    func_80100970_ovl_ending();
    D_80156FC0 = 0xA;
    D_80156FC4 = 1;
    D_80156FC8 = 0x12C;
    D_80156FCC = 0xDF;
    D_80156FDC = 0;
    D_80156FE0 = 0;
    D_80156FD0 = 0;
    D_80156FD4 = 0;
    D_80156FE4 = 0;
    D_801035A0_ovl_ending = 0;
    D_801035A4_ovl_ending = 0;
    D_80156FD8 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ending/E27840/func_8010008C_E278CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ending/E27840/func_80100184_ovl_ending.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ending/E27840/func_8010082C_ovl_ending.s")
s32 func_8010082C_ovl_ending(s32 arg0, u32* arg1) {
    u32 i,j;
    
    for (i = 0; i < D_801061B8_ovl_ending; i++) {
        for (j = 0; j < D_801061B0_ovl_ending[i].unk4; j++) {
            if (arg0 == D_801061B0_ovl_ending[i].unk0[j].unk22) {
                *arg1 = i;
                return j;
            }
        }
    }
    
    return -1;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ending/E27840/func_801008A8_ovl_ending.s")
void func_801008A8_ovl_ending(s16 arg0, s32 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9, s32 argA, s32 argB, s32 argC, s32 argD) {
    unk80156fe8_s* temp_v0;

    temp_v0 = &D_80156FE8[arg0];
    temp_v0->unk0 = arg1;
    temp_v0->unk4 = arg2;
    temp_v0->unk6 = arg3;
    temp_v0->unkC = arg4;
    temp_v0->unkE = arg5;
    temp_v0->unk8 = arg6;
    temp_v0->unkA = arg7;
    temp_v0->unk10 = arg8;
    temp_v0->unk12 = arg9;
    temp_v0->unk14 = argB;
    temp_v0->unk18 = argA;
    temp_v0->unk4C = 0;
    temp_v0->unk4E = 0xFF;
    temp_v0->unk32 = 0;
    temp_v0->unk24 = 0;
    temp_v0->unk34 = 0;
    temp_v0->unk40 = 0.0f;
    temp_v0->unk44 = 0.0f;
    temp_v0->unk48 = 0.0f;
    temp_v0->unk1C = 0.0f;
    temp_v0->unk20 = 0.0f;
    temp_v0->unk38 = argC;
    temp_v0->unk3C = argD;
    temp_v0->unk2E = temp_v0->unk30 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ending/E27840/func_80100970_ovl_ending.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ending/E27840/func_80100A94_ovl_ending.s")
void func_80100A94_ovl_ending(s32 arg0) {
    unk80156fe8_s* temp_v0;

    temp_v0 = &D_80156FE8[arg0];
    temp_v0->unk0 = 0;
    temp_v0->unk4 = 0;
    temp_v0->unk6 = 0;
    temp_v0->unkC = 0;
    temp_v0->unkE = 0;
    temp_v0->unk8 = 0;
    temp_v0->unkA = 0;
    temp_v0->unk10 = 0;
    temp_v0->unk12 = 0;
    temp_v0->unk14 = 0;
    temp_v0->unk18 = 0;
    temp_v0->unk4E = 0xFF;
    temp_v0->unk32 = 0;
    temp_v0->unk24 = 0;
    temp_v0->unk2A = 0;
    temp_v0->unk2C = 0;
    temp_v0->unk26 = 0;
    temp_v0->unk28 = 0;
    temp_v0->unk34 = 0;
    temp_v0->unk4C = 0;
    temp_v0->unk38 = 0;
    temp_v0->unk3C = 0;
    temp_v0->unk48 = 0.0f;
    temp_v0->unk1C = 0.0f;
    temp_v0->unk20 = 0.0f;
    temp_v0->unk40 = 0.0f;
    temp_v0->unk44 = 1.0f;
    temp_v0->unk2E = temp_v0->unk30 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ending/E27840/func_80100B38_ovl_ending.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ending/E27840/func_80100BE8_ovl_ending.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ending/E27840/func_80100C98_ovl_ending.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ending/E27840/func_80100D80_ovl_ending.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ending/E27840/func_80100EE4_ovl_ending.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ending/E27840/func_80101040_ovl_ending.s")
void func_80101040_ovl_ending(s32 arg0) {
    unk80156fe8_s* temp_v0;

    temp_v0 = &D_80156FE8[arg0];
    temp_v0->unk2E = temp_v0->unk4 + temp_v0->unk8;
    temp_v0->unk30 = temp_v0->unk6 + temp_v0->unkA;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ending/E27840/func_8010107C_ovl_ending.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ending/E27840/func_80101180_ovl_ending.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ending/E27840/func_80101284_ovl_ending.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ending/E27840/func_80101500_ovl_ending.s")
void func_80101500_ovl_ending(s32 arg0, s32 arg1, s32 arg2) {
    unk80156fe8_s* temp_v0;

    temp_v0 = &D_80156FE8[arg0];
    temp_v0->unk2A = (s16) arg1;
    temp_v0->unk2C = (s16) arg2;
    temp_v0->unk26 = temp_v0->unk4;
    temp_v0->unk28 = temp_v0->unk6;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ending/E27840/func_80101534_ovl_ending.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ending/E27840/func_801016B4_ovl_ending.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ending/E27840/func_80101834_ovl_ending.s")
s32 func_80101834_ovl_ending(s32 arg0) {
    unk80156fe8_s* temp_v0;

    temp_v0 = &D_80156FE8[arg0];
    temp_v0->unk34 += 1;
    if (temp_v0->unk34 >= temp_v0->unk38) {
        return 0xFF;
    }
    return 0;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ending/E27840/func_80101880_ovl_ending.s")
void func_80101880_ovl_ending(s32 arg0) {
    D_8015701C[arg0].unk0 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ending/E27840/func_8010189C_ovl_ending.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ending/E27840/func_801028DC_ovl_ending.s")
