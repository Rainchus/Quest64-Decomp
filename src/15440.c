#include "common.h"
#include "el_math.h"
#include "33D0.h"
#include "monsters.h"

typedef struct {
    char unk0[0x8C];
    u16 unk8C;
}struct_80018278_arg1_2;

typedef struct {
    char unk0[0x68];
    struct_80018278_arg1_2* unk68;
}struct_80018278_arg1;

typedef struct {
    s32 unk0;
    u16 unk4;
    char unk6[0x36];
}unk15b50s;

typedef struct {
    char unk0[0xA];
    u16 unkA;
}struct_800164E4_arg0;

extern unk15b50s D_80086F18[];
extern s32 D_8007C990;
extern u16 gBattleState;
extern u16 D_8004CD74[];


void func_800208B8(MonsterBattleData* arg0);
#define IN_BOSS_BATTLE gBattleState & 0x100

void func_8001FCF8(struct_80018278_arg1* arg0, u16 arg1, u16 arg2, s16 arg3);

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80014840.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80014890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_800149D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80014A98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80014E80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80014ED4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80014F48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80014FDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_800150C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_800151D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_800152E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80015370.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_800154EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80015630.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_800156D0.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80015B50.s")
s32 func_80015B50(void) {
    unk15b50s* var_v0;
    s32 var_v1;
    
    var_v1 = 10;
    var_v0 = D_80086F18;
    while (var_v1 != 0 && var_v0->unk4 == 0) {
        var_v1--;
        var_v0++;
    }
    return var_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80015B8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80015FE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_8001613C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_800163E8.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_800164E4.s")
s32 func_800164E4(struct_800164E4_arg0* arg0) {
    s32 var_v1;

    var_v1 = 0;
    if (arg0->unkA & 1) {
        var_v1 = func_8001613C();
    }
    return var_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80016520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_800165E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_8001679C.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80016940.s")
void func_80016940(s32 arg0, MonsterBattleData* arg1) { //@TODO Confirm that this is MonsterBattleData, 
    if (arg1->transformAnimation.unk5E & 1) {           //and not something that targets player as well
        arg1->transformAnimation.unk50 = -1;
        D_8007C990 -= 1;
        return;
    }
    if (!(IN_BOSS_BATTLE)) {
        gBattleState |= 0x10;
        D_8007BAB8.PlayerMainStats->MPXP++;
        return;
    }
    func_800208B8(arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_800169C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80016A84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80016B18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80016BEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80016CB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80016D60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80016D98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80016F88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80016FFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_8001700C.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80017094.s")
void func_80017094(s32 arg0, struct_80018278_arg1* arg1) {
    u16* temp_v0;

    temp_v0 = arg1->unk68;
    *temp_v0 |= 2;
    func_8001FCF8(arg1, 2U, 2U, -1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_800170DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_8001715C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_800171E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_800172A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_8001737C.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_800173E0.s")
void func_800173E0(s32 arg0, struct_80018278_arg1* arg1) {
    u16* temp_v0;

    temp_v0 = arg1->unk68;
    *temp_v0 |= 0x80;
    func_8001FCF8(arg1, 0x80U, 0xAU, -1);
}

//#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80017428.s")
void func_80017428(s32 arg0, struct_80018278_arg1* arg1) {
    u16* temp_v0;

    temp_v0 = arg1->unk68;
    *temp_v0 |= 0x100;
    func_8001FCF8(arg1, 0x100U, 4U, -1);
}

//#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80017470.s")
void func_80017470(s32 arg0, struct_80018278_arg1* arg1) {
    u16* temp_v0;

    temp_v0 = arg1->unk68;
    *temp_v0 |= 0x200;
    func_8001FCF8(arg1, 0x200U, 3U, -1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_800174B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_800175B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_800175D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_800177F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80017998.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80017BD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80017D04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80017FA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_8001817C.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80018278.s")
s32 func_80018278(s32 arg0, struct_80018278_arg1* arg1) {
    return arg1->unk68->unk8C & D_8004CD74[arg0];
}

//#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_8001829C.s")
void func_8001829C(s32 arg0, struct_80018278_arg1* arg1) {
    arg1->unk68->unk8C |= D_8004CD74[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_800182C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80018318.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_800183C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80018484.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15440/func_80018524.s")
