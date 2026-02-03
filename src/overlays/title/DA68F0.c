#include "common.h"

typedef struct UnkStruct_80102E30_Title_s
{
    u16 unk0;
    u16 unk2;
    f32 unk4;
    f32 unk8;
} UnkStruct_80102E30_Title;

extern s32 D_8011AD34;
extern u8 D_80103138_ovl_title[];
extern s32 D_80103420_ovl_title;
extern s32 D_80103424_ovl_title;
extern s32 D_8011AD30;
extern s32 D_8011AD38;
extern s32 D_8011AD3C;
extern s32 D_8011AD40;
extern s32 gTitleTimeoutTimer;
extern u16 D_80092876;
extern s32 D_80103110_ovl_title;
extern s32 D_8011AD3C;
extern s32 D_8011AD40;
extern s8 D_8011AD50;
extern s32 D_8011AD54;
extern s32 D_8011AD60;
extern Gfx D_801033A0_ovl_title[];

void func_80100000_ovl_title(void);
s32 func_801000A8_ovl_title(void);
void func_80100BA0_ovl_title(s32);

void func_80100000_ovl_title(void)
{
    D_8011AD30 = 0;
    gTitleTimeoutTimer = 0;
    D_80103424_ovl_title = 1;
    D_80103420_ovl_title = 0;
    D_8011AD34 = 1;
    D_8011AD3C = 0;
    D_8011AD40 = 8;
    D_8011AD38 = 0;
}

s32 func_8010004C_DA693C_ovl_title(void)
{
    if (func_801000A8_ovl_title() == 0)
    {
        if (gTitleTimeoutTimer == 0)
        {
            return 1;
        }
        if (gTitleTimeoutTimer == 0xF)
        {
            gTitleTimeoutTimer = 0;
            return 0;
        }
    }
    return 2;
}

#ifdef NEEDS_DATA

s32 func_801000A8_DA6998(void)
{
    static u8 D_80103114_DA9A04;
    static u32 D_80103118_DA9A08;
    static u16 D_8010311C_DA9A0C;
    static u8 D_80103120_DA9A10;

    if (D_80103120_DA9A10 == 0)
    {
        D_8011AD30 = 3;
        gGlobalStartScreenTimer = 1;
        D_8011AD44 = 0;
        D_8006AC60 = 0;
        D_80103120_DA9A10++;
    }

    switch (D_8011AD30)
    {
    case 3:
        gGlobalStartScreenTimer = gGlobalStartScreenTimer - 1;
        if (gGlobalStartScreenTimer == 0)
        {
            gGlobalStartScreenTimer = 0x1518;
            D_8011AD30++;
            D_80103424_DA9D14 = 0x14;
            D_80103420_DA9D10 = 2;
        }
        break;
    case 4:
        func_801006D8_DA6FC8();
        if (D_80103420_DA9D10 == 2)
        {
            func_80102E30_DA9720();
        }
        if ((gGlobalStartScreenTimer == 0) && (D_8011AD44 == 0) && (D_80103110_DA9A00 == 0))
        {
            D_80103110_DA9A00 = 1;
            D_80103424_DA9D14 = 0x3C;
            D_80103420_DA9D10 = 1;
            gGlobalStartScreenTimer = 0x3C;
        }
        if (D_80103110_DA9A00 == 1)
        {
            func_80102E30_DA9720();
            if (D_80103420_DA9D10 == 0)
            {
                gPushStartBlinkTimer = 0;
                gPushStartBlinkFrequency = 8;
                gGlobalStartScreenTimer = 0;
                D_8011AD30 = 0;
                D_80103110_DA9A00 = 0;
                D_8011AD44 = 0;
            }
        }
        if ((gGlobalStartScreenTimer == 0) && (D_8011AD44 == 1))
        {
            D_8011AD44 = 2;
            gGlobalStartScreenTimer = 2;
            D_8011AD30++;
        }
        break;
    case 5:
        func_801006D8_DA6FC8();
        if (D_8010311C_DA9A0C == 0)
        {
            D_80103118_DA9A08 = D_80103118_DA9A08 + 1;
        }
        else
        {
            D_80103118_DA9A08 = 0;
        }
        if (!(D_80092876 & 0xF000) && (D_80092871 >= -0x13) && (D_80092871 < 0x14) && (D_80092872 >= -0x13) && (D_80092872 < 0x14))
        {
            D_8010311C_DA9A0C = 0;
        }
        else
        {
            D_8010311C_DA9A0C = 1;
        }
        // D_80103118_DA9A08 = var_a1;
        if (D_80103118_DA9A08 >= 0x1C21U)
        {
            D_8010311C_DA9A0C = 0;
            D_8011AD44 = 4;
            D_80103110_DA9A00 = 1;
            gGlobalStartScreenTimer = 2;
            D_80103118_DA9A08 = 0;
        }
        if (D_80103110_DA9A00 == 0)
        {
            gGlobalStartScreenTimer = 0x14;
        }
        if ((gGlobalStartScreenTimer == 0) && ((D_8011AD44 == 3) || (D_8011AD44 == 4)))
        {
            if (D_8011AD44 == 4)
            {
                D_80103110_DA9A00 = 2;
                D_80103424_DA9D14 = 0x3C;
                D_80103420_DA9D10 = 1;
            }
            gGlobalStartScreenTimer = 0x3C;
            if (D_8011AD44 == 3)
            {
                D_8011AD44 = 5;
                D_8011AD30 += 1;
                gPushStartBlinkTimer = 0xFF;
                gPushStartBlinkFrequency = 0;
                D_80103110_DA9A00 = 0;
            }
        }
        if (D_80103110_DA9A00 == 2)
        {
            func_80102E30_DA9720();
            if (D_80103420_DA9D10 == 0)
            {
                gPushStartBlinkTimer = 0;
                gPushStartBlinkFrequency = 8;
                gGlobalStartScreenTimer = 0;
                D_8011AD38 = 0;
                D_8011AD30 = 3;
                D_8011AD44 = 0;
                D_80103110_DA9A00 = 0;
            }
        }
        break;
    case 6:
        func_801006D8_DA6FC8();
        if (D_80103114_DA9A04 < 2)
        {
            D_80103114_DA9A04++;
        }
        else if ((D_8007B344 & 0xF0) == 0x10)
        {
            D_8011AD30 = 8;
            D_80103424_DA9D14 = 0x3C;
            D_80103420_DA9D10 = 1;
        }
        else
        {
            D_8011AD30 = 8;
            D_80103424_DA9D14 = 0x3C;
            D_80103420_DA9D10 = 1;
        }
        break;
    case 7:
        func_801006D8_DA6FC8();
        if (D_80103110_DA9A00 == 0)
        {
            gGlobalStartScreenTimer = 0x14;
        }
        if (D_8011AD44 == 2)
        {
            D_8011AD30 = 5;
        }
        // goto mode
        if ((gGlobalStartScreenTimer == 0) && ((D_8011AD44 == 0xB) || (D_8011AD44 == 0xC) || (D_8011AD44 == 0xD) || (D_8011AD44 == 0xE) || (D_8011AD44 == 9) || (D_8011AD44 == 0xA)))
        {
            if (D_8011AD44 == 9)
            {
                gGlobalStartScreenTimer = 0xA;
                D_8011AD30 = 5;
                D_80103110_DA9A00 = 0;
                D_8011AD44 = 2;
            }
            if (D_8011AD44 == 0xA)
            {
                gGlobalStartScreenTimer = 0xA;
                D_8011AD30 = 5;
                D_80103110_DA9A00 = 0;
                D_8011AD44 = 2;
            }
            if (D_8011AD44 == 0xC)
            {
                gGlobalStartScreenTimer = 5;
                D_8011AD44 = 9;
                D_80103110_DA9A00 = 0;
            }
            if (D_8011AD44 == 0xB)
            {
                gGlobalStartScreenTimer = 0x3C;
                D_8011AD30 += 1;
                D_8011AD44 = 0xF;
                gPushStartBlinkTimer = 0;
                gPushStartBlinkFrequency = 0x100;
                D_80103424_DA9D14 = 0x3C;
                D_80103420_DA9D10 = 1;
                D_80103110_DA9A00 = 0;
            }
            if (D_8011AD44 == 0xD)
            {
                gGlobalStartScreenTimer = 5;
                D_8011AD44 = 0xA;
                D_80103110_DA9A00 = 0;
            }
            if (D_8011AD44 == 0xE)
            {
                gGlobalStartScreenTimer = 0xA;
                D_8011AD30 = 5;
                D_8011AD44 = 2;
                D_80103110_DA9A00 = 0;
            }
        }
        break;
    case 8:
        func_80100B14_DA7404();
        func_80102E30_DA9720();
        break;
    }
    if (gGlobalStartScreenTimer == 0)
    {
        D_8010311C_DA9A0C = 0;
        D_80103118_DA9A08 = 0;
    }
    return gGlobalStartScreenTimer;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/title/DA68F0/func_801000A8_ovl_title.s")
#endif

void func_801006D8_ovl_title(void)
{
    s32 var_v0;

    gSPDisplayList(gMasterGfxPos++, D_80103138_ovl_title);
    gDPSetEnvColor(gMasterGfxPos++, 0, 0, 0, D_8011AD3C);

    func_80100BA0_ovl_title((u32)gTitleTimeoutTimer);
    D_8011AD3C += D_8011AD40;
    if (D_8011AD3C >= 0x100)
    {
        D_8011AD3C = 0xFF;
        D_8011AD40 = -D_8011AD40;
    }
    else if (D_8011AD3C < 0)
    {
        D_8011AD3C = 0;
        D_8011AD3C = 0;
        D_8011AD40 = -D_8011AD40;
    }
    D_8011AD54 = D_8011AD3C;
    if (D_80103420_ovl_title == 0)
    {
        if ((gTitleTimeoutTimer == 0) && (D_80092876 & 0x1000))
        {
            func_80025B8C(1, 0xFF, 0x40);
            D_8011AD3C = 0;
            D_8011AD40 = 0x80;
            gTitleTimeoutTimer = 1;
            D_8011AD34 = 0x3C;
        }
        else if (gTitleTimeoutTimer == 2)
        {
            if (D_80092876 & 0xB000)
            {
                func_80025B8C(1, 0xFF, 0x40);
                D_8011AD3C = 0;
                D_8011AD40 = 0x80;
                gTitleTimeoutTimer = 3;
                D_8011AD34 = 0x3C;
                D_80103110_ovl_title = 1;
            }
            else if (D_80092876 & 0x4000)
            {
                func_80025B8C(2, 0xFF, 0x40);
                D_8011AD3C = 0xFF;
                D_8011AD40 = 0x80;
                gTitleTimeoutTimer = 4;
                D_8011AD34 = 2;
                D_80103110_ovl_title = 1;
            }
        }
        else if ((gTitleTimeoutTimer == 8) || (gTitleTimeoutTimer == 7))
        {
            if (D_80092876 & 0xB000)
            {
                func_80025B8C(1, 0xFF, 0x40);
                D_8011AD3C = 0;
                D_8011AD40 = 0x80;
                D_80103110_ovl_title = 1;
                D_8011AD34 = 0x3C;
                if (D_8011AD50 == 0)
                {
                    if (gTitleTimeoutTimer == 8)
                    {
                        gTitleTimeoutTimer = 0xB;
                    }
                    else
                    {
                        gTitleTimeoutTimer = 0xD;
                    }
                }
                else if (gTitleTimeoutTimer == 8)
                {
                    gTitleTimeoutTimer = 0xC;
                }
                else
                {
                    gTitleTimeoutTimer = 0xE;
                }
            }
            else if (D_80092876 & 0x4000)
            {
                func_80025B8C(2, 0xFF, 0x40);
                D_8011AD3C = 0xFF;
                D_8011AD40 = 0x80;
                gTitleTimeoutTimer = 2;
                D_8011AD34 = 2;
                D_80103110_ovl_title = 1;
            }
        }
        else if (gTitleTimeoutTimer == 6)
        {
            if (D_80092876 & 0xF000)
            {
                func_80025B8C(2, 0xFF, 0x40);
                D_8011AD3C = 0xFF;
                D_8011AD40 = 0x80;
                gTitleTimeoutTimer = 2;
                D_8011AD34 = 2;
            }
        }
        else if (gTitleTimeoutTimer == 9)
        {
            if (D_80092876 & 0xB000)
            {
                func_80025B8C(1, 0xFF, 0x40);
                D_80103110_ovl_title = 1;
            }
        }
        else if ((gTitleTimeoutTimer == 0xA) && (D_80092876 & 0xB000))
        {
            func_80025B8C(1, 0xFF, 0x40);
            D_80103110_ovl_title = 1;
        }
    }
    D_8011AD34 -= 1;
}

void func_80100B14_ovl_title(void)
{
    gSPDisplayList(gMasterGfxPos++, D_80103138_ovl_title);
    gDPSetEnvColor(gMasterGfxPos++, 0x00, 0x00, 0x00, 0xFF);

    func_80100BA0_ovl_title(gTitleTimeoutTimer);
    if (--D_8011AD34 == 0)
    {
        gTitleTimeoutTimer = 0xF;
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/title/DA68F0/func_80100BA0_ovl_title.s")

#ifdef NEEDS_DATA
void func_80102E30_ovl_title(void)
{
    static UnkStruct_80102E30_Title D_80103428_ovl_title = {0};

    if (D_80103420_ovl_title == 0)
    {
        if (D_80103428_ovl_title.unk0 != 0)
        {
            D_80103428_ovl_title.unk0 = 0;
        }
    }
    else
    {
        if (D_80103428_ovl_title.unk0 == 0)
        {
            D_80103428_ovl_title.unk0 = -1;

            D_80103428_ovl_title.unk4 = 255.0f / D_80103424_ovl_title;
            D_80103428_ovl_title.unk2 = D_80103424_ovl_title;

            switch (D_80103420_ovl_title)
            { /* irregular */
            case 1:
            case 3:
                D_80103428_ovl_title.unk8 = 0.0f;
                break;
            case 2:
            case 4:
                D_80103428_ovl_title.unk8 = 255;
                break;
            default:
                D_80103428_ovl_title.unk8 = 128.0f;
                break;
            }
        }
        func_80102F14_ovl_title(&D_80103428_ovl_title);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/title/DA68F0/func_80102E30_ovl_title.s")
#endif

void func_80102F14_ovl_title(UnkStruct_80102E30_Title *arg0)
{
    s32 rgbColorValue;
    s32 alpha;

    arg0->unk2 -= 1;
    if (D_80103420_ovl_title & 1)
    {
        arg0->unk8 += arg0->unk4;
    }
    else
    {
        arg0->unk8 -= arg0->unk4;
    }
    switch (D_80103420_ovl_title)
    { /* irregular */
    case 3:
    case 4:
        rgbColorValue = 255;
        break;
    case 1:
    case 2:
        rgbColorValue = 0;
        break;
    default:
        rgbColorValue = 0;
        break;
    }

    if (arg0->unk8 <= 0.0f)
    {
        D_80103420_ovl_title = 0;
        arg0->unk8 = 0.0f;
        arg0->unk0 = 0;
    }
    else if (arg0->unk8 > 255.0f)
    {
        D_80103420_ovl_title = 0;
        arg0->unk8 = 255.0f;
        arg0->unk0 = 0;
    }
    if (arg0->unk2 == 0)
    {
        if ((D_80103420_ovl_title == 3) || (D_80103420_ovl_title == 1))
        {
            D_80103420_ovl_title = 0;
            arg0->unk8 = 255.0f;
            arg0->unk0 = 0;
        }
        else if ((D_80103420_ovl_title == 4) || (D_80103420_ovl_title == 2))
        {
            D_80103420_ovl_title = 0;
            arg0->unk8 = 0.0f;
            arg0->unk0 = 0;
        }
    }

    alpha = arg0->unk8;
    gDPPipeSync(gMasterGfxPos++);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, rgbColorValue, rgbColorValue, rgbColorValue, alpha);
    gDPSetRenderMode(gMasterGfxPos++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    gSPDisplayList(gMasterGfxPos++, &D_801033A0_ovl_title);
    gDPFillRectangle(gMasterGfxPos++, 0, 0, 336, 960);

    D_8011AD60 = rgbColorValue;
}
