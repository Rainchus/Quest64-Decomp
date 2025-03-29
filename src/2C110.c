#include "common.h"

typedef struct Unk {
    s8 unk_00;
    s8 unk_01;
} Unk;

typedef struct Unk3 {
    s16 unk_00;
    s8 unk_02[0x10];
    char unk_12[1];
    u8 unk_13;
} Unk3;

typedef struct Unk4 {
    u8 unk_00[UNK_SIZE_0];
    u8 unk_20[UNK_SIZE_1];
    u8 unk_30[INVENTORY_SIZE];
    u8 unk_C7[UNK_SIZE_2];
} Unk4; //sizeof 0xC8

extern s32 D_80084EFC;
extern s32 D_80084F00;
extern s32 D_80084F04;
extern s32 D_80084F08;
extern s32 D_80084F0C;
extern s8 D_8005FA00;
extern s8 D_8005F010;
extern Unk4 D_80090398;
extern Unk4 D_800904E0;
extern u8 D_800869D8[UNK_SIZE_0];
extern u8 D_80086AE8[UNK_SIZE_1];
extern u8 D_8007D19C[UNK_SIZE_2];
extern Gfx D_8005FAA0[];
extern u16 D_8008FD0C;
extern u16 D_8008FD20;
extern u8 D_8008FD22;
extern s32 D_8008FD24;
extern s8 D_8008FD29;
extern s8 D_8008FD2A;
extern Unk D_8008FD30[16];
extern SaveData D_8008FD58[16];
extern SaveData D_80090460;
extern Unk3 D_80092A38[4];
extern s8 gCurrControllerNum;
extern u8 D_8008FD28;
extern s8 D_8008FD2B;
extern u8 D_8008FD2C;
extern u8 D_8008FD23;
extern u16 gGameMode;
void func_8002E234(u32 arg0);
s32 func_80031890(s32 arg0, u8 arg1);
s32 func_80031A44(s8, s8, s32, s32, u8*);
s32 osMotorInit(OSMesgQueue* mq, OSPfs* pfs, int channel);
s32 func_80031574(s8);
s32 func_800319E0(s8, s8, s32, s32, void*);
s32 func_80031BB0(s32);
void func_8002B6F0(void);
void func_8002B8C4(void);
void func_8002BCA0(void);
void func_8002C818(s32);
void func_8002D5D4(void);
void func_8002D614(void);
void func_8002D748(void);
void func_8002D8BC(void);
void func_8002DBE0(void);
void func_8002DFD0(void);
void func_8002DD18(void);
s32 func_8003195C(s8, u8);
void func_8002DF6C(void);

void func_8002B510(s32 arg0) {
    gGameMode = 2;
    D_8008FD0C = D_8008FD0C | arg0 | 0x4000;
    D_8008FD20 = 0x1000;
    D_8008FD28 = 0xFF;
    D_8008FD2A = 0;
    D_8008FD29 = 0;
    D_8008FD22 = 0;
    D_8008FD2B = 0;
    D_8008FD2C = 0;
}

void func_8002B57C(void) {
    func_8002DFD0();
    if (!(D_8008FD20 & 0x4000)) {
        if (D_8008FD20 & 0x2000) {
            func_8002B8C4();
            D_8008FD20 = D_8008FD20 | 0x4000;
            D_8008FD20 = D_8008FD20 & ~0x2000;
            D_8008FD2C = 0;
        } else {
            D_8008FD20 = D_8008FD20 | 0x2000;
            D_8008FD23 = 0;
        }
  
    }
    if (D_8008FD20 & 0x4000) {
        switch (D_8008FD20 & 7) {
        case 5:
            func_8002BCA0(); 
            break;
        case 0:
            func_8002C818(0);
            break;
        case 4:
            func_8002D614();
            break;
        case 2:
            func_8002D748();
            break;
        case 3:
            func_8002D8BC();
            break;
        case 1:
            func_8002DBE0();
            break;
        case 6:
            func_8002D5D4();
            break;
        }
    }
    if (D_8008FD20 & 0x2000) {
        func_8002B6F0();
    }
    if (D_8008FD20 & 0x8000) {
        D_8008FD0C &= ~0x8000;
    }
}

typedef struct Unk5 {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
} Unk5;

extern Unk5 D_8006A014[];
extern u8* gControllerPakMessages[];
void func_80029B58(s32, s32, s32, s32, s32);

void func_8002B6F0(void) {
    char pad[4];
    Unk5* temp_v0;
    s16 temp_s0;
    s16 temp_s1;
    s16 temp_s2;
    s16 temp_s3;

    temp_v0 = &D_8006A014[D_8008FD23];
    temp_s2 = temp_v0->unk_00;
    temp_s0 = temp_v0->unk_02;
    temp_s3 = temp_v0->unk_04;
    temp_s1 = temp_v0->unk_06;
    func_80029B58(0, temp_s2, temp_s0, temp_s3, temp_s1);
    func_80029B58(0x37, temp_s2 + 3, (temp_s0 + temp_s1), temp_s3, 3);
    func_80029B58(0x37, (temp_s2 + temp_s3), (temp_s0 + 6), 2, temp_s1 - 5);
    func_80029B58(0x37, (temp_s2 - 1), temp_s0 - 1, (temp_s3 + 2), 1);
    func_80029B58(0x37, (temp_s2 - 1), (temp_s0 + temp_s1), (temp_s3 + 2), 1);
    func_80029B58(0x37, (temp_s2 - 1), temp_s0, 1, temp_s1);
    func_80029B58(0x37, (temp_s2 + temp_s3), temp_s0, 1, temp_s1);
    func_80029B58(0x38, (temp_s2 + 1), (temp_s0 + 1), temp_s3 - 3, 1);
    func_80029B58(0x38, (temp_s2 + 1), temp_s0 + 2, 1, temp_s1 - 4);
    func_80029B58(0x39, (temp_s2 + 1), (temp_s0 + temp_s1) - 2, temp_s3 - 2, 1);
    func_80029B58(0x39, (temp_s2 + temp_s3) - 2, (temp_s0 + 1), 1, temp_s1 - 3);
    func_80030EA0(temp_s2 + 6, (temp_s0 + 6), gControllerPakMessages[D_8008FD23]);
    func_8002DF6C();
}

void func_8002B8C4(void) {
    s32 sp1C;
    s32 sp18;
    s32 temp_v0;
    s32 var_a0_2;

    sp1C = D_8008FD0C & 0xC;
    if (D_8008FD20 & 0x1000) {
        temp_v0 = osPfsInitPak(&gSIMessageQ, &gPFS[gCurrControllerNum], gCurrControllerNum);
        if (temp_v0 == 2) {
            temp_v0 = 0;
        } else if (temp_v0 == 0xA) {
            if (osMotorInit(&gSIMessageQ, &gPFS[gCurrControllerNum], gCurrControllerNum) == 0) {
                temp_v0 = 1;
            } else {
                temp_v0 = 0xA;
            }
        }
        sp18 = temp_v0;
        D_8008FD20 &= ~0x1000;
    }
    var_a0_2 = sp18;
    if (var_a0_2 == 0) {
        var_a0_2 = func_80031574(gCurrControllerNum);
    }
    if (var_a0_2 != 0) {
        D_8008FD24 = var_a0_2;
        if (-func_80031BB0(var_a0_2) == 1) {
            if (sp1C == 4) {
                D_8008FD22 = 0xD;
                D_8008FD29 = 0xA;
            } else {
                D_8008FD22 = 8;
                D_8008FD29 = 0xA;
            }
        } else {
            D_8008FD22 = 0x11;
            D_8008FD29 = 0xA;
        }
        
        D_8008FD20 &= ~7;
        D_8008FD20 |= 5;
        return;
    }
    if (sp1C == 4) {
        if (D_80092A38[gCurrControllerNum].unk_13 < 2) {
            if (D_80092A38[gCurrControllerNum].unk_00 & 0x4000) {
                D_8008FD22 = 0x15;
            } else {
                D_8008FD22 = 0x14;
            }
            D_8008FD29 = 0xA;
            D_8008FD20 &= ~7;
            D_8008FD20 |= 5;
            return;
        }
        if (D_80092A38[gCurrControllerNum].unk_00 & 0x2000) {
            if (D_80092A38[gCurrControllerNum].unk_00 & 0x4000) {
                D_8008FD22 = 0x15;
                D_8008FD2A = 0;
                D_8008FD20 &= ~0x20;
            } else {
                D_8008FD22 = 0x14;
            }
            D_8008FD29 = 0xA;
            D_8008FD20 &= ~7;
            D_8008FD20 |= 5;
            return;
        }
    } else if ((D_8008FD2C != 0) && ((D_80092A38[gCurrControllerNum].unk_13 < 2) || (D_80092A38[gCurrControllerNum].unk_00 & 0x2000)) ) {
        D_8008FD22 = 0x18;
        D_8008FD29 = 0xA;
        func_8002DD18();
        D_8008FD20 &= ~7;
        D_8008FD20 |= 5;
        D_8008FD2A = 0;
        D_8008FD20 &= ~0x20;
        return;
    } else if (!(D_80092A38[gCurrControllerNum].unk_00 & 0x4000)) {
        if (sp1C == 0) {
            D_8008FD22 = 9;
            D_8008FD29 = 0xA;
        } else {
            D_8008FD22 = 0xA;
            D_8008FD29 = 0xA;
        }
        D_8008FD20 &= ~7;
        D_8008FD20 |= 5;
        return;
    }
    func_8002DD18();
    D_8008FD20 &= ~7;
    D_8008FD20 = D_8008FD20;
    D_8008FD2A = 0;
    D_8008FD20 &= ~0x20;
}

#pragma GLOBAL_ASM("asm/nonmatchings/2C110/func_8002BCA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2C110/func_8002C818.s")

void func_8002D5D4(void) {
    if (--D_8008FD29 < 0) {
        D_8008FD20 &= ~7;
        D_8008FD20 = D_8008FD20;
    }
}

void func_8002D614(void) {
    s32 temp_v0;
    s32 temp_v1;

    temp_v0 = func_8003195C(gCurrControllerNum, D_8008FD30[D_8008FD2A].unk_01);
    if (temp_v0 != 0) {
        D_8008FD24 = temp_v0;
        temp_v1 = -func_80031BB0(temp_v0);
        switch (temp_v1) {
            default:
                D_8008FD22 = 0x11;
                D_8008FD29 = 0xA;
                break;
            case 1:
                D_8008FD22 = 8;
                D_8008FD29 = 0xA;
                break;
            case 4:
                D_8008FD22 = 0xC;
                D_8008FD29 = 0xA;
                break;

        }
        D_8008FD20 &= ~7;
        D_8008FD20 |= 5;
        D_8008FD20 &= ~0x2000;
        return;
    }
    D_8008FD20 &= ~7;
    D_8008FD20 |= 5;
    D_8008FD20 &= ~0x2000;
    D_8008FD22 = 0x16;
    D_8008FD29 = 0xA;
    D_8008FD30[D_8008FD2A].unk_01 = -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/2C110/func_8002D748.s")

void func_8002D8BC(void) {
    s32 temp_v0_2;
    s32 var_v1;
    s32 var_a0;
    s32 var_a2;

    if (D_8008FD30[D_8008FD2A].unk_00 == -2) {
        var_a2 = D_80092A38[gCurrControllerNum].unk_00 & 0xF;
        for (var_a0 = 0xF; var_a0 >= 0; ) {
            var_v1 = 0;
            var_a0++;
            do {
                if (var_a0 == D_8008FD30[var_v1].unk_01) {
                    var_v1 = 0x7F;
                    break;
                }
                var_v1++;
            } while (var_v1 < var_a2);
            
            if (var_v1 != 0x7F) {
                var_a2 = var_a0;
                var_a0 = -1;
            }
        }
        
        D_8008FD30[D_8008FD2A].unk_01 = var_a2;
        if (D_8008FD2A + 1 < 16) {
            D_8008FD30[D_8008FD2A + 1].unk_01 = -2;
        }
        temp_v0_2 = func_80031890(gCurrControllerNum, var_a2);
        if (temp_v0_2 >= 0) {
            D_8008FD30[D_8008FD2A].unk_00 = temp_v0_2;
        } else {
           
        }
        func_8002E234(D_8008FD2A);
    } else {
        func_8002E234(D_8008FD2A);
    }
    var_a0 = func_80031A44(gCurrControllerNum, D_8008FD30[D_8008FD2A].unk_00, 0, 0x80, (u8*)&D_8008FD58[D_8008FD2A]);
    if (var_a0 != 0) {
        D_8008FD24 = var_a0;
        var_a0 = -func_80031BB0(var_a0);
        switch (var_a0) {
            default:
                D_8008FD22 = 0x11;
                D_8008FD29 = 0xA;
                break;
            case 1:
                D_8008FD22 = 0xD;
                D_8008FD29 = 0xA;
                break;
            case 4:
                D_8008FD22 = 0xE;
                D_8008FD29 = 0xA;
                break;

        }
        D_8008FD20 &= ~(1 | 2 | 4);
        D_8008FD20 |= (1 | 4);
        D_8008FD20 &= ~0x2000;
        return;
    }
    var_a0 = func_80031A44(gCurrControllerNum, D_8008FD30[D_8008FD2A].unk_00, 0x80, 0xE0, (u8*)&D_80090398.unk_00);
    if (var_a0 != 0) {
        D_8008FD24 = var_a0;
        var_a0 = -func_80031BB0(var_a0);
        switch (var_a0) {
            default:
                D_8008FD22 = 0x11;
                D_8008FD29 = 0xA;
                break;
            case 1:
                D_8008FD22 = 0xD;
                D_8008FD29 = 0xA;
                break;
            case 4:
                D_8008FD22 = 0xE;
                D_8008FD29 = 0xA;
                break;

        }
        D_8008FD20 &= ~(1 | 2 | 4);
        D_8008FD20 |= (1 | 4);
        D_8008FD20 &= ~0x2000;
        return;
    }
    D_8008FD20 &= ~(1 | 2 | 4);
    D_8008FD20 |= (1 | 4);
    D_8008FD20 &= ~0x2000;
    D_8008FD22 = 0x17;
    D_8008FD29 = 0xA;
}

#pragma GLOBAL_ASM("asm/nonmatchings/2C110/func_8002DBE0.s")

void func_8002DD18(void) {
    Unk* temp_v0;
    s32 var_a1;
    s32 var_fp;
    s32 i;

    var_fp = 0;
    
    //17 not 16?
    for (i = 0; i < 17; i++) {
        D_8008FD30[i].unk_00 = -1;
        D_8008FD30[i].unk_01 = -1;
    }

    var_a1 = 0;
    for (i = 0; i < 16; i++) {
        if ((D_80092A38[gCurrControllerNum].unk_02[i] != 0x7F) && (D_80092A38[gCurrControllerNum].unk_02[i] >= 0)) {
            temp_v0 = &D_8008FD30[var_a1];
            temp_v0->unk_00 = i;
            temp_v0->unk_01 = D_80092A38[gCurrControllerNum].unk_02[i];
            var_a1 += 1;
        }        
    }
    
    if (D_8008FD0C & 4) {
        if ((D_80092A38[gCurrControllerNum].unk_13 >= 2) && !(D_80092A38[gCurrControllerNum].unk_00 & 0x2000)) {
            D_8008FD30[var_a1].unk_00 = -2;
        }
    }
    D_8008FD2A = 0;

    for (i = 0; i < 16; i++) {
        //if slot index is greater than or equal to 0
        if (D_8008FD30[i].unk_00 >= 0) {
            var_a1 = func_800319E0(gCurrControllerNum, D_8008FD30[i].unk_00, 0, 0x80, &D_80090460);
            D_8008FD58[i] = D_80090460;
            if (var_a1 != 0) {
                D_8008FD24 = var_fp;
                var_fp = -func_80031BB0(var_fp);
                if (var_fp == 1) {
                    D_8008FD22 = 8;
                    D_8008FD29 = 0xA;
                } else {
                    D_8008FD22 = 0x11;
                    D_8008FD29 = 0xA;
                }
                
                D_8008FD20 &= ~7;
                D_8008FD20 |= 5;
            }
        }   
    }
}

void func_8002DF6C(void) {
    gSPDisplayList(gMasterGfxPos++, D_8005FAA0);
    gDPSetTextureLUT(gMasterGfxPos++, G_TT_RGBA16);
    D_8008FD0C &= ~0x10;
}

void func_80029B58(s32, s32, s32, s32, s32);

void func_8002DFD0(void) {
    func_80029B58(0, 0x3C, 0x22, 0xC8, 0xAB);
    func_80029B58(0x37, 0x3F, 0xCE, 0xC8, 3);
    func_80029B58(0x37, 0x105, 0x28, 2, 0xA9);
    func_80029B58(0x37, 0x3B, 0x21, 0xCA, 1);
    func_80029B58(0x37, 0x3B, 0xCD, 0xCA, 1);
    func_80029B58(0x37, 0x3B, 0x21, 1, 0xAD);
    func_80029B58(0x37, 0x104, 0x21, 1, 0xAD);
    func_80029B58(0x38, 0x3D, 0x23, 0xC5, 1);
    func_80029B58(0x38, 0x3D, 0x23, 1, 0xA8);
    func_80029B58(0x39, 0x3D, 0xCB, 0xC6, 1);
    func_80029B58(0x39, 0x102, 0x23, 1, 0xA9);
    func_80029B58(0x3F, 0x5A, 0x2E, 0x96, 2);
    func_80029B58(0x3F, 0x5A, 0x44, 0x96, 2);
    func_80029B58(0x3F, 0x5A, 0x7B, 0x96, 2);
    func_80029B58(0x3F, 0x5A, 0x91, 0x96, 2);
    func_80029B58(0x42, 0x5E, 0x67, 0x7C, 0xC);
    func_80029B58(0x42, 0x5E, 0xB5, 0x7C, 0xC);
    func_80029B58(0x46, 0x55, 0x58, 0x14, 0xE);
    func_80029B58(0x47, 0xA2, 0x58, 0x18, 0xE);
    func_80029B58(0x46, 0x55, 0xA6, 0x14, 0xE);
    func_80029B58(0x47, 0xA2, 0xA6, 0x18, 0xE);
}

void func_8002E234(u32 arg0) {
    SaveData* temp_a2;
    s32 i;
    u8* ptr1;
    u8* ptr2;

    temp_a2 = &D_8008FD58[arg0];
    temp_a2->playerStats = gPlayerMainData.playerStats;
    temp_a2->unk38 = D_800859E2;
    temp_a2->curDay = gCurrentDay;
    temp_a2->nextMap = gNextMap;
    temp_a2->nextSubMap = gNextSubmap;
    temp_a2->unk44 = D_80084EF8;
    temp_a2->unk48 = D_80084EFC;
    temp_a2->unk4C = D_80084F00;
    temp_a2->unk50 = D_80084F04;
    temp_a2->unk54 = D_80084F08;
    temp_a2->unk58 = D_80084F0C;
    temp_a2->unk5C = D_8007BA60;
    temp_a2->unk5E = D_8007BA62;
    temp_a2->unk_60 = D_8007BA64;
    temp_a2->unk_62 = D_8005FA00;
    temp_a2->unk_63 = D_8005F010;
    
    ptr1 = D_80090398.unk_00;
    ptr2 = D_800869D8;
    for (i = UNK_SIZE_0; i != 0; i--) {
        *ptr1++ = *ptr2++;
    }
    
    ptr1 = D_80090398.unk_20;
    ptr2 = D_80086AE8;
    for (i = UNK_SIZE_1; i != 0; i--) {
        *ptr1++ = *ptr2++;
    }
    
    ptr1 = D_80090398.unk_30;
    ptr2 = gInventory;
    for (i = INVENTORY_SIZE; i != 0; i--) {
        *ptr1++ = *ptr2++;
    }
    
    ptr1 = D_80090398.unk_C7;
    ptr2 = D_8007D19C;
    for (i = UNK_SIZE_2; i != 0; i--) {
        *ptr1++ = *ptr2++;
    }
}

void func_8002E404(s32 arg0) {
    SaveData* temp_a2;
    s32 i;
    u8* ptr1;
    u8* ptr2;

    temp_a2 = &D_8008FD58[arg0];
    gPlayerMainData.playerStats = temp_a2->playerStats;
    D_800859E2 = temp_a2->unk38;
    gCurrentDay = temp_a2->curDay;
    gNextMap = temp_a2->nextMap;
    gNextSubmap = temp_a2->nextSubMap;
    D_80084EF8 = temp_a2->unk44;
    D_80084EFC = temp_a2->unk48;
    D_80084F00 = temp_a2->unk4C;
    D_80084F04 = temp_a2->unk50;
    D_80084F08 = temp_a2->unk54;
    D_80084F0C = temp_a2->unk58;
    D_8007BA60 = temp_a2->unk5C;
    D_8007BA62 = temp_a2->unk5E;
    D_8007BA64 = temp_a2->unk_60;
    D_8005FA00 = temp_a2->unk_62;
    D_8005F010 = temp_a2->unk_63;

    ptr1 = D_80090398.unk_00;
    ptr2 = D_800869D8;
    for (i = UNK_SIZE_0; i != 0; i--) {
        *ptr2++ = *ptr1++;
    }

    ptr1 = D_80090398.unk_20;
    ptr2 = D_80086AE8;
    for (i = UNK_SIZE_1; i != 0; i--) {
        *ptr2++ = *ptr1++;
    }

    ptr1 = D_80090398.unk_30;
    ptr2 = gInventory;
    for (i = INVENTORY_SIZE; i != 0; i--) {
        *ptr2++ = *ptr1++;
    }
    
    ptr1 = D_80090398.unk_C7;
    ptr2 = D_8007D19C;
    for (i = UNK_SIZE_2; i != 0; i--) {
        *ptr2++ = *ptr1++;
    }
}
