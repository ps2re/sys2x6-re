
/***
 *       _______     _______ ___         __    _____  ______ 
 *      / ____\ \   / / ____|__ \       / /   |  __ \|  ____|
 *     | (___  \ \_/ / (___    ) |_  __/ /_   | |__) | |__
 *      \___ \  \   / \___ \  / /\ \/ / '_ \  |  _  /|  __|
 *      ____) |  | |  ____) |/ /_ >  <| (_) | | | \ \| |____
 *     |_____/   |_| |_____/|____/_/\_\\___/  |_|  \_\______|
 *
 *     System 246/256 software revenge engineering
 *     MIT Licensed
 */
#include "irx_imports.h"
#include "acdev.h"


extern struct irx_export_table _exp_acdev;
#define MODNAME "acdev"
IRX_ID(MODNAME, 1, 1);

int _start(int argc, char **argv)
{
    int x;
    unsigned int local_10[2];

    CpuSuspendIntr(local_10);
    x = RegisterLibraryEntries(&_exp_acdev);
    if (x == 0) {
        SetDelayFor0xaDevice(0x1a30ff);
        x = romAddDevice(1, 0xb0000000);
        if (x != 0) {
            Kprintf("Arcade ROM directory not found\n");
        }
        CpuResumeIntr(local_10[0]);
        return MODULE_RESIDENT_END;
    } else {
        CpuResumeIntr(local_10[0]);
        return MODULE_NO_RESIDENT_END;
    }
}

void SetDelayFor0xaDevice(unsigned int Delay)
{
    SetDelay(10, Delay); //romdrv import #4
    return;
}

void GetDelayFor0xaDevice(void)
{
    GetDelay(10); //romdrv import #5
    return;
}

void SetDelayFor0xbDevice(unsigned int Delay)
{
    SetDelay(0xb, Delay);
    return;
}

void GetDelayFor0xbDevice(void) //FUN_00000068
{
    GetDelay(0xb);
    return;
}
