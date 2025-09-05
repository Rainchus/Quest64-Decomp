#include "common.h"
#include "1D160.h"
#include "1BCD0.h"

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    s16 unk14;
    u16 unk16;
}struct_80084E60;

typedef struct {
    s32 unk0;
    char unk4[0x1C - 0x4];
    s32 unk1C;
    char unk20[0x38 - 0x20];
    s32 unk38;
    char unk3C[0x54 - 0x3C];
    s32 unk54;
    char unk58[0x70 - 0x58];
}struct_8000E3C4;

typedef struct {
    u16 unk0;
    char unk2[0x1C - 0x2];
    f32 unk1C;
    char unk20[0x34 - 0x20];
    f32 unk34;
}struct_8000E350;


extern s32 D_8007D2D0;
extern struct_8000E3C4 D_80084098;
extern struct_8000E3C4 D_80084180;
extern struct_80084E60 D_80084E60[4];

#pragma GLOBAL_ASM("asm/nonmatchings/C910/func_8000BD10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/C910/func_8000C42C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/C910/func_8000C4C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/C910/func_8000CE8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/C910/func_8000D518.s")

#pragma GLOBAL_ASM("asm/nonmatchings/C910/func_8000D9BC.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/C910/func_8000DB10.s") //Init door timers.
void func_8000DB10(void)
{
    struct_80084E60 *var_v0 = D_80084E60;
    s32 var_a0 = 4;

  while (var_a0--)
  {
      var_v0->unk0 = 0;
      var_v0++;
  }
}

//#pragma GLOBAL_ASM("asm/nonmatchings/C910/func_8000DB38.s")
s32 func_8000DB38(s32 arg0) {
    s32 var_v1 = 4;
    struct_80084E60* var_v0 = D_80084E60;

    while (var_v1 != 0) {
        if ((var_v0->unk0 != 0) && (arg0 == var_v0->unk10)) {
            var_v1 = 5 - var_v1;
            break;
        }

        var_v1 -= 1;
        var_v0++;
    }

    return var_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/C910/func_8000DB7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/C910/func_8000DC4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/C910/func_8000DDB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/C910/func_8000E10C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/C910/func_8000E224.s")

#pragma GLOBAL_ASM("asm/nonmatchings/C910/func_8000E2C0.s")
//https://decomp.me/scratch/mF7ad

//#pragma GLOBAL_ASM("asm/nonmatchings/C910/func_8000E350.s")
void func_8000E350(struct_8000E350* arg0) {

    arg0->unk1C += arg0->unk34 / 2;
    arg0->unk34 -= 0.2;
    
    gDPSetEnvColor(gMasterGfxPos++, 0xFF, 0xFF, 0xFF, arg0->unk0 * 5);
}

//#pragma GLOBAL_ASM("asm/nonmatchings/C910/func_8000E3C4.s") @TODO this loop is unrolled, and may need to be rolled back up. 
void func_8000E3C4(void) {
    s32 var_v0;
    struct_8000E3C4* var_a0;
    struct_8000E3C4* var_v1;

    D_8007D2D0 = 0;
    var_v0 = 8;
    var_v1 = &D_80084098;
    var_a0 = &D_80084180;
    do {
        var_a0->unk0 = 0;
        var_v1->unk0 = 0;
        var_a0->unk1C = 0;
        var_v1->unk1C = 0;
        var_a0->unk38 = 0;
        var_v1->unk38 = 0;
        var_a0->unk54 = 0;
        var_v1->unk54 = 0;
        var_v0 -= 4;
        var_v1++;
        var_a0++;
    } while (var_v0 != 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/C910/func_8000E418.s")

#pragma GLOBAL_ASM("asm/nonmatchings/C910/func_8000E588.s")

#pragma GLOBAL_ASM("asm/nonmatchings/C910/func_8000E774.s")

#pragma GLOBAL_ASM("asm/nonmatchings/C910/func_8000EB30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/C910/func_8000EDD8.s")
