#include "common.h"

extern s32 gIntroFadeTimer;
extern s32 gIntroFadeAlpha;
extern s32 gIntroFadeState;
extern u8 D_80106240_ovl_intro[]; //DL
extern u8 D_8015BC78_ovl_intro[]; //No Controller Connected texture
extern u8 D_8015CEB8_ovl_intro[]; //Rumble Pak Detected texture. 

//#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC4700/func_801030E0_ovl_intro.s")
void func_801030E0_ovl_intro(void) {

    gSPDisplayList(gMasterGfxPos++, D_80106240_ovl_intro);
    gDPSetRenderMode(gMasterGfxPos++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, TEXEL0, 0, 0, 0, ENVIRONMENT, 0, 0, 0, TEXEL0, 0, 0, 0, ENVIRONMENT);
    gDPSetEnvColor(gMasterGfxPos++, 0x00, 0x00, 0x00, gIntroFadeAlpha);

    func_80103690_ovl_intro();
    
    gIntroFadeTimer -= 1;
    switch (gIntroFadeState) {
    case 0:
        gIntroFadeAlpha += 0x10;
        if (gIntroFadeAlpha >= 0x100) {
            gIntroFadeAlpha = 0xFF;
            gIntroFadeState += 1;
            gIntroFadeTimer = 0x5A;
        }
        return;
    case 1:
        if (gIntroFadeTimer == 0) {
            gIntroFadeState += 1;
            gIntroFadeTimer = 0x20;
        }
        break;
    case 2:
        gIntroFadeAlpha -= 0x10;
        if (gIntroFadeAlpha < 0) {
            gIntroFadeAlpha = 0;
            gIntroFadeState = 0;
            gIntroFadeTimer = 0;
        }
        break;
    }
}

//#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC4700/func_8010324C_ovl_intro.s")
void func_8010324C_ovl_intro(void) {

    gSPDisplayList(gMasterGfxPos++, D_80106240_ovl_intro);
    gDPSetRenderMode(gMasterGfxPos++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, TEXEL0, 0, 0, 0, ENVIRONMENT, 0, 0, 0, TEXEL0, 0, 0, 0, ENVIRONMENT);
    gDPSetEnvColor(gMasterGfxPos++, 0x00, 0x00, 0x00, gIntroFadeAlpha);
    
    func_80103954_ovl_intro();
    
    gIntroFadeTimer -= 1;
    switch (gIntroFadeState) {
    case 0:
        gIntroFadeAlpha += 8;
        if (gIntroFadeAlpha >= 0x100) {
            gIntroFadeAlpha = 0xFF;
            gIntroFadeState += 1;
            gIntroFadeTimer = 0x64;
        }
        return;
    case 1:
        if (gIntroFadeTimer == 0) {
            gIntroFadeState += 1;
            gIntroFadeTimer = 0x20;
            return;
        }
        break;
    case 2:
        gIntroFadeAlpha -= 8;
        if (gIntroFadeAlpha < 0) {
            gIntroFadeAlpha = 0;
            gIntroFadeState = 0;
            gIntroFadeTimer = 0;
        }
        break;
    }
}

//#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC4700/func_801033B8_ovl_intro.s")
void func_801033B8_ovl_intro(void) {

    gSPDisplayList(gMasterGfxPos++, &D_80106240_ovl_intro);
    gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, TEXEL0, 0, 0, 0, ENVIRONMENT, 0, 0, 0, TEXEL0, 0, 0, 0, ENVIRONMENT);
    gDPSetRenderMode(gMasterGfxPos++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetEnvColor(gMasterGfxPos++, 0x00, 0x00, 0x00, gIntroFadeAlpha);

    
    func_80103DB8_ovl_intro();
    gIntroFadeTimer -= 1;
    switch (gIntroFadeState) {
    case 0:
        gIntroFadeAlpha += 8;
        if (gIntroFadeAlpha >= 0x100) {
            gIntroFadeAlpha = 0xFF;
            gIntroFadeState += 1;
            gIntroFadeTimer = 0x78;
        }
        return;
    case 1:
        if (gIntroFadeTimer == 0) {
            gIntroFadeState += 1;
            gIntroFadeTimer = 0x20;
        }
        break;
    case 2:
        gIntroFadeAlpha -= 8;
        if (gIntroFadeAlpha < 0) {
            gIntroFadeAlpha = 0;
            gIntroFadeState = 0;
            gIntroFadeTimer = 0;
        }
        break;
    }
}

//#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC4700/func_80103524_ovl_intro.s")
void func_80103524_ovl_intro(void) {

    gSPDisplayList(gMasterGfxPos++, D_80106240_ovl_intro);
    gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, TEXEL0, 0, 0, 0, ENVIRONMENT, 0, 0, 0, TEXEL0, 0, 0, 0, ENVIRONMENT);
    gDPSetRenderMode(gMasterGfxPos++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetEnvColor(gMasterGfxPos++, 0x00, 0x00, 0x00, gIntroFadeAlpha);
    
    func_8010421C_ovl_intro();
    gIntroFadeTimer -= 1;
    switch (gIntroFadeState) {                      /* irregular */
    case 0:
        gIntroFadeAlpha += 8;
        if (gIntroFadeAlpha >= 0x100) {
            gIntroFadeAlpha = 0xFF;
            gIntroFadeState += 1;
            gIntroFadeTimer = 0x73;
        }
        return;
    case 1:
        if (gIntroFadeTimer == 0) {
            gIntroFadeState += 1;
            gIntroFadeTimer = 0x20;
        }
        break;
    case 2:
        gIntroFadeAlpha -= 8;
        if (gIntroFadeAlpha < 0) {
            gIntroFadeAlpha = 0;
            gIntroFadeState = 0;
            gIntroFadeTimer = 0;
        }
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC4700/func_80103690_ovl_intro.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC4700/func_80103954_ovl_intro.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC4700/func_80103DB8_ovl_intro.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC4700/func_8010421C_ovl_intro.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC4700/func_80104874_ovl_intro.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC4700/func_801051B4_ovl_intro.s")
void func_801051B4_ovl_intro(void) {

    gSPDisplayList(gMasterGfxPos++, D_80106240_ovl_intro);
    gDPSetTextureLUT(gMasterGfxPos++, G_TT_RGBA16);
    gDPSetCombineMode(gMasterGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(gMasterGfxPos++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetTextureImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_8015CEB8_ovl_intro);
    gDPTileSync(gMasterGfxPos++);
    gDPSetTile(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0100, G_TX_LOADTILE, 0, G_TX_NOMIRROR 
               | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync(gMasterGfxPos++);
    gDPLoadTLUTCmd(gMasterGfxPos++, G_TX_LOADTILE, 15);
    gDPPipeSync(gMasterGfxPos++);
    gDPSetTextureImage(gMasterGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 88, D_8015BC78_ovl_intro);
    gDPSetTile(gMasterGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 11, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR 
               | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync(gMasterGfxPos++);
    gDPLoadTile(gMasterGfxPos++, G_TX_LOADTILE, 0, 0, qu102(88), qu102(13));
    gDPPipeSync(gMasterGfxPos++);
    gDPSetTile(gMasterGfxPos++, G_IM_FMT_CI, G_IM_SIZ_4b, 11, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR 
               | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, 0, 0, qu102(176), qu102(13));
    gSPTextureRectangle(gMasterGfxPos++, qu102(72), qu102(114), qu102(248), qu102(127), G_TX_RENDERTILE, 0, 0, qs510(1), qs510(1));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC4700/func_8010541C_ovl_intro.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/intro/DC4700/func_8010575C_ovl_intro.s")
