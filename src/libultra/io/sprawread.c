#include <os_internal.h>
#include <rcp.h>
#include "os/osint.h"


//#pragma GLOBAL_ASM("asm/nonmatchings/io/sprawread/__osSpRawReadIo.s")
s32 __osSpRawReadIo(u32 devAddr, u32* data) {
    
    if (__osSiDeviceBusy()) {
        return -1;
    }

    *data = IO_READ(devAddr);
    return 0;
}
