#include "common.h"

//#pragma GLOBAL_ASM("asm/nonmatchings/spsetstat/__osSpSetStatus.s")
void __osSpSetStatus(u32 data) {
    IO_WRITE(SP_STATUS_REG, data);
}