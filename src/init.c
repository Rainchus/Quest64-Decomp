#include "common.h"

void __osInitialize_common(void); /* extern */
void func_80000C50(void *);       /* extern */
void func_800004B0(void *);       /* extern */

extern OSThread D_80075040;
extern OSMesgQueue D_800781F0;
extern void *D_80078208;
extern OSThread D_80074E90;
extern s32 D_800761F0;

void func_80000450(s32 arg0)
{
    __osInitialize_common();
    osCreateThread(&D_80074E90, 1, func_800004B0, NULL, &D_800761F0, 1);
    osStartThread(&D_80074E90);
}

void func_800004B0(void *arg0)
{
    osCreatePiManager(OS_PRIORITY_PIMGR, &D_800781F0, &D_80078208, 0x32);
    osCreateThread(&D_80075040, 6, func_80000C50, arg0, &D_800781F0, 5);
    osStartThread(&D_80075040);
    for (;;); // Required to match 
}
