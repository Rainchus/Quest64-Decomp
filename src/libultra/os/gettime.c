#include "PR/os_internal.h"
#include "PR/ultraerror.h"
#include "os/osint.h"
#include "PR/viint.h"

OSTime osGetTime() {
    u32 tmptime;
    u32 elapseCount;
    OSTime currentCount;
    register u32 saveMask;


    saveMask = __osDisableInt();
    tmptime = osGetCount();
    elapseCount = tmptime - __osBaseCounter;
    currentCount = __osCurrentTime;
    __osRestoreInt(saveMask);
    return currentCount + elapseCount;
}