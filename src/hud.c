#include "common.h"
#include "animation.h"
#include "33D0.h"
#include "8650.h"
#include "monsters.h"

#define FIRE 0
#define EARTH 1
#define WATER 2
#define WIND 3
#define ELEMENT_MAX 50

typedef struct {
    void* unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
}unk20e2cs;

typedef struct {
    char unk0[0x24];
    u8 unk24[1]; // some size
}unk1ebdcs;

typedef struct {
    f32 unk0;    
    f32 unk4;
    f32 unk8;
}struct_8008C668_2;

typedef struct {
    u16 unk0;
    char unk2[2];
    struct_8008C668_2* unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    u16 unk14;
    u16 unk16;
    u16 unk18;
    u16 unk1A;
}struct_8008C668;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u16 unk6;
    u16 unk8;
    s16 unkA;
    u16 unkC;
    u16 unkE;
    char unk10[0x16];
    u16 unk26;
    u16 unk28;
    u16 unk2A;
}unk203d0s2;

typedef struct {
    char unk0[0x20];
    unk203d0s2* unk20;
    char unk24[0x6C];
    u16 unk90;    
}unk203d0s;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
}struct_8008C748;

typedef struct {
    char unk0[10];
}struct_803A8DD8;

typedef struct STRUCT_803A8E0C {
    s16 unk0;
    s16 unk2;
    u16 unk4;
    float unk8;
    float unkC;
} STRUCT_803A8E0C;

extern STRUCT_803A8E0C D_803A8E0C[];

extern u16 D_8004D2CC[];
extern u16 D_8004D2DC[];
extern struct_8008C748 D_8008C748;
extern struct_803A8DD8 D_803A8DD8[];

extern s32 *D_8007D0AC;
extern s32 D_8008C648;
extern s32 D_8008C64C;
extern u8 gPal_Ci8_HUD[];
extern u8 gPal_Ci8_HUD_magic[];
extern unk20e2cs D_803A6F40;
extern unk20e2cs gHUD_magic_texture_attributes;
extern unk203d0s* D_8007D088;

extern struct_8008C668 D_8008C668[8];

extern u8 gHUD_status_symbols_attributes[];
extern u8 gPal_Ci8_status_symbols[];

extern s32 D_8007BA74;
extern s32 D_8008C644;
extern u8 gDL_Speech_bubble[];
extern u8 D_8007BAA4;
extern u8 D_8007BAA5;
extern u8 D_8007BAA6;
extern u8 D_8007BAA7;
extern u16 D_80092876;
extern s32 gGameState;
extern unk20e2cs gHUD_magic_texture_attributes;
extern u8 gPal_Ci8_HUD[];
extern u8 gPal_Ci8_HUD_magic[];
extern s16 D_8008C630;
extern s32 D_8008C638;
extern s32 D_8008C63C;
extern s32 D_8008C640;
extern s32 D_8008C648;
extern s32 D_8008C64C;
extern s32 D_8008C650;
extern s32 D_8008C654;
extern s32 D_8008C658; //number of pixels wide to display of the HUD left to right.
extern s32 D_8008C65C; //number of pixels high to display the HUD top to bottom
extern unk20e2cs D_803A6F40;

s32 func_800177F8(u16 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, void* arg6, void* arg7, TransformAnim* arg8);

s32 count_digits(s32 arg0, u8* arg1, u16 arg2);
s32 func_8002413C(f32 arg0, f32 arg1, f32 arg2, s32* arg3, s32* arg4);
void func_80020F8C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
void func_8001EBDC(unk1ebdcs* arg0);
void func_80020D4C(u16 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80020E2C(unk20e2cs* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_800210FC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8);


//#pragma GLOBAL_ASM("asm/nonmatchings/hud/func_8001E1F0.s")
void func_8001E1F0(void)
{
  D_8008C638 = 0;
  D_8008C63C = 0;
  D_8008C640 = -1;
  D_8008C648 = D_8008C64C = 0;
  D_8008C650 = D_8008C654 = 0;  
  D_8008C658 = 0x140;
  D_8008C65C = 0xF0;
  D_8008C630 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/hud/func_8001E25C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hud/func_8001E7FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hud/func_8001EA84.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/hud/func_8001EBDC.s")
void func_8001EBDC(unk1ebdcs* arg0) {
    s32 var_s0;
    s32 i;
    unk1ebdcs* var_s2;

    var_s2 = &D_803A6F40;
    func_800210FC(var_s2, 0, 0, 0xC, 0xC, 0x20, 0x10, 0x400, 0x400);
    func_800210FC(var_s2, 0x16, 0, 0xC, 0xC, 0x2C, 0x10, 0x400, 0x400);
    func_800210FC(var_s2, 0x2C, 0, 0xC, 0xC, 0x38, 0x10, 0x400, 0x400);
    func_800210FC(var_s2, 0x42, 0, 0xC, 0xC, 0x44, 0x10, 0x400, 0x400);
    func_80020E2C(var_s2, 0x20, 0x1D, 0x80, 0xA);
    var_s0 = 6;
    for (i = 0; i < 4; i++) {
        func_80020D4C(1U, var_s0, 6, arg0->unk24[i]);
        var_s0 += 0x16;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/hud/func_8001ED5C.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/hud/func_8001F3DC.s")
void func_8001F3DC(PlayerAnimData* arg0) {
    unk20e2cs* temp; 
    
    D_8008C648 = 0;
    D_8008C64C = 0;
    
    gDPPipeSync(gMasterGfxPos++);
    gDPSetTextureImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, gPal_Ci8_HUD_magic);
    gDPTileSync(gMasterGfxPos++);
    gDPSetTile(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0100, G_TX_LOADTILE, 0, G_TX_NOMIRROR |
        G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync(gMasterGfxPos++);
    gDPLoadTLUTCmd(gMasterGfxPos++, G_TX_LOADTILE, 255);
    gDPPipeSync(gMasterGfxPos++);

    temp = &gHUD_magic_texture_attributes;
    func_800210FC(temp, 0x81, 0x48, 0x40, 0x14, 0, 0, 0x400, 0x400);
    func_800210FC(temp, 0x81, 0x5C, 0x40, 0x14, 0, 0x14, 0x400, 0x400);
    func_800210FC(temp, 0x81, 0x70, 0x40, 0x14, 0, 0x28, 0x400, 0x400);
    func_800210FC(temp, 0x81, 0x84, 0x40, 0x14, 0, 0x3C, 0x400, 0x400);
    func_80020E2C(&D_803A6F40, 0x20, 0x1D, 0x80, 0xA);

    gDPSetTextureImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, gPal_Ci8_HUD);
    gDPTileSync(gMasterGfxPos++);
    gDPSetTile(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0100, G_TX_LOADTILE, 0, G_TX_NOMIRROR | 
        G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync(gMasterGfxPos++);
    gDPLoadTLUTCmd(gMasterGfxPos++, G_TX_LOADTILE, 255);
    gDPPipeSync(gMasterGfxPos++);
    
    func_80020D4C(5U, 0x9D, 0x6C, D_8007BAA4);
    func_80020D4C(5U, 0x8B, 0x7C, D_8007BAA5);
    func_80020D4C(5U, 0x9D, 0x8B, D_8007BAA6);
    func_80020D4C(5U, 0xAF, 0x7C, D_8007BAA7);

    if ((D_80092876 & U_CBUTTONS) && (arg0->PlayerMainStats->elements[FIRE] < ELEMENT_MAX)) { 
        arg0->PlayerMainStats->elements[FIRE]++;
        gGameState &= ~8; 
    } else if ((D_80092876 & D_CBUTTONS) && (arg0->PlayerMainStats->elements[WATER] < ELEMENT_MAX)) {  
        arg0->PlayerMainStats->elements[WATER]++;
        gGameState &= ~8;
    } else if ((D_80092876 & R_CBUTTONS) && (arg0->PlayerMainStats->elements[WIND] < ELEMENT_MAX)) { 
        arg0->PlayerMainStats->elements[WIND]++;
        gGameState &= ~8;
    } else if ((D_80092876 & L_CBUTTONS) && (arg0->PlayerMainStats->elements[EARTH] < ELEMENT_MAX)) {  
        arg0->PlayerMainStats->elements[EARTH]++;
        gGameState &= ~8;
    }    
    

    if ((gGameState & 8) == 0) {
        func_800268D4(0, 4, 0xFF);
    }
}

//#pragma GLOBAL_ASM("asm/nonmatchings/hud/func_8001F818.s")
void func_8001F818(void) {
    s32 sp34;
    Vec3f* temp_v0;

    temp_v0 = &gNPCData[D_8007BA74-1].transformationAnimation.posrot.pos;
    if (func_8002413C(temp_v0->x, (f32) (temp_v0->y + 14.0), temp_v0->z, &sp34, &D_8008C644) != 0) {
        gSPDisplayList(gMasterGfxPos++, gDL_Speech_bubble);
        func_80020F8C(sp34, D_8008C644 - 0x1E, 0x40, 0x1D, 0, 0, 0x400, 0x400);
        return;
    }
    D_8008C644 = 0xF0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/hud/func_8001F900.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hud/func_8001F9B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hud/func_8001FA60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hud/func_8001FB94.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/hud/func_8001FCF8.s")
void func_8001FCF8(MonsterBattleData* arg0, u16 arg1, u16 arg2, s16 arg3) {

    u32 i;
    UnknownMonsterData2* temp_t2 = arg0->unk68;

    for(i = 0; i < 7; i++) {
        if (D_8004D2CC[i] & arg1) {
            temp_t2->status[i] = arg2;
            temp_t2->unk22[i] = arg3;
            break;
        }
    }

    for(i = 0; i < 4; i++) {
    f32 var_f0;
    void* p;
    u16 temp;
        
        if ((D_8004D2DC[i] & arg1) && (temp_t2->unk44[i] == 0)) {
            temp_t2->unk32[i] = arg3;
            D_8008C748.unk0 = D_803A8E0C[arg2].unk8;
            D_8008C748.unk4 = D_803A8E0C[arg2].unkC;
            D_8008C748.unk8 = 1.0f;
            p = &D_803A8DD8[D_803A8E0C[arg2].unk0];
            if (((MonsterBaseData*)arg0->transformAnimation.unk64)->monsterType == 1) {
                var_f0 = (D_803A8E0C[arg2].unk4 & 0x100) 
                    ? arg0->unk68->unk94
                    : arg0->unk68->unk94 - (((MonsterBaseData*)arg0->transformAnimation.unk64)->hitboxHeight * arg0->transformAnimation.scale);
            } else {
                var_f0 = (D_803A8E0C[arg2].unk4 & 0x100) 
                    ? (f32)(arg0->transformAnimation.posrot.pos.y + (((MonsterBaseData*)arg0->transformAnimation.unk64)->hitboxWidth * 0.5 * arg0->transformAnimation.scale)) 
                    : arg0->transformAnimation.posrot.pos.y;
            }
            temp_t2->unk44[i] = 
                func_800177F8(D_803A8E0C[arg2].unk2, D_803A8E0C[arg2].unk4, arg0->transformAnimation.posrot.pos.x, var_f0, arg0->transformAnimation.posrot.pos.z, 0.0f, p, &D_8008C748, (void*)arg0);
            return;        
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/hud/func_8001FEEC.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/hud/func_800202E4.s")
void func_800202E4(MonsterBattleData *arg0)
{
    u32 i;
    UnknownMonsterData2 *temp_v0;
    UnknownMonsterData3 *temp_a0;

    temp_v0 = arg0->unk68;

    for(i = 0; i < 7; i++) {
        if(temp_v0->status[i] != 0) {
            temp_v0->status[i] = 0;
        }
    }

    for(i = 0; i < 4; i++) {
        if (temp_v0->unk44[i] != NULL)
        {
            temp_a0 = temp_v0->unk44[i];
            temp_a0->unk0 = 8;
            temp_a0->unk8 &= ~1;
            temp_v0->unk44[i] = NULL;
        }
    }
}

void blankfunc1 (void){
    return;
}

void blankfunc2 (void){
    return;
}

void blankfunc3 (void){
    return;
}

void blankfunc4 (void){
    return;
}

void blankfunc5 (void){
    return;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/hud/func_800203D0.s")
void func_800203D0(void)
{
  unk20e2cs *new_var;
  D_8008C648 = 0xB5;
  D_8008C64C = 0x1A;

  //Load palette for popup menues  
  gDPPipeSync(gMasterGfxPos++);
  gDPSetTextureImage(gMasterGfxPos++, 0, G_IM_SIZ_16b, 1, gPal_Ci8_HUD_magic);
  gDPTileSync(gMasterGfxPos++);
  gDPSetTile(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0100, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);  gDPLoadSync(gMasterGfxPos++);
  gDPLoadTLUTCmd(gMasterGfxPos++, G_TX_LOADTILE, 255);  
  gDPPipeSync(gMasterGfxPos++);
    
  new_var = &gHUD_magic_texture_attributes;
  if (D_8007D088->unk90 & 0x80)
  {
    func_800210FC((s32) new_var, 0, 0, 0x6E, 0x10, 0x64, 0x1C, 0x400, 0x400);
    func_800210FC((s32) new_var, 0, 0x10, 0x6E, 0x10, 0x64, 0x2C, 0x400, 0x400);
    func_800210FC((s32) new_var, 0, 0x20, 0x6E, 0x10, 0x64, 0x3C, 0x400, 0x400);
    func_800210FC((s32) new_var, 0, 0x30, 0x6E, 4, 0x64, 0x4C, 0x400, 0x400);
  }
  else
  {
    func_800210FC((s32) new_var, 0, 0, 0x6E, 0x10, 0x64, 0x1C, 0x400, 0x400);
    func_800210FC((s32) new_var, 0, 0x10, 0x6E, 0xA, 0x64, 0x2C, 0x400, 0x400);
    func_800210FC((s32) new_var, 0, 0x1A, 0x6E, 2, 0x64, 0x4E, 0x400, 0x400);
  }
  func_80020B4C(4, 0x11, 0, D_8007D0AC[D_8007D088->unk20->unk2]);
  func_80020E2C(&D_803A6F40, 0x20, 0x1D, 0x80, 0xA);

  //Load palette for HUD  
  gDPSetTextureImage(gMasterGfxPos++, 0, G_IM_SIZ_16b, 1, gPal_Ci8_HUD);
  gDPTileSync(gMasterGfxPos++);
  gDPSetTile(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0100, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);  gDPLoadSync(gMasterGfxPos++);
  gDPLoadTLUTCmd(gMasterGfxPos++, G_TX_LOADTILE, 255);
  gDPPipeSync(gMasterGfxPos++);
  if (D_8007D088->unk90 & 0x80)
  {
    func_80020D4C(3U, 0x10, 0x1C, (s32) D_8007D088->unk20->unk6);
    func_80020D4C(3U, 0x10, 0x26, (s32) D_8007D088->unk20->unkE);
    func_80020D4C(3U, 0x46, 0x1C, (s32) D_8007D088->unk20->unk2A);
    func_80020D4C(3U, 0x46, 0x26, (s32) D_8007D088->unk20->unkC);
    if (D_8007D088->unk20->unk26 != 4)
    {
      func_800210FC((s32) (&D_803A6F40), 0x5B, 3, 0xC, 0xC, (D_8007D088->unk20->unk26 * 0xC) + 0x20, 0x10, 0x400, 0x400);
    }
  }
}

//#pragma GLOBAL_ASM("asm/nonmatchings/hud/func_80020888.s")
void func_80020888(void) { //@TODO roll it up up up
    s32 var_v1;
    struct_8008C668* var_v0;

    var_v0 = D_8008C668;
    var_v1 = 8;
    do {
        var_v1 -= 4;
        var_v0->unk0 = 0;
        var_v0[1].unk0 = 0;
        var_v0[2].unk0 = 0;
        var_v0[3].unk0 = 0;
        var_v0 += 4;
    } while (var_v1 != 0);
}

//#pragma GLOBAL_ASM("asm/nonmatchings/hud/func_800208B8.s")
void func_800208B8(MonsterBattleData* arg0) {
    s32 i;
    struct_8008C668* var_v0;
    MonsterBaseData* temp_v1;

    var_v0 = D_8008C668;
    for (i = 7; i != 0 && var_v0->unk0 != 0; i--, var_v0++) {
        
    }
    var_v0->unk0 = 0x2D;
    var_v0->unk4 = (struct_8008C668_2* ) arg0;
    var_v0->unk10 = 0.0f;
    var_v0->unk8 = 0.0f;
    temp_v1 = arg0->transformAnimation.unk64;
    if (temp_v1->monsterType == 0) {
        var_v0->unkC = temp_v1->hitboxWidth * arg0->transformAnimation.scale;
    } else if (temp_v1->monsterType == 1) {
        var_v0->unkC = arg0->unk68->unk94 - arg0->transformAnimation.posrot.pos.y;
    } else {
        var_v0->unkC = (f32) ((f64) arg0->transformAnimation.scale * 600.0);
    }
    var_v0->unk14 = 0x23;
    var_v0->unk16 = 0x31;
    var_v0->unk18 = 0x29;
    var_v0->unk1A = 0xE;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/hud/func_80020988.s") //@TODO There's a lot of weirdness here. It matches, but at what cost? 
void func_80020988(void) {

    f32 var_f0;
    f32 var_f12;
    f32 var_f14;
    s32 var_s1;
    s32 sp74;
    s32 sp70;
    struct_8008C668* var_s0;
    unk20e2cs* new_var;
    
    gDPPipeSync(gMasterGfxPos++);
    gDPSetTextureImage(gMasterGfxPos++, 0, G_IM_SIZ_16b, 1, gPal_Ci8_status_symbols);
    gDPTileSync(gMasterGfxPos++);
    gDPSetTile(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0100, G_TX_LOADTILE, 0, G_TX_NOMIRROR 
        | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync(gMasterGfxPos++);
    gDPLoadTLUTCmd(gMasterGfxPos++, 7, 255);
    gDPPipeSync(gMasterGfxPos++);

    var_s0 = &D_8008C668;
    var_s1 = 8;

  while (var_s1 != 0)
  {
    if (var_s0->unk0 != 0)
    {
      var_f12 = var_s0->unk8;
      var_f14 = var_s0->unkC;
      new_var = &gHUD_status_symbols_attributes;
      var_f0 = var_s0->unk10;
      if (var_s0->unk4 != NULL)
      {
        var_f12 += var_s0->unk4->unk0;
        var_f14 += var_s0->unk4->unk4;
        var_f0 += var_s0->unk4->unk8;
      }
            func_8002413C(var_f12, var_f14, var_f0, &sp74, &sp70);
            func_800210FC((s32) new_var, sp74 - ((s32) var_s0->unk18 >> 1), sp70 - var_s0->unk1A, (s32) var_s0->unk18, (s32) var_s0->unk1A, (s32) var_s0->unk14, (s32) var_s0->unk16, 0x400, 0x400);
            var_s0->unk0 -= 1;
        }
        var_s1--;
        var_s0++;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/hud/func_80020B4C.s")
//https://decomp.me/scratch/mr85d

//#pragma GLOBAL_ASM("asm/nonmatchings/hud/func_80020D18.s")
s32 func_80020D18(u8* arg0) {
    s32 ret;
    u8 val;

    ret = 0;
    val = *arg0;
    
    arg0 += 1;
    
    if (val != 0) {
        do {
            val = *arg0;
            ret++;
            arg0++;
        } while (val != 0);
    }
    return ret;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/hud/func_80020D4C.s")
void func_80020D4C(u16 countFlag, s32 arg1, s32 arg2, s32 arg3) {
  u8 *string_ptr;
  u8 string_buffer[0xC];
  s32 num_digits;
   
  string_ptr = string_buffer;
  num_digits = count_digits(arg3, string_buffer, countFlag);
    for (;num_digits != 0; num_digits--, string_ptr++) {
      if (*string_ptr != ' ') {
        func_80020F8C(arg1, arg2, 8, 0xA, (*string_ptr * 8) + 0x20, 0x1D, 0x400, 0x400);
        arg1 += 7;
      } else if (countFlag & 6) {
        arg1 += 7;
      }
    }
}

void func_80020E24(void) {
}

//#pragma GLOBAL_ASM("asm/nonmatchings/hud/func_80020E2C.s")
void func_80020E2C(unk20e2cs* tex, s32 tileX, s32 tileY, s32 tileWidth, s32 tileHeight) {
    gDPSetTextureImage(gMasterGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, tex->unk8, tex->unk0);
    gDPSetTile(gMasterGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, ((((tileX + tileWidth) - tileX) + 8)) >> 3, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync(gMasterGfxPos++);
    gDPLoadTile(gMasterGfxPos++, G_TX_LOADTILE, tileX * 4, tileY * 4, (tileX + tileWidth) * 4, (tileY + tileHeight) * 4);
    gDPPipeSync(gMasterGfxPos++);
    gDPSetTile(gMasterGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, ((((tileX + tileWidth) - tileX) + 8)) >> 3, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, tileX * 4, tileY * 4, (tileX + tileWidth) * 4, (tileY + tileHeight) * 4);
}

//#pragma GLOBAL_ASM("asm/nonmatchings/hud/func_80020F8C.s")
void func_80020F8C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) //@TODO this fella has a weird label that MAY be removable. 
{
  arg0 += D_8008C648;
  arg2 += arg0;
  arg1 += D_8008C64C;
  if (arg2 >= D_8008C650)
  {
    arg3 += arg1;
    if (((arg3 >= D_8008C654) && (D_8008C658 >= arg0)) && (D_8008C65C >= arg1))
    {
      if (D_8008C658 < arg2)
      {
        arg2 = D_8008C658;
      }
      if (D_8008C65C < arg3)
      {
        arg3 = D_8008C65C;
      }
      if (arg0 < D_8008C650)
      {
        arg4 = (arg4 - arg0) + D_8008C650;
        arg0 = D_8008C650;
      }
      if (arg1 < D_8008C654)
      {
        arg5 = (arg5 - arg1) + D_8008C654;
        arg1 = D_8008C654;
      }
      gSPTextureRectangle(gMasterGfxPos++, arg0 << 2, arg1 << 2, arg2 << 2, arg3 << 2, 0, arg4 << 5, arg5 << 5, arg6, arg7);
    }
  }
 dummy_label_814065: ;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/hud/func_800210FC.s")
void func_800210FC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    func_80020E2C(arg0, arg5, arg6, arg3, arg4);
    func_80020F8C(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/hud/D_800716A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hud/D_800716A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hud/D_800716B0.s")
