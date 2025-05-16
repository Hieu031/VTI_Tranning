/*
 * mpu_driver.c
 *
 *  Created on: May 10, 2025
 *      Author: hieu.nguyentri
 */

#include "mpu_driver.h"

void MPU_Init(MPU_Config_t* config) {
    MPU->CTRL &= ~MPU_CTRL_ENABLE_Msk;
    for (uint8_t i = 0; i < config->RegionCount; i++) {
        MPU_RegionConfig_t* region = &config->Regions[i];
        MPU->RNR  = region->RegionNumber;
        MPU->RBAR = region->StartAddress;
        MPU->RASR = (region->Size << MPU_RASR_SIZE_Pos) |
                    (region->AccessRight << MPU_RASR_AP_Pos) |
                    (region->MemoryType == MPU_MEM_STRONG_ORDER ? (0x2 << MPU_RASR_TEX_Pos) :
                     region->MemoryType == MPU_MEM_NORMAL_CACHEABLE ? (0x1 << MPU_RASR_TEX_Pos) | MPU_RASR_C_Msk :
                     (0x1 << MPU_RASR_TEX_Pos)) |
                    (region->Enable ? MPU_RASR_ENABLE_Msk : 0);
    }
    uint32_t ctrl = 0;
    if (config->EnableDefaultMem) ctrl |= MPU_CTRL_PRIVDEFENA_Msk;
    if (config->EnableInException) ctrl |= MPU_CTRL_HFNMIENA_Msk;
    ctrl |= MPU_CTRL_ENABLE_Msk;
    MPU->CTRL = ctrl;
    if (config->EnableMemManage) NVIC_EnableIRQ(MemoryManagement_IRQn);
    __DSB();
    __ISB();
}

void MPU_DeInit(void) {
    MPU->CTRL = 0;
    for (uint8_t i = 0; i < 8; i++) {
        MPU->RNR = i;
        MPU->RBAR = 0;
        MPU->RASR = 0;
    }
    __DSB();
    __ISB();
}

void MPU_SetRegionConfig(MPU_RegionConfig_t* region) {
    // CHeck valid regions numbers (0-7)
    if (region->RegionNumber > 7) return;

    // Disable MPU before initialize to avoid conflict
    uint32_t ctrl = MPU->CTRL;
    MPU->CTRL &= ~MPU_CTRL_ENABLE_Msk;

    // Configure Region
    MPU->RNR  = region->RegionNumber;
    MPU->RBAR = region->StartAddress;
    MPU->RASR = (region->Size << MPU_RASR_SIZE_Pos) |
                (region->AccessRight << MPU_RASR_AP_Pos) |
                (region->MemoryType == MPU_MEM_STRONG_ORDER ? (0x2 << MPU_RASR_TEX_Pos) :
                 region->MemoryType == MPU_MEM_NORMAL_CACHEABLE ? (0x1 << MPU_RASR_TEX_Pos) | MPU_RASR_C_Msk :
                 (0x1 << MPU_RASR_TEX_Pos)) |
                (region->Enable ? MPU_RASR_ENABLE_Msk : 0);

    // Restore status MPU
    MPU->CTRL = ctrl;
    __DSB();
    __ISB();
}

void MPU_GetErrorDetails(uint32_t* faultAddr, uint8_t* faultStatus) {
    *faultAddr = SCB->MMFAR;   // Address get fault
    *faultStatus = SCB->CFSR & 0xFF; // Error status (MMFSR)

    // Delete error flag after read data
    SCB->CFSR |= SCB->CFSR & 0xFF;
}

