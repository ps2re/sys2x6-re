
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

int start(int argc, char **argv)
{
    int x;
    iop_thread_t T;

    CpuEnableIntr();
    T.attr = 0x2000000;
    T.func = sec_checker;
    T.priority = 0x7e;
    T.stacksize = 0x800;
    T.option = 0;
    x = CreateThread(&T);
    if (x >= 1) {
        StartThread(x, 0);
    }
    return x < 1;
}

void sec_checker(void)
{
    int x;
    printf("check card routine start\n");
    do {
        McDetectCard2(0, 0);
        x = 0x3c;
        while (0 < x) {
            DelayThread(1000000);
            x = x + -1;
        }
    } while (true);
}
