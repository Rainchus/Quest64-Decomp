#include "common.h"
#include "191F0.h"
#include "1BCD0.h"


typedef struct {
    s16 unk0;
    char unk2[0xCE];
}struct_800880A8;

typedef struct {
    s32 unk0;
    s32 unk4;
}struct_80087210;

extern struct_80087210 D_80087210[];

extern struct_800880A8 D_800880A8[4];

#pragma GLOBAL_ASM("asm/nonmatchings/191F0/func_800185F0.s")

void func_800186F8(void);
void func_80018B14(void);
void func_800193B4(void);
void func_80018F60(void);

void func_80018638(Mtx* arg0) {
    func_800186F8();
    func_80018B14();
    func_800193B4();
    func_80019CCC(arg0);
    func_8001A398(arg0);
    func_80018F60();
}

//#pragma GLOBAL_ASM("asm/nonmatchings/191F0/func_80018684.s") @TODO I'm sure this can be written better. 
void func_80018684(void) {
    struct_80087210* ptr;
    s32 count = 8;

    ptr = D_80087210;
    do {
        ptr[0].unk0 = 0;
        ptr[1].unk0 = 0;
        ptr[2].unk0 = 0;
        ptr[3].unk0 = 0;
        ptr += 4;      // advance 4 structs (0x20 bytes)
        count -= 4;
    } while (count != 0);
}

//#pragma GLOBAL_ASM("asm/nonmatchings/191F0/func_800186B4.s")
void func_800186B4(s32 arg0) {
    s32 var_v0 = 7;
    struct_80087210* var_v1 = D_80087210;

    while (var_v0 != 0 && var_v1->unk0 != 0) {
        var_v0--;
        var_v1++;
    }

    var_v1->unk0 = 4;
    var_v1->unk4 = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/191F0/func_800186F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/191F0/func_800187F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/191F0/func_800188C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/191F0/func_80018918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/191F0/func_80018B14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/191F0/func_80018BF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/191F0/func_80018CF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/191F0/func_80018D34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/191F0/func_80018DB4.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/191F0/func_80018DF4.s")
void func_80018DF4(Vec3f* arg0, s32 arg1, s32 arg2) {
    s32 pad[2];
    DamageDigs* var_t0;
    s32 var_v1;
    s32 i;

    i = 9;
    var_t0 = D_800873D0;
        while ((i != 0) && (var_t0->damageDisplayTimer != 0)){
            i--;
            var_t0++;
        }
    var_t0->damageDisplayTimer = 0x2D;
    var_t0->targetPos = arg0;
    var_t0->unk10 = arg1;
    
    if (arg2 < 0) {
        arg2 = -arg2;
    }

    var_t0->numDigits = count_digits(arg2, var_t0->damageDigits, 1U);
    var_v1 = 0;
    
    for(i = 0; i < 10; i++) {
        if((D_800873D0[i].damageDisplayTimer != 0) && (arg0 == D_800873D0[i].targetPos)){
            var_v1++;
        } 
    }
    var_t0->unk18 = var_v1 - 1;
}


#pragma GLOBAL_ASM("asm/nonmatchings/191F0/func_80018F60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/191F0/func_80019324.s")

#pragma GLOBAL_ASM("asm/nonmatchings/191F0/func_80019354.s")

#pragma GLOBAL_ASM("asm/nonmatchings/191F0/func_800193B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/191F0/func_800195E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/191F0/func_80019738.s")

#pragma GLOBAL_ASM("asm/nonmatchings/191F0/func_80019918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/191F0/func_80019A70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/191F0/func_80019A98.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/191F0/func_80019CA4.s")
void func_80019CA4(s32 arg0) {
    D_800880A8[arg0].unk0 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/191F0/func_80019CCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/191F0/func_8001A238.s")

#pragma GLOBAL_ASM("asm/nonmatchings/191F0/func_8001A268.s")

#pragma GLOBAL_ASM("asm/nonmatchings/191F0/func_8001A398.s")

#pragma GLOBAL_ASM("asm/nonmatchings/191F0/func_8001A620.s")

#pragma GLOBAL_ASM("asm/nonmatchings/191F0/func_8001A834.s")
