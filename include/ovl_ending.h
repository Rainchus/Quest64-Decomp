#ifndef _OVL_ENDING_H_
#define _OVL_ENDING_H_

typedef struct {
    s16 unk0;
    char unk2[2];
    s32 unk4;
    s32 unk8;
    char unkC[4];
    char unk10[4];
    char unk14[4];
    char unk18[4];
    s32 unk1C;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
    char unk2C[4];
    void* unk30;
    void* unk34;
    char unk38[0x18];
}unk8015701c;

typedef struct {
    char unk0[0x22];
    s16 unk22;
    char unk24[4];
}unk1061b0_2;

typedef struct {
    unk1061b0_2* unk0;
    s32 unk4;
}unk801061B0;

typedef struct {
    s32 unk0;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s32 unk14;
    s32 unk18;
    f32 unk1C;
    f32 unk20;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    s16 unk2E;
    s16 unk30;
    u16 unk32;
    s16 unk34;
    char unk36[2];
    s32 unk38;
    s32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    s16 unk4C;
    s16 unk4E;
}unk80156fe8_s;

extern unk80156fe8_s D_80156FE8[];
extern unk801061B0 D_801061B0_ovl_ending[];
extern u32 D_801061B8_ovl_ending;
extern unk8015701c D_8015701C[];
extern s32 D_801035A0_ovl_ending;
extern s32 D_801035A4_ovl_ending;
extern s32 D_80156FC0;
extern s32 D_80156FC4;
extern s32 D_80156FC8;
extern s32 D_80156FCC;
extern s32 D_80156FD0;
extern s32 D_80156FD4;
extern s32 D_80156FD8;
extern s32 D_80156FDC;
extern s32 D_80156FE0;
extern s32 D_80156FE4;

void func_80100970_ovl_ending(void);
s32 func_80100184_ovl_ending(void);


#endif
