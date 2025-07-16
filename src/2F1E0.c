#include "common.h"
#include "31F00.h"
#include "bgm.h"

typedef struct Message
{
/*0x000*/    s32 unk0; //textbox state? 
/*0x004*/    s16 xpos; //textbox xpos
/*0x006*/    s16 ypos; //textbox ypos
/*0x008*/    s16 width; //width
/*0x00A*/    s16 height; //height
/*0x00C*/    s16 quillTimer; //quill position timer
/*0x00E*/    u8 unkE;
/*0x00F*/    s8 unkF;
/*0x010*/    s8 unk10;
/*0x011*/    s8 unk11;
/*0x012*/    s16 unk12;
/*0x014*/    u8 unk14;
/*0x015*/    s8 unk15;
/*0x016*/    u8 unk16;
/*0x017*/    u8 unk17[0x20];
/*0x037*/    char unk37;
/*0x038*/    s16 unk38;
/*0x03A*/    s16 unk3A;
/*0x03B*/    u8 unk3C[4][0x18];
/*0x09B*/    u8 unk9C[0x400];
/*0x49B*/    u8 unk49C[0x400];
} Message; // size = 0x89C

typedef struct {
    s32 unk0;//0 when normal message 2 when yes/no available
    char unk4[4];
    u8* option_one;
    u8* option_two;
}MessageType;

typedef struct {
    u16 xpos;
    u16 ypos;
    u16 width;
    u16 height;
}MessageBoxAttributes;

extern MessageType D_800905C8;
extern u8 gNPCName[];

extern s8 D_8005F9B0[8];
extern MessageBoxAttributes gMessageBoxAttributes[4]; //gMessageBoxAttributes
extern MessageBoxAttributes gYesNoBoxAttributes; //gYesNoBoxAttributes
extern s8 gMessageSpeed; //in data as the first of 4 bytes
extern s32 D_8007C990;
extern Message D_800905E0[3];
extern u8 gMessageBuffer[0x400];
extern s32 gMessageBoxOpen;

extern u8 D_80092850;
extern u16 D_80092852;


//functions

void func_8002E628(s32 arg0, u8 arg1);

void func_80030D70(void);
u32 func_80030D80(void);

//#pragma GLOBAL_ASM("asm/nonmatchings/2F1E0/func_8002E5E0.s")
void func_8002E5E0(s32 arg0) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_8002E628(var_s0, 0U);
        var_s0 += 1;
    } while (var_s0 != 4);
}

//#pragma GLOBAL_ASM("asm/nonmatchings/2F1E0/func_8002E628.s") //!TODO something here is obviously wrong, since xpos is being set to ypos and width is being set to height
void func_8002E628(s32 arg0, u8 arg1) {
    s32 i;
    s32 j;

    if (!arg1) {
        D_800905E0[arg0].ypos = 0;
        D_800905E0[arg0].height = 0;
        D_800905E0[arg0].unk0 = 0;
        D_800905E0[arg0].xpos = D_800905E0[arg0].ypos;
        D_800905E0[arg0].width = D_800905E0[arg0].height;
    }
    D_800905E0[arg0].quillTimer = 1;
    D_800905E0[arg0].unkE = 0;
    D_800905E0[arg0].unkF = 0;
    D_800905E0[arg0].unk10 = 0;
    D_800905E0[arg0].unk12 = 0;
    D_800905E0[arg0].unk14 = -1;
    D_800905E0[arg0].unk15 = 0;
    D_800905E0[arg0].unk16 = 0;

    for (i = 0; i < 0x20; i++) {
        D_800905E0[arg0].unk17[i] = -1;
    }
    
    for(i = 0 ; i < 0x400; i++){
        D_800905E0[arg0].unk9C[i] = -1;
        D_800905E0[arg0].unk49C[i] = -1;
    }
    
    D_800905E0[arg0].unk38 = 0;
    D_800905E0[arg0].unk3A = 0;
    for(i = 0; i != 0x18; i++) {
        for (j = 0; j < 4; j++) {
            D_800905E0[arg0].unk3C[j][i] = -1;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/2F1E0/func_8002E768.s")
//https://decomp.me/scratch/cqbbL

#pragma GLOBAL_ASM("asm/nonmatchings/2F1E0/func_8002EAA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2F1E0/func_8002FB30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2F1E0/func_8002FD90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2F1E0/func_8002FEA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2F1E0/func_80030068.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2F1E0/func_800303E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2F1E0/func_80030668.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/2F1E0/func_80030754.s")
s32 func_80030754(s32 arg0, s32 arg1) {
    Message *var_a1;
    s32 i;
    s32 ret = -1;
    
    if (arg0 >= 0)
    {
        for(i = 0, var_a1 = D_800905E0; i < 4; i++, var_a1++) {
            if(arg0 == var_a1->unkE) {
                ret = i;
                break;
            }  
        }
    }
    else
    {
        for(i = 0, var_a1 = D_800905E0; i < 4; i++, var_a1++) {
            if((var_a1->unk0 & 7) == arg1) {
                ret = i;
                break;
            }
        }
    }
    return ret;
}
  
#pragma GLOBAL_ASM("asm/nonmatchings/2F1E0/func_800307D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2F1E0/func_80030BF0.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/2F1E0/func_80030D70.s")
void func_80030D70(void) {
    D_80092852 = 0;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/2F1E0/func_80030D80.s")
u32 func_80030D80(void)
{
  u32 ret;
  u32 stick_magnitude;
  ret = 0;
  if (D_80092850 != 0)
  {
    stick_magnitude = ((gPadStickX * gPadStickX) + (gPadStickY * gPadStickY));
    if (stick_magnitude >= 0xE11U)
    {
      D_80092852++;
      if (D_80092852 >= 5)
      {
        ret = 1;
      }
    }
    else
    {
      D_80092852 = 0;
    }
  }
  return ret;
}

