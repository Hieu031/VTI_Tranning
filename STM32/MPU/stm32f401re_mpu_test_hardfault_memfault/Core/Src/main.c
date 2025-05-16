/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#include <stdint.h>
#include "BasicTypes.h"
#include "MPU_Address.h"
#include "SCB_Address.h"

int a = 1; // set a variable to test HardFault

int main(){
	/* Region 0 */
	MPU->RNR = 0; // Region Number 0 - set bit = 0 to determine REgion Number
	MPU->RBAR = 0x00; // Start Address - bit 0 set 0
	MPU->RASR |= (0b11111 << 1); // Size - bit 5:1
	MPU->RASR |= (0b011 << 24); // Full Access - bit 26:24
	// bit [21:19, 17, 16] set 0 (default) as Strongly-ordered memory type
	MPU->RASR |= (0b1UL << 0); // Enable Region - bit 0 set 0 to enable Region

	/* Region 1 */
	MPU->RNR = 1;
	MPU->RBAR = 0x40000000;
	MPU->RASR |= (0b01001 << 1); // Size 1KB - bit 5:1
	MPU->RASR |= (0b001000 << 16); // Normal nonCache - bit 21:16
	MPU->RASR |= (0b111 << 24); // Read only - bit 26:24
	MPU->RASR |= (0b1UL << 0); //Enable Region - bit 0

	/* Set MemFault Handler */
	SCB->SHCSR |= (0b0UL << 16); // set bit 16 to 1 to enable MemManage
	/*
	 * When enable this bit of SCB register to when write to Read Only Memory
	 * Program will jump to MemFault_Handler
	*/

	/* Enable MPU */
	MPU->CTRL |= (0b1UL << 0); // set bit 0 to enable MPU

	/* Write to Read Only Memory */
	*(uint32_t *) (0x40000000UL) = 0xDEADBEEF; // Get Fault

	while (1);
}

void HardFault_Handler(void){
	a = 2;
}

void MemManage_Handler(void){
	a = 3;
}
