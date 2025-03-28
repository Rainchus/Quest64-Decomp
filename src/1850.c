#include "common.h"
#include "1850.h"
#include "map_ids.h"
#include "33D0.h"
#include "31F00.h"

//TODO: declare these by using a header
#define OS_SC_SWAPBUFFER        0x0040	/* swapbuffers when gfx task done */
/* standard boot ucode: */
extern long long int	rspbootTextStart[], rspbootTextEnd[];
/* standard 3D ucode: */
extern long long int	gspFast3DTextStart[], gspFast3DTextEnd[];
extern long long int	gspFast3DDataStart[], gspFast3DDataEnd[];

#define MODE_GAMEPLAY 1
#define MODE_PAUSED   2
#define MODE_TITLE    3
#define MODE_SPLASH   4
#define MODE_CREDITS  5

void func_80021170(void);
void func_80030E58(void);
void func_800265F0(void);
void func_800314C0(s32 cont);

void func_80000C50(s32 arg0) {
    osCreateViManager(0xFE);
    osCreateMesgQueue(&D_8007B320, &D_8007B338, 1);
    func_80024704();
    func_8002513C(instrument_ctl_ROM_START, instrument_ctl_ROM_END, unk_tbl_ROM_START, unk_tbl_ROM_END, instrument_tbl_ROM_START);
    func_80025488(SE_ctl_ROM_START, SE_ctl_ROM_END, SE_tbl_ROM_START);
    nnScCreateScheduler(&D_8007B358, 1);
    func_80031300();
    if (osTvType == OS_TV_NTSC) {
        osViSetMode(&D_8006F4F0);
    } else {
        osViSetMode(&D_8006FDB0);
    }
    osViBlack(1);
    func_80032704(&gSIMessageQ, &D_8007B3CC);
    osViBlack(1);
    osViSetSpecialFeatures(0x5A);
    nnScStartScheduler(&D_8007B358);
    func_800250E8(&D_8007B358);
    osCreateMesgQueue(&D_8007B9E8, &D_8007BA00, 8);
    nnScAddClient(&D_8007B358, &D_8007B9E0, &D_8007B9E8);
    D_8007B9D8 = nnScGetGfxMQ(&D_8007B358);
    func_80000FE8();

    while (1) {
        func_8000B520();
        func_80011B40();
        func_800121F0();
        func_800027D0();
        func_80021170();
        func_800100D0();
        func_80030E58();
        func_800265F0();
        func_80000EEC();
        func_80026A40();
    loop_5:
        gGameState &= ~3;
        if (gGameMode == 0) {
            gGameMode = MODE_GAMEPLAY;
        }
        switch (gGameMode) {
        case MODE_GAMEPLAY:
            func_80001800();
            break;
        case MODE_PAUSED:
            func_800020B4();
            break;
        case MODE_TITLE:
            func_8000227C();
            break;
        case MODE_SPLASH:
            func_80002428();
            break;
        case MODE_CREDITS:
            func_800025E8();
            break;
        }
        if (!(gGameState & 0x8000)) {
            goto loop_5;
        }
    }
}

void func_80000EEC(void) {
    gGameState = 0x160;
    gGameMode = 4;
    gNextMap = -1;
    D_80084EF8 = -1;
    D_80084F04 = -1;
    D_80084F14 = 0xFFFF;
    D_80086E44 = 0.0f;
    D_800859E2 = 0;
    gCurrentMap = (u32)MAP_MONASTERY;
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

extern u8 D_80300000[]; //stack?
extern u8 gThreadOutStack[0x8000]; //FIFO buffer start
extern u8 D_80300400[];
 
void func_8000111C(unk111Cs* arg0) {
    arg0->task.list.t.type = M_GFXTASK;
    arg0->task.list.t.flags = 0;
    arg0->task.list.t.ucode_boot = (u64*)rspbootTextStart; // ucode boot at 0x80049EF0
    arg0->task.list.t.ucode_boot_size = (uintptr_t)rspbootTextEnd - (uintptr_t)rspbootTextStart;
    arg0->task.list.t.ucode = (u64*)gspFast3DTextStart; // ucode .text section at 0x80049FC0
    arg0->task.list.t.ucode_data = (u64*)gspFast3DDataStart; // ucode .data section at 0x800723D0
    arg0->task.list.t.ucode_data_size = SP_UCODE_DATA_SIZE;
    arg0->task.list.t.dram_stack = (u64*)D_80300000; // Stack at 0x80300000
    arg0->task.list.t.dram_stack_size = SP_DRAM_STACK_SIZE8;
    arg0->task.list.t.output_buff = (u64*)gThreadOutStack;      // Output FIFO buffer starts at 0x8031B2A0
    arg0->task.list.t.output_buff_size = (u64*)(gThreadOutStack + sizeof(gThreadOutStack)); //gThreadOutStackEnd; // Output FIFO buffer ends   at 0x803232A0
    arg0->task.list.t.yield_data_ptr = (u64*)D_80300400;
    arg0->task.list.t.yield_data_size = OS_YIELD_DATA_SIZE;
    arg0->task.next = NULL;
    arg0->task.flags = OS_SC_SWAPBUFFER;
    arg0->task.msgQ = &D_8007B9E8;
    arg0->task.msg = &arg0->unkD148;
    arg0->task.framebuffer = arg0->unkD14C;
}

extern s32 D_8004C210;
extern s8 D_8006AC60;
extern s32 D_8007B300;
extern s32 D_8007B304;
extern u32 D_8007B308;
extern s32 D_8007B340;
extern s32 D_8007B34C;
extern void* D_8007B350;
extern s32 D_8007BC08;
extern u16 D_80084F12;

struct Struct_800011DC_arg0_sub {
    /* 0x0058 */ Mtx unk_58[1];
    /* 0x0098 */ char unk_98[0x8148 - 0x98];
    /* 0x8148 */ Gfx unk_8148[1];
    /* 0x8150 */ char unk_814C[0xD14C - 0x8150];
    /* 0xD14C */ u16* unk_D14C;
};

struct Struct_800011DC_arg0 {
    /* 0x0000 */ char unk_00[0x40];
    /* 0x0040 */ Gfx* unk_40;
    /* 0x0044 */ s32 unk_44;
    /* 0x0048 */ char unk_48[0x10];
    /* 0x0058 */ struct Struct_800011DC_arg0_sub unk_58;
};

extern u8 D_1000010[];
extern u8 D_2000000[];
extern void* DepthBuffer;
void func_80012BE0(Mtx *arg0);
void func_80018638(Mtx* arg0);
void func_8001B19C(Mtx* arg0);
void func_8001E25C(Mtx* arg0);
void func_80021524(void);
void func_800228F8(Mtx* arg0);
void func_80026A7C(Mtx* arg0);
void func_8002B510(s32 arg0);
void func_8002EAA0(void);
void func_80003870(Mtx* arg0);
void func_80007F18(Mtx* arg0);
void func_80008CF4(Mtx* arg0);
void func_8000B618(Mtx* arg0);
void func_8000C4C4(Mtx* arg0);
void func_8000CE8C(Mtx* arg0);
void func_8000D9BC(Mtx* arg0);
void func_80010B58(void);
void func_800111F8(s32 arg0);
void func_800118D4(Mtx*); //has a different struct in a matched function. I'm scared... 
void func_80011D28(Mtx* arg0);
void func_8001249C(void);
s32 func_8010004C_DA693C_ovl_title(void);
s32 func_8010009C_DC16BC_ovl_intro(void);
s32 func_8010008C_E278CC_ovl_ending(void);

void func_800011DC(struct Struct_800011DC_arg0* arg0) {
    struct Struct_800011DC_arg0_sub* sub = &arg0->unk_58;
    s32 temp_t8;
    s32 one = 1;

    gMasterGfxPos = arg0->unk_58.unk_8148;
    
    gSPSegment(gMasterGfxPos++, 0x00, 0x00000000);
    gSPSegment(gMasterGfxPos++, 0x01, osVirtualToPhysical(D_8007B350));
    gSPSegment(gMasterGfxPos++, 0x02, osVirtualToPhysical(&arg0->unk_58));
    gSPDisplayList(gMasterGfxPos++, D_1000010);
    gDPSetDepthImage(gMasterGfxPos++, osVirtualToPhysical(&DepthBuffer));
    gDPPipeSync(gMasterGfxPos++);
    gDPSetCycleType(gMasterGfxPos++, G_CYC_FILL);
    gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(&DepthBuffer));
    gDPSetFillColor(gMasterGfxPos++, 0xFFFCFFFC);
    gDPFillRectangle(gMasterGfxPos++, 8, 8, 311, 231);
    gDPPipeSync(gMasterGfxPos++);
    gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(arg0->unk_58.unk_D14C));
    
    if (gGameMode == 1) {
        gDPSetFillColor(gMasterGfxPos++, (GPACK_RGBA5551(D_8007B300, D_8007B304, D_8007B308, 1) << 16) | (GPACK_RGBA5551(D_8007B300, D_8007B304, D_8007B308, 1)));        
        gDPFillRectangle(gMasterGfxPos++, 8, 8, 311, 231);
    } else {
        gDPSetFillColor(gMasterGfxPos++, (GPACK_RGBA5551(0, 0, 0, 1) << 16) | (GPACK_RGBA5551(0, 0, 0, 1)));
        gDPFillRectangle(gMasterGfxPos++, 8, 8, 311, 231);
    }
    gDPPipeSync(gMasterGfxPos++);
    gDPSetCycleType(gMasterGfxPos++, G_CYC_2CYCLE);
    
    if (gGameMode == 1) {
        func_80012BE0(sub->unk_58);
        func_80010B58();
        if (D_80084F12 & 4) {
            func_800111F8(D_8007B340);
            func_8000D9BC(sub->unk_58);
        }
        func_800111F8(D_8007B340);
        func_8000C4C4(sub->unk_58);
        func_80003870(sub->unk_58);
        func_80007F18(sub->unk_58);
        func_80011D28(sub->unk_58);
        func_8000CE8C(sub->unk_58);
        func_80008CF4(sub->unk_58);
        func_8000B618(sub->unk_58);
        func_8001249C();
        func_800111F8(D_8007BC08);
        func_800118D4(sub->unk_58);
        func_8001B19C(sub->unk_58);
        func_80018638(sub->unk_58);
        func_800228F8(sub->unk_58);
        if (gGameState & 2) {
            func_8002EAA0();
        } else if (!(gGameState & 0x4000) && ((u16) D_8007B2E8 != 4)) {
            func_8001E25C(sub->unk_58);
        }
        if (gGameState & 1) {
            func_80021524();
        }
    } else if (gGameMode == 2) {
        func_80026A7C(sub->unk_58);
    } else if (gGameMode == 3) {
        switch (func_8010004C_DA693C_ovl_title()) {
            case 0:
                switch (D_8007B344 & 0xF0) {
                    case 0x10:
                        gGameMode = 1;
                        break;
                    case 0x20:
                        func_8002B510(0);
                        break;
                    case 0x30:
                        func_8002B510(8);
                        break;
                    default:
                        gGameMode = 1;
                        break;
                }
                break;
            case 1:
                gGameMode = 4;
                break;
        }
    } else if (gGameMode == 4) {
        switch (func_8010009C_DC16BC_ovl_intro()) {
            case 0:
                D_8006AC60 = 0;
                gGameMode = 3;
                break;
            case 1:
                D_8006AC60 = one;
                gGameMode = 3;
                break;
            default:
                D_8006AC60 = 0;
                // break; // no break here!
        }
    } else if (gGameMode == 5) {
        if (func_8010008C_E278CC_ovl_ending() == 0) {
            gGameMode = 3;
        }
    }
    gDPFullSync(gMasterGfxPos++);
    gSPEndDisplayList(gMasterGfxPos++);
    osWritebackDCache(D_2000000, 0xD0F0);
    
    temp_t8 = gMasterGfxPos - arg0->unk_58.unk_8148;
    if (D_8007B34C < temp_t8) {
        D_8007B34C = temp_t8;
    }
    D_8004C210 = temp_t8;
    
    arg0->unk_40 = sub->unk_8148;
    arg0->unk_44 = (gMasterGfxPos - sub->unk_8148) * sizeof(Gfx);
    
}

#pragma GLOBAL_ASM("asm/nonmatchings/1850/func_80001800.s")

void func_800020B4(void) {
    OSMesg sp4C;
    OSMesg* temp_s5;

    D_8007B348 = 0;
    sp4C = NULL;
    D_8008FD0E = 0;

    while (gGameMode == 2) {
        func_800314C0(gCurrControllerNum);
        D_8007B2F8 = 0;
        func_800011DC((void*)D_80301000[D_8007B2F4]);
        temp_s5 = (OSMesg*)D_80301000[D_8007B2F4];
        func_80026658();
        if (D_8007B348 == 0) {
            D_8007B348++;
            do {
                osRecvMesg(&D_8007B9E8, &sp4C, 1);
            } while (*(s16*)sp4C != 1);
        } else {
            do {
                osRecvMesg(&D_8007B9E8, &sp4C, 1);
            } while (*(s16*)sp4C != 2);
        }
        osSendMesg(D_8007B9D8, temp_s5, 1);
        D_8007B2F4 ^= 1;
    }

    if (D_8008FD0E != 0) {
        func_80002EA0();
        D_8007B2E8 = 2;
    }

    func_80026A04();
    
    do {
        osRecvMesg(&D_8007B9E8, &sp4C, 1);
    } while (*(s16*)sp4C != 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/1850/func_8000227C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1850/func_80002428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1850/func_800025E8.s")
