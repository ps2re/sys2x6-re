
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
#ifndef __ACDEV_H
#define __ACDEV_H

void SetDelayFor0xaDevice(unsigned int Delay);
void GetDelayFor0xaDevice(void);
void SetDelayFor0xbDevice(unsigned int Delay);
void GetDelayFor0xbDevice(void);

#define acdev_IMPORTS_start DECLARE_IMPORT_TABLE(acdev, 1, 1)
#define acdev_IMPORTS_end END_IMPORT_TABLE

#define I_GetDelayFor0xaDevice DECLARE_IMPORT(4, SetDelayFor0xaDevice)
#define I_GetDelayFor0xaDevice DECLARE_IMPORT(5, GetDelayFor0xaDevice)
#define I_SetDelayFor0xbDevice DECLARE_IMPORT(6, SetDelayFor0xbDevice)
#define I_GetDelayFor0xbDevice DECLARE_IMPORT(7, GetDelayFor0xbDevice)
#endif