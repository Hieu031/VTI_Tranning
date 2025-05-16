/*
 * mpu_driver.h
 *
 *  Created on: May 10, 2025
 *      Author: hieu.nguyentri
 */

#ifndef INC_MPU_DRIVER_H_
#define INC_MPU_DRIVER_H_

#include "stm32f4xx.h"

// Macro configure for MPU
#define MPU_ENABLE_DEFAULT_MEM		1
#define MPU_DISABLE_DEFAULT_MEM		0
#define MPU_ENABLE_IN_EXCEPTION		1
#define MPU_DISABLE_IN_EXCEPTION	0

// Memory Types
#define MPU_MEM_STRONG_ORDER		0x00
#define MPU_MEM_NORMAL_CACHEABLE	0x01
#define MPU_MEM_NORMAL_NONCACHE		0x02

// Access Rights
#define MPU_ACCESS_NO_ACCESS		0x00
#define MPU_ACCESS_FULL				0x03
#define MPU_ACCESS_READ_ONLY			0x05

// Fault Status (MMFSR bits)
#define MPU_FAULT_IACCVIOL			(1 << 0) // Instruction Access Violation
#define MPU_FAULT_DACCVIOL			(1 << 1) // Data Access VIolation
#define MPU_FAULT_MUNSTKERR			(1 << 3) //	Un-stacking Error
#define MPU_FAULT_MSTKERR			(1 << 4) // Stacking Error
#define MPU_FAULT_MLSPERR			(1 << 5) // Lazy State Preservation Error
#define MPU_FAULT_MMARVALID			(1 << 7) // MMFAR Valid

// Structure for MPU REgion
typedef struct{
	uint8_t  RegionNumber;      // 0-7
	uint32_t StartAddress;      // start address (aligned)
	uint8_t  Size;              // SIZE field (log2(size) - 1)
	uint8_t  MemoryType;        // Strong Order, Normal Cache-able, NonCacheable
	uint8_t  AccessRight;       // access authorize
	uint8_t  Enable;            // 1: Enable, 0: Disable
} MPU_RegionConfig_t;

// Structure for overview MPU
typedef struct{
	uint8_t EnableDefaultMem; 	// MPU_CTRL.PRIVDEFENA
	uint8_t EnableInException; 	// MPU_CTRL.HFNMIENA
	uint8_t EnableMemManage;	// Enable MemManage Fault
	MPU_RegionConfig_t* Regions;// Array regions
	uint8_t RegionCount; 		// Number regions
} MPU_Config_t;

// Function driver
void MPU_Init(MPU_Config_t* config);	// Function initialize and configure for MPU
void MPU_DeInit(void); 					// Re-Initialize MPU
void MPU_SetRegionConfig(MPU_RegionConfig_t* Regions);
//	Function re-set configure some part of MPU after Initialize
void MPU_GetErrorDetails(uint32_t* faultAddr, uint8_t* faultStatus); // Get error when error

#endif /* INC_MPU_DRIVER_H_ */
