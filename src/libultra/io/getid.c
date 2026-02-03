#include "PRinternal/macros.h"
#include "PR/os_internal.h"
#include "PR/os_version.h"
#include "PRinternal/controller.h"
#include "PR/rmon.h"

s32 __osGetID(OSPfs *pfs) {
    s32 i;
    u16 sum;
    u16 isum;
    u8 temp[BLOCKSIZE];
    __OSPackId newid;
    s32 ret;
    __OSPackId *id;

    if (pfs->activebank != 0) {
        pfs->activebank = 0;
        ERRCK(__osPfsSelectBank(pfs));
    }
    
    ERRCK(__osContRamRead(pfs->queue, pfs->channel, PFS_ID_0AREA, (u8*)temp));
    __osIdCheckSum((u16*)temp, &sum, &isum);
    id = (__OSPackId*)temp;

    if (id->checksum != sum || id->inverted_checksum != isum) {
        ret = __osCheckPackId(pfs, id);
        
        if (ret == PFS_ERR_ID_FATAL) {
            ERRCK(__osRepairPackId(pfs, id, &newid));
            id = &newid;
        } else if (ret != 0) {
            return ret;
        }
    }

    if ((id->deviceid & 1) == 0) {
        ERRCK(__osRepairPackId(pfs, id, &newid));
        id = &newid;
        
        if ((id->deviceid & 1) == 0) {
            return PFS_ERR_DEVICE;
        }
    }
    
    //for loop becomes //bcopy(id, pfs->id, BLOCKSIZE); in new revisions
    for (i = 0; i < BLOCKSIZE; i++) {
        pfs->id[i] = ((u8*)id)[i];
    }

    
    
    pfs->version = id->version;
    pfs->banks = id->banks;
    pfs->inode_start_page = 1 + DEF_DIR_PAGES + (2 * pfs->banks);
    pfs->dir_size = 16;
    pfs->inode_table = PFS_ONE_PAGE;
    pfs->minode_table = (1 + pfs->banks) * PFS_ONE_PAGE;
    pfs->dir_table = pfs->minode_table + pfs->banks * PFS_ONE_PAGE;
    ERRCK(__osContRamRead(pfs->queue, pfs->channel, PFS_LABEL_AREA, pfs->label));
    return 0;
}
