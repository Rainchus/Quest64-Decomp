#include "common.h"
#include "31F00.h"

s32 osMotorInit(OSMesgQueue* mq, OSPfs* pfs, int channel);
extern u8 D_8005FB40[];
s32 func_80031C0C(u8* str0, u8* str1, s32 size);

s32 func_80031300(void) {
    s32 var_a2;
    OSContStatus* cont;
    s32 var_t4;
    s32 i;
    
    var_t4 = 0;
    D_80092878 = 0;
    for (i = 0; i < 4; i++) {
        D_80092A38[i].unk_12[0] = -128;
    }

    for (i = 0; i < 4; i++) {
        gPad[i].button = 0;
        gPad[i].stick_x = 0;
        gPad[i].stick_y = 0;
    }

    osCreateMesgQueue(&gSIMessageQ, &D_80092AA0, 1);
    osSetEventMesg(5, &gSIMessageQ, &D_80092AA0);
    osContInit(&gSIMessageQ, &D_80092A88, &D_80092A90[0]);
    osContSetCh(4);
    gCurrControllerNum = -1;
    var_a2 = 0;
    for (i = 0; i < 4; i++) {
        if (D_80092A88 & (1 << i)) {
            cont = &D_80092A90[i];
            if (cont->errno & 4) {
                D_80092A38[i].unk_12[0] = -1;
            } else if (cont->type & 2) {
                D_80092A38[i].unk_12[0] = -2;
            } else {
                D_80092A38[i].unk_12[0] = 0;
                var_a2 += 1;
                if (gCurrControllerNum == -1) {
                    gCurrControllerNum = i;
                }
                if (cont->status & 1) {
                    D_80092A38[i].unk_00 |= 0x8000;
                } else {
                    D_80092A38[i].unk_00 = 0;
                    if (i == gCurrControllerNum) {
                        var_t4 = 1;
                    }
                }
            }
        } else {
            D_80092A38[i].unk_12[0] = -3;
        }
    }
    if (var_a2 == 0) {
        return -1;
    }
    return var_t4;
}

void func_800314C0(s32 cont) {
    OSContPad* pad;
    u16 button;

    osContSetCh(4);
    osContStartReadData(&gSIMessageQ);

    if (osRecvMesg(&gSIMessageQ, NULL, 1) != -1) {
        osContGetReadData(&gPad[0]);
    }
    pad = &gPad[cont];
    button = pad->button;
    gPadButtonPressed = button;
    gPadStickX = pad->stick_x;
    gPadStickY = pad->stick_y;
    D_80092876 = button & D_80092878;
    D_80092878 = ~button;
}

#ifdef NON_MATCHING
s32 func_80031574(s32 arg0) {
    s32 i;
    char pad[0x10];
    s32 var_s4;
    s32 var_s5;
    s32 var_s6;
    s32 temp;
    OSPfsState sp4C;
 
    
    var_s4 = 0;
    var_s6 = 0;
    D_80092A38[arg0].unk_13 = 0xFF;
    D_80092A38[arg0].unk_00 = 0;

    for (i = 0; i < 16; i++) {
        D_80092A38[arg0].unk_02[i] = -1;
    }

    var_s5 = osPfsInitPak(&gSIMessageQ, &gPFS[arg0], arg0);
    if (var_s5 != 0) {
        if (var_s5 == 0xA) {
            var_s5 = (osMotorInit(&gSIMessageQ, &gPFS[arg0], arg0) == 0) ? 1 : 10;
        }
        return var_s5;
    }
    for (i = 0; i < 16; i++) {
        var_s5 = osPfsFileState(&gPFS[arg0], i, &sp4C);
        if (var_s5 == 0) {
            if ((sp4C.game_code == 0x4E455445) && (sp4C.company_code == 0x3738)) {
                if (func_80031C0C(D_8005FB40, sp4C.game_name, 0x10) == 0) {
                    D_80092A38[arg0].unk_02[i] = sp4C.ext_name[0];
                    D_80092A38[arg0].unk_00 |= 0x4000;
                    var_s4 += 1;
                    var_s6 += 1;
                } else {
                    D_80092A38[arg0].unk_02[i] = 0x7F;
                    var_s6 += 1;
                }
            } else {
                D_80092A38[arg0].unk_02[i] = 0x7F;
                var_s6 += 1;
            }
            continue;
        }
        
        if (var_s5 == 5) {
            D_80092A38[arg0].unk_02[i] = -1;
            var_s5 = 0;
        } else {
            break;
        }
    }
    
    if (var_s5 == 0) {
        D_80092A38[arg0].unk_00 &= ~0x0F;
        D_80092A38[arg0].unk_00 |= var_s4;
        if (var_s4 >= 0x10) {
            D_80092A38[arg0].unk_00 |= 0x2000;
        }
        if (var_s6 >= 0x10) {
            D_80092A38[arg0].unk_00 |= 0x2000;
        }
        osPfsFreeBlocks(&gPFS[arg0], &i);
        D_80092A38[arg0].unk_13 = i / 256;
        if ((i / 256) < 2) {
            D_80092A38[arg0].unk_00 |= 0x2000;
        }
    }        
    
    return var_s5;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/31F00/func_80031574.s")
#endif

u8 func_80031800(s32 arg0) {
    s32 var_a0;
    s32 var_v0;
    s32 var_v1;

    var_v0 = -1; //fake, is assigned to 0 right after. var_v1 is what needs to be assigned the -1
    var_v1 = var_v0;
    do {
        var_v1 += 1;
        var_v0 = 0;
        var_a0 = 0;
        for (; var_v0 < 16; var_v0++) {
            if ((var_v1 + 0x1A) == D_80092A38[arg0].unk_02[var_v0]) {
                var_a0 = -1;
                break;
            }
        }

        if ((var_v1 >= 0x10) && (var_a0 != 0)) {
            var_a0 = -1;
            break;
        } 

    } while (var_a0 == 0);
    
    if (var_a0 == 0) {
        var_a0 = (var_v1 + 0x1A);
    }
    return var_a0;
}


// extern u8 D_8005FB40;

// u8 func_80031890(s32 arg0, u8 arg1) {
//     s32 temp_v0;
//     s32 file_no;
//     u8 ext_name[] = {0, 0, 0, 0}; //D_8005FB70
    
//     s32 var_v1;

//     file_no = -1;
//     ext_name[0] = arg1;
//     temp_v0 = osPfsAllocateFile(&gPFS[arg0], 0x3738U, 0x4E455445U, &D_8005FB40, ext_name, 0x200, &file_no);
    
//     if (temp_v0 == 0) {
//         var_v1 = file_no;
//         D_80092A38[arg0].unk_02[var_v1] = arg1;
//     } else {
//         var_v1 = -temp_v0;
//     }
//     return var_v1;
// }
#pragma GLOBAL_ASM("asm/nonmatchings/31F00/func_80031890.s")


//needs .data imported for the  `u8 sp20[] = {0, 0, 0, 0}; //D_8005FB74` line
// extern u8 D_8005FB40[];
// u8 func_8003195C(s32 arg0, u8 arg1) {
//     s32 temp;
//     u8 sp20[] = {0, 0, 0, 0}; //D_8005FB74
//     sp20[0] = arg1;
    
//     return osPfsDeleteFile(&gPFS[arg0], 0x3738, 0x4E455445, D_8005FB40, sp20);
// }
#pragma GLOBAL_ASM("asm/nonmatchings/31F00/func_8003195C.s")

void func_800319E0(s32 pfsIndex, s32 file_no, s32 offset, s32 nbytes, u8* data_buffer) {
	osPfsReadWriteFile(&gPFS[pfsIndex], file_no, PFS_READ, offset, nbytes, data_buffer);
}

s32 func_80031A44(s32 pfsFileNum, s32 arg1, s32 arg2, s32 arg3, u8* arg4) {
    s32 ret;
    s32 pfsBytesNotUsed;

    ret = osPfsFreeBlocks(&gPFS[pfsFileNum], &pfsBytesNotUsed);
    if (ret != 0) {
        return ret;
    }
    return osPfsReadWriteFile(&gPFS[pfsFileNum], arg1, 1, arg2, arg3, arg4);
}

/*initializes devices such as the rumble pak and the controller pak and returns an error ID if there is one.*/
s32 initPFSPaks(s32 arg0, s32 arg1) {
	s32 con_error;
	u32 cont;

	cont = gCurrControllerNum;

	if (arg1 == 0xA) {
		if (osMotorInit(&gSIMessageQ, &gPFS[cont], cont) != 0) {
			con_error = osPfsInitPak(&gSIMessageQ, &gPFS[cont], cont);
			if ((con_error != PFS_ERR_DEVICE) && (con_error != PFS_ERR_NOPACK) && (con_error != PFS_ERR_NEW_PACK)) {
				con_error = __osGetID(&gPFS[cont]);
			}
		} else {
			con_error = 4;
		}
	} else {
		con_error = osPfsInitPak(&gSIMessageQ, &gPFS[cont], cont);
	}

	return con_error;
}

s32 func_80031BB0(s32 arg0) {
    s32 var_v1;

    switch (arg0) {
    case PFS_ERR_NOPACK:
        var_v1 = -1;
        break;
    case PFS_ERR_CONTRFAIL:
    case PFS_ERR_DEVICE:
        var_v1 = -2;
        break;
    case PFS_ERR_INCONSISTENT:
    case PFS_ERR_ID_FATAL:
        var_v1 = -3;
        break;
    case PFS_ERR_NEW_PACK:
        var_v1 = -4;
        break;
    case PFS_ERR_EXIST:
        var_v1 = -5;
        break;
    default:
        var_v1 = -6;
        break;
    }
    return var_v1;
}


s32 func_80031C0C(u8* str0, u8* str1, s32 size) {
    do {
        if (*str0++ != *str1++) {
            break;
        }
    } while(size--);

    return size;
}
