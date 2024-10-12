#ifndef _33D0_H_
#define _33D0_H_

//structs
typedef struct {
    u16 map;
    u16 submap;
    f32 x;
    f32 z;
    f32 yrot;
}SaveSpawnLocation;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u16 unkC;
    char unkE[2];
    s32 unk10;
    f32 unk14;
}unk80085368;

typedef struct PlayerMainData{
    /*0x00*/ u16 unk0;
    /*0x02*/ s16 unk2;
    /*0x04*/ u16 currHP;
    /*0x06*/ u16 maxHP;
    /*0x08*/ u16 currMP;
    /*0x0A*/ u16 maxMP;
    /*0x0C*/ u16 agi;
    /*0x0E*/ u16 def;
    /*0x10*/ s32 exp;
    /*0x14*/ s32 stone; //unused currency. Name derived from beta screenshots. 
    /*0x18*/ f32 collisionSize;
    /*0x1C*/ f32 unk1C; //height? 160.0f by default. Lowering it makes numbers appear lower when brian takes damage, and rocks come out of his chest. 
    /*0x20*/ f32 unk20; //also affects collision size. May be zCollisionSize and the above are X and Y.
    /*0x24*/ u8 elements[4];
    /*0x28*/ u16 HPXP;
    /*0x2A*/ u16 MPXP;
    /*0x2C*/ u16 agiXP;
    /*0x2E*/ u16 defXP;
    /*0x30*/ u8 HPLevel;
    /*0x31*/ u8 MPLevel;
    /*0x32*/ u8 agiLevel;
    /*0x33*/ u8 defLevel;
    /*0x34*/ u8 spiritLevel;
    /*0x35*/ u8 unk35;
    /*0x36*/ u8 unk36;
    /*0x37*/ u8 unk37;
    /*0x38*/ u16 unk38;
    /*0x3A*/ s16 unk3A;
    /*0x3C*/ s16 unk3C; //animation related
    /*0x3E*/ s16 unk3E; //side of door entered? 
    /*0x40*/ u16 unk40;
    /*0x42*/ s16 unk42;
    /*0x44*/ char unk44[0x4];
    /*0x48*/ void* PlayerMainData;
}PlayerMainData;

typedef struct {
             PosRot posrot;
             Vec3f speed;
             f32 scale;
             f32 shadowScale;
             Vec3f shadowRot;
             f32 unk38;
             f32 unk3C;
             f32 unk40;
             f32 unk44;
             f32 unk48;
             f32 unk4C;
             s16 unk50;
             s16 currentAnimID;
             u16 currentAnimFrame;
             u16 totalAnimFrames;
             u16 animFramerate;
             s16 unk5A;
             u16 unk5C;
             s16 unk5E;
             u16 unk60;
             u16 unk62;
             PlayerMainData* playerMainData;
             void* playerStatusPtr;
             u8 status[7];
}PlayerPosData;

//symbols
extern SaveSpawnLocation gSaveSpawnLocationTbl[17];
extern unk80085368 D_80085368;
extern PlayerMainData gPlayerMainData;
extern PlayerPosData gPlayerData1;

//functions
void func_80002EA0(void);

#endif
