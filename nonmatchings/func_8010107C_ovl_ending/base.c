typedef unsigned short u16;
typedef short s16;
typedef long s32;
typedef float f32;
typedef struct 
{
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
} unk80156fe8_s;
extern unk80156fe8_s D_80156FE8[];
s32 func_8010107C_ovl_ending(s32 arg0, s32 arg1)
{
  unk80156fe8_s *temp_v0 = &D_80156FE8[arg0];
  if (!(temp_v0->unk0 & 0x80000000))
  {
    return 0;
  }
  temp_v0->unk32++;
  temp_v0->unk48 += 255.0f / ((f32) temp_v0->unk38);
  if ((temp_v0->unk48 >= 255.0f) || ((temp_v0->unk32 & 0xFFFF) >= temp_v0->unk38))
  {
    temp_v0->unk48 = 255.0f;
  }
  temp_v0->unk4E = (s16) ((arg1 == 0) ? (temp_v0->unk48) : (255.0f - temp_v0->unk48));
  if (((s32) temp_v0->unk32) >= temp_v0->unk38)
  {
    temp_v0->unk32 = 0;
    temp_v0->unk48 = 0.0f;
    temp_v0->unk4E = (arg1 == 0) ? (0xFF) : (0);
    return 0xFF;
  }
  return 0;
}

