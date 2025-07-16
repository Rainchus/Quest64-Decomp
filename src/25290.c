#include "common.h"

extern s32 D_800539A4;
extern s32 D_800539B8;
extern OSThread D_8008D090; //Almost certainly OSThread type. 
extern ALHeap D_8008F240;
extern OSMesgQueue D_8008F288;
extern ALSndPlayer D_8008F620;
extern s16* D_8008F68C;
extern s32 D_8008F92C;
extern s32 D_800539E4;

extern void* func_80024BEC;

//loads an overlay
void func_80024690(s32 devAddr, void* vAddr, s32 nbytes) {
    OSIoMesg sp28;

    osInvalDCache(vAddr, nbytes);
    osPiStartDma(&sp28, 0, 0, devAddr, vAddr, nbytes, &D_8008F288);
    osRecvMesg(&D_8008F288, NULL, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80024704.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_800248C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80024A48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80024B1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80024BEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80025040.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_800250E8.s")
void func_800250E8(void* arg0) {
    osCreateThread(&D_8008D090, 5, &func_80024BEC, arg0, &D_8008F240, 0x32);
    osStartThread(&D_8008D090);
}

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_8002513C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_800252D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80025364.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_800253F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_8002543C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80025488.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80025634.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_8002568C.s")
void func_8002568C(s32 arg0) {
    alSndpSetSound(&D_8008F620, D_8008F68C[arg0]);
    alSndpStop(&D_8008F620);
}

//#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_800256D4.s")
void func_800256D4(s32 arg0) {
    alSndpSetSound(&D_8008F620, D_8008F68C[arg0]);
    alSndpGetState(&D_8008F620);
}

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_8002571C.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_800258F8.s")
void func_800258F8(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 0x47)) {
        D_8008F92C = (&D_800539E4)[arg0];
        return;
    }
    D_8008F92C = D_800539E4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80025938.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80025984.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80025B3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80025B8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80025BD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80025E0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80026214.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_800262F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_800263A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80026434.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80026488.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_8002650C.s")
void func_8002650C(void) {
    if (D_800539A4 != 0xFF) {
        func_8002568C(D_800539A4);
    }
    D_800539B8 = 0;
    D_800539A4 = 0xFF;
}

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80026554.s")
