#include "common.h"
#include "animation.h"
#include "33D0.h"
#include "1D160.h"
#include "24E60.h"
#include "191F0.h"

#define ARRAY_COUNT(a) (sizeof(a) / sizeof(a[0]))

//put this stuff in a header somewhere. Why doesn't it already exist? 
#define qs510(n)		((qs510_t)((n) * 0x0400))

#define ITEM_USABLE 1
#define ITEM_NOT_USABLE 0


typedef struct ItemData_s{
    u16 canBeUsed;
    u16 type;
    s16 itemArg1;
    s16 itemArg2;
    u16 unk8;
    u16 unkA;
}ItemData;


typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s16 unkC;
    char unkE[2];
    s32 unk10;
    f32 unk14;
}unk80085368s;

typedef struct {
    f32 width;
    f32 height;
    f32 unk8;
}ItemLightRingData;

typedef struct {
    u16 mapID;
    u16 submapID;
    f32 xpos;
    f32 zpos;
    f32 yrot;
}unk803a9190s;

typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    char unk8[2];
}unk2234c3;

typedef struct {
    s16 unk0;
    u16 unk2;
    u16 healItemLightColor;
    char unk6[2];
    f32 healItemLightWidth;
    f32 healItemLightHeight;
    s16 unk10;
    u16 unk12;
    u16 wingLightColor;
    char unk16[2];
    f32 wingLightWidth;
    f32 wingLightHeight;
}BaseItemLightRingData;

typedef struct {
    char unk0[0x14];
    u16 unk14;
}unk_80084F1C;

extern u16 D_80084EE0;
extern unk_80084F1C* D_80084F1C;

void UseWings(TransformAnim* arg0, ItemData* arg1);
s32 func_800177F8(u16 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, void* arg6, void* arg7, TransformAnim* arg8);
void func_800268D4(u8 arg0, s8 arg1, u8 arg2);


extern ItemLightRingData D_8008D010;
extern unk803a9190s D_803A9190; //wing data
extern unk2234c3 D_803A9A54[];
extern BaseItemLightRingData D_803A9A68;

extern s32 D_8007B2EC;
extern s16 D_8007B2F0;
extern f32 D_8007BA40;
extern f32 D_8007BA44;
extern f32 D_8007BA48;
extern s32 D_8007BA4C;
extern s32 gGameState;
extern u16 D_800859E2;



extern u8 gInventory[150];

extern u8 D_D3BE40[]; //inv palettes
extern void* gPal_Ci8_items_color; //virt inventory palette
extern u8 D_8008C770[8]; //IDs of items visible in inventory. One per item no matter how many of it you have.  
extern s32 gInventoryScrollOffset; //inventory scroll index
extern s32 gHighlightedInventorySlot; //visible inv offset from start
extern s32 D_8008C768;
extern u8 D_803A8FF8[]; //DL

extern ItemData gItemDataTable[25];
extern void (*gUseItemFuncs[])(TransformAnim*, ItemData*);
extern s32 (*gCheckItemUsableFuncs[])(TransformAnim*, ItemData*);

//from 15440.c Some arg types may be wrong, but this matches for now. 
void func_80014A98(TransformAnim* arg0, u32 arg1, s32 arg2, u16 arg3);

void func_8000669C(u8);


//#pragma GLOBAL_ASM("asm/nonmatchings/inventory/InventoryInit.s")
void InventoryInit(void) {
    s32 i;
    u8 *temp;

    dmaLoadFromROM(&D_D3BE40, &gPal_Ci8_items_color, 0x400); //load inventory palette into RAM
    i = 8;
    temp = D_8008C770;
    do {
        i--;
        *temp++ = 0xFF;
    } while(i != 0);

    temp = gInventory;
    i = 151;
    while(i != 0) {
         i--;
        *temp++ = 0xFF;
    }

    gInventoryScrollOffset = 0;
    gHighlightedInventorySlot = 0;
    D_8008C768 = 0;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/inventory/CheckIfInventoryFull.s")
s32 CheckIfInventoryFull(void) {
    s32 var_v1;

    if (gInventory[149] != 0xFF) {
        var_v1 = 0;
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

/*
* function: CheckForItemInInventory
* Look up function to check if a item is in the inventory array 
* @param itemID token to check if it is in the array
* @return true if the item is found otherwise false
*/ 

s32 CheckForItemInInventory(u8 itemID) {
    s32 item_exists = FALSE;
    int index;
    int max = 74;
 
    for (index = 75; index != -75 && !item_exists; index--) {
        if (itemID == gInventory[index+max]) {
            item_exists += TRUE;
        }
    }
    
    return item_exists;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/inventory/AddItemToInventory.s")
void AddItemToInventory(u8 arg0) {
    s32 i = 0;

    do {
        if(gInventory[i] == 0xFF)
            break;
        i++;
    } while(i < ARRAY_COUNT(gInventory));

    gInventory[i] = arg0;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/inventory/func_800212E4.s")
s32 func_800212E4(u8 itemID) {
    s32 ret;
    ItemData* item;
    s32 in_battle;
    s32 itemUsable;

    ret = 0;
    in_battle = gBattleState & 1;
    if ((in_battle != 0) && (gItemDataTable[itemID].canBeUsed & 2)) {
        ret = 1; 
    }
    else if ((in_battle == 0) && (gItemDataTable[itemID].canBeUsed & 1)) {
        ret = 1;
    }

    item = &gItemDataTable[itemID];
    itemUsable = ret;
    if (itemUsable != 0) {
        
        ret = gCheckItemUsableFuncs[item->type](&gPlayerPosData, item);
    }
    if (ret != 0) {
        func_8000669C(itemID);
    }
    return ret;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/inventory/func_800213D8.s")
void func_800213D8(u8 arg0, TransformAnim* arg1) {
    ItemData* temp_a1;

    temp_a1 = &gItemDataTable[arg0];
    gUseItemFuncs[temp_a1->type](arg1, temp_a1);
}

//#pragma GLOBAL_ASM("asm/nonmatchings/inventory/func_80021434.s")
s32 func_80021434(u16 itemArg) {
    ItemData* item;
    s32 slots_left;
    s32 var_v1;
    u8* inv_slot;
    
    var_v1 = 0;
    inv_slot = gInventory;
    slots_left = 0x96;

    while (!var_v1 && *inv_slot != 0xFF) {
        item = &gItemDataTable[*inv_slot];
        inv_slot++;
        
        if (item->type == 0xF) {
            var_v1 = itemArg == item->itemArg1;
        }
        
        slots_left--;
    }
    
    if (var_v1 != 0) {
        inv_slot--;
        while (slots_left != 0) {
            slots_left--;
            inv_slot[0] = inv_slot[1];
            inv_slot++;
        }
        *inv_slot = 0xFF;
    }
    return var_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/inventory/func_80021524.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/inventory/NoEffectItem.s")
s32 NoEffectItem(TransformAnim* pos, ItemData* item) {
    return 0;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/inventory/CheckIfHealingNeeded.s")
s32 CheckIfHealingNeeded(TransformAnim* arg0, ItemData* arg1) {
    s32 var_v1;
    PlayerMainData* player;

    var_v1 = 0;
    player = arg0->unk64;
    if ((arg1->itemArg1 != 0) && (player->playerStats.maxHP != player->playerStats.currHP)) {
        var_v1 = 1;
    }
    if ((arg1->itemArg2 != 0) && (player->playerStats.maxMP != player->playerStats.currMP)) {
        var_v1 = 1;
    }
    return var_v1;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/inventory/CheckIfTeleportPossible.s")
s32 CheckIfTeleportPossible(s32 arg0, s32 arg1) {
    s32 ret;

    if (((D_80084EE0 & 0xA) != 0) || (((D_80084F1C->unk14 & 4) != 0))) {
        ret = 0;
    } else {
        ret = 1;
    }
    return ret;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/inventory/CheckIfSpellItemUsable.s")
s32 CheckIfSpellItemUsable(s32 arg0, u16* arg1) {
    s32 var_v1;

    var_v1 = 1;
    if ((gBattleState & 0x100) && (*arg1 & 8)) {
        var_v1 = 0;
    }
    return var_v1;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/inventory/func_8002233C.s")
void func_8002233C(s32 arg0, s32 arg1) {

}

//#pragma GLOBAL_ASM("asm/nonmatchings/inventory/UseHealingItem.s")
void UseHealingItem(TransformAnim* arg0, ItemData* item) {
    u16 delta;
    PlayerMainData* player = (PlayerMainData*) arg0->unk64;
    unk2234c3* temp;


    if (item->itemArg1 != 0) {
        delta = (player->playerStats.maxHP - player->playerStats.currHP);
        if (item->itemArg1 < delta) {
            delta = item->itemArg1;
        }
        player->playerStats.currHP += delta;
        func_80018DF4(arg0, 1, delta);
    }
    if (item->itemArg2 != 0) {
        delta = (player->playerStats.maxMP - player->playerStats.currMP);
        if (item->itemArg2 < delta) {
            delta = item->itemArg2;
        }
        player->playerStats.currMP += delta;
        func_80018DF4(arg0, 2, delta);
    }
    D_8008D010.width = D_803A9A68.healItemLightWidth;
    D_8008D010.height = D_803A9A68.healItemLightHeight;
    D_8008D010.unk8 = 1.0f;
    temp = &D_803A9A54[D_803A9A68.unk0];
    func_800177F8(D_803A9A68.unk2, D_803A9A68.healItemLightColor, arg0->posrot.pos.x, arg0->posrot.pos.y, arg0->posrot.pos.z, 0.0f, temp, &D_8008D010, arg0);
    func_800268D4(0U, 0xB, 0xFFU);
}

//#pragma GLOBAL_ASM("asm/nonmatchings/inventory/UseWings.s")
void UseWings(TransformAnim* arg0, ItemData* arg1) {
    unk2234c3* temp;
    
    gGameState |= 0x80;
    D_8007B2EC = 0x16;
    D_80085368.unk0 = (s32) (&D_803A9190)[arg1->itemArg1].mapID;
    D_80085368.unk4 = (s32) (&D_803A9190)[arg1->itemArg1].submapID;
    D_80085368.unk8 = -1;
    D_8007BA40 = (&D_803A9190)[arg1->itemArg1].xpos;
    D_8007BA44 = (&D_803A9190)[arg1->itemArg1].zpos;
    D_8007BA48 = (&D_803A9190)[arg1->itemArg1].yrot;
    D_8007BA4C = 0x108;
    gPlayerMainData.playerAnim.mapEntryAnimation = 0;
    D_8007B2F0 = 1;
    temp = &D_803A9A54[D_803A9A68.unk10];
    D_8008D010.width = D_803A9A68.wingLightWidth;
    D_8008D010.height = D_803A9A68.wingLightHeight;
    D_8008D010.unk8 = 1.0f;
    func_800177F8(D_803A9A68.unk12, D_803A9A68.wingLightColor, arg0->posrot.pos.x, arg0->posrot.pos.y, arg0->posrot.pos.z, 0.0f, temp, &D_8008D010, arg0);
    func_800268D4(0U, 0x3B, 0xFFU);
}

//#pragma GLOBAL_ASM("asm/nonmatchings/inventory/UseSpellItem.s")
void UseSpellItem(TransformAnim* arg0, ItemData* item) {
    func_80014A98(arg0, (u32) item->itemArg1, 0, 4U);
}

//#pragma GLOBAL_ASM("asm/nonmatchings/inventory/DrawItemBox.s")
void DrawItemBox(s32 ulx, s32 uly, s32 width, s32 height) {

    gDPPipeSync(gMasterGfxPos++);
    gDPSetCycleType(gMasterGfxPos++, G_CYC_FILL);  
    gDPSetRenderMode(gMasterGfxPos++, G_RM_NOOP, G_RM_NOOP2);    
    gDPSetFillColor(gMasterGfxPos++, 0x00010001);    
    gDPFillRectangle(gMasterGfxPos++,  ulx, uly, (ulx + width), uly);
    gDPFillRectangle(gMasterGfxPos++, ulx, (uly + height), (ulx + width) , (uly + height));
    gDPFillRectangle(gMasterGfxPos++, ulx , uly, ulx, (uly + height) );
    gDPFillRectangle(gMasterGfxPos++, ulx + width, uly, (ulx + width), uly + height );
    gDPFillRectangle(gMasterGfxPos++ , ((ulx + 3)), ((uly + height) + 1), ((ulx + width) + 2) , ((uly + height) + 2));
    gDPFillRectangle(gMasterGfxPos++, ((ulx + width) + 1), (uly + 3) , ((ulx + width) + 2), ((uly + height) + 1));
    gSPDisplayList(gMasterGfxPos++, D_803A8FF8);
    gSPTextureRectangle(gMasterGfxPos++, ((ulx + 1) <<2) ,((uly+1)<<2), ((ulx + width) * 4), ((uly + height) * 4) , G_TX_RENDERTILE, 0, 0, qs510(1), qs510(1));

}