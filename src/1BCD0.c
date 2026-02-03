#include "common.h"
#include "1BCD0.h"
typedef struct {
    s32 unk0;
    s32 unk4;
    u16 unk8;
    char unkA[2];
    f32 unkC;
    f32 unk10;
    f32 unk14;
    char unk18[0x10];
    f32 unk28;
    f32 unk2C;
    char unk30[4];
    f32 unk34;
    char unk38[4];
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    char unk50[4];
    f32 unk54;
    f32 unk58;
    f32 unk5C;
    f32 unk60;
    f32 unk64;
    f32 unk68;
    f32 unk6C;
    f32 unk70;
    char unk74[4];
    f32 unk78;
    f32 unk7C;
    s32 unk80;
    f32 unk84;
}struct_80086DC0;

typedef struct {
    char unk00[0xC0];
    Mtx unkC0[1];
} teststruct;

extern Mtx D_2000000[];
extern u8 D_8004D050[]; //some display list
extern s32 D_8007B2F8;
extern struct_80086DC0 D_80086DC0;

void func_8001B0D0(void) {
    s32 var_v1;
    Dust* var_v0;

    var_v0 = D_80088428;
    var_v1 = 0x100;
    while (var_v1 > 0) {
        var_v0->unk0 = 0;
        var_v0++;
        var_v1--;
    }
    gNumDustParticlesToSpawn = 0;
}

Dust* func_8001B108(Dust* arg0) {
    Dust* ret = D_80088428;
    u32 i = 0x100;

    while((i > 0) && (ret->unk0 != 0)){
        i--;
        ret++;
    }

    if (i != 0) {
        *ret = *arg0;
        gNumDustParticlesToSpawn++;
    } else {
        ret = NULL;
    }
    return ret;
}

void func_8001B19C(teststruct* arg0) {
    s32 i;
    u8* dust_texture_ptr;
    Dust* dust;
    MtxF spB4;
    MtxF sp74;

    i = gNumDustParticlesToSpawn;
    dust_texture_ptr = NULL;
    dust = D_80088428;
    while (i != 0) {
        if (dust->unk0 != 0) {
            dust->unk0--;
            if (dust_texture_ptr != dust->dustTexture) {
                dust_texture_ptr = dust->dustTexture;
                func_8001B448(dust->unk8, dust_texture_ptr, dust->unk9, dust->unkA, (s32) dust->unkB, (s32) dust->unkC);
            }
            if (dust->unk4 != NULL) {
                ((void (*)(Dust*)) dust->unk4)(dust);
            } else {
                gSPDisplayList(gMasterGfxPos++, D_8004D050);
            }
            if (dust->unk2 & 1) {
                func_80023A08(&spB4, dust->unk30, dust->unk34, dust->unk38);
                spB4.mf[3][0] = dust->unk18;
                spB4.mf[3][1] = dust->unk1C;
                spB4.mf[3][2] = dust->unk20;
                func_80023DF4(&spB4, dust->unk28, dust->unk28, dust->unk28);
            } else {
                func_8002371C(&spB4, dust->unk18, dust->unk1C, dust->unk20, D_80086DC0.unkC, D_80086DC0.unk10, D_80086DC0.unk14);
                if (dust->unk24 != 0.0f) {
                    func_80023570(&sp74, 0.0f, 0.0f, dust->unk24);
                    guMtxCatF((f32 (*)[4]) &sp74, (f32 (*)[4]) &spB4, (f32 (*)[4]) &spB4);
                }
                func_80023DF4(&spB4, dust->unk28, dust->unk2C, 1.0f);
            }
            guMtxF2L((f32 (*)[4]) &spB4, &arg0->unkC0[D_8007B2F8]);
            gSPMatrix(gMasterGfxPos++, &D_2000000[D_8007B2F8+3].m[0][0], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            D_8007B2F8++;
            gSPDisplayList(gMasterGfxPos++, dust->dustDL);
            if (dust->unk0 == 0) {
                gNumDustParticlesToSpawn -= 1;
            }
            i--;
        }
        dust++;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/1BCD0/func_8001B448.s")
