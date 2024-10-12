#ifndef _1E4B0_H_
#define _1E4B0_H_

typedef struct {
    s16 unk0;
    s16 unk2;
    void* unk4;
    void* unk8;
}unk1E0ACarg2s;

typedef struct {
/*0x00*/ Vec3f pos;
/*0x0C*/ f32 yrot;
/*0x10*/ f32 zrot;
/*0x14*/ f32 xrot;
/*0x18*/ Vec3f scale;
/*0x24*/ f32 unk24;
/*0x28*/ f32 unk28;
/*0x2C*/ f32 unk2C;
/*0x30*/ s16 unk30; //maybe padding. 
/*0x32*/ u16 startingFrame;
}LimbKeyframe;

typedef struct {
    LimbKeyframe* unk0; //pointer to an array
    u16 unk4;
    u16 numFramesInAnim;
    Vec3f unk8;
    s8 unk14;
    s8 unk15;
    u8 unk16;
    char unk17; //unread?
    s32 unk18;
    char unk1C[4];
}unk22b40s;

#endif
