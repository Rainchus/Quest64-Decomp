#ifndef _1D160_H_
#define _1D160_H_

extern u16 gBattleState;
extern f32 D_8008C574;
extern s16 D_8008C578;
extern u16 gAllowBattles;

typedef struct unk_ptr_2_s {
    u16 unk0;
    u16 unk2;
    s16 unk4;
    s16 unk6;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    char unk24[4];
    u16 unk28;
    char unk2A[2];
}unkptr2s;

typedef struct submap_data_s {
    u16 unk0;
    u16 unk2;
    void* unk4;
    s32 unk8;
    void* unkC;
    char unk10[4];
    u16 unk14;
    char unk16[2];
}unkSubmapData;

typedef struct {
    u16 map_flags;
    char pad[2]; //may not be padding. Investigate further
    u32 rom_start;
    u32 rom_end;
    u8* map_ram_ptr;
    u8* unk10;
    unkptr2s* unk14;
    unkSubmapData* submap_data;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    s32 unk3C;
    s32 num_submaps;
}MapData;


#endif
