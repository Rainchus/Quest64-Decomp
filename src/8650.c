#include "common.h"
#include "8650.h"
#include "24E60.h"

extern u8 D_D305E0[];


#pragma GLOBAL_ASM("asm/nonmatchings/8650/func_80007A50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8650/func_80007B64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8650/func_80007F18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8650/func_800080E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8650/func_80008290.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8650/func_8000835C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8650/func_800086E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8650/func_80008948.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/8650/LoadNPCName.s")
void LoadNPCName(NPCData* NPC, s32 arg1) {
    s32 i;
    
    dmaLoadFromROM(&D_D305E0[arg1], gMessageBuffer, 1024);
    
    if (NPC->NPCData2->NPCName != NULL) {
        for (i = 0; i < 32; i++) {
            gNPCName[i] = NPC->NPCData2->NPCName[i];
        }
        return;
    }
    *gNPCName = 0xFF;
}



void func_80008AD8(s32 arg0, u8 *arg1) {
	s32 i;
	u8 *message_buffer;
	NPCData *current_npc;

	message_buffer = gMessageBuffer;

	for (i = 0x400; i != 0; i--) {
		*message_buffer++ = *arg1++;
	}

	current_npc = &gNPCData[arg0];

	if (current_npc->NPCData2->NPCName != 0) {
		for (i = 0; i != 0x20; i++) {
			gNPCName[i] = (current_npc->NPCData2->NPCName)[i];
		}
	} else {
		gNPCName[0] = 0xFF;
	}
}
