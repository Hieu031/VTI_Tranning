#include <stdint.h> 

#define AHB1_BASE_ADDR  0x40020000                  // Base Address of bus AHB1 
#define RCC_BASE_ADDR   (AHB1_BASE_ADDR + 0x3800)   // RCC base address offset 0x3800 from AHB1
#define RCC_CR          (RCC_BASE_ADDR + 0x00)      // RCC clock control register offset 0x00
#define RCC_CFGR        (RCC_BASE_ADDR + 0x08)      // RCC clock configuration register offset 0x08 

void HSE_SystemClock(void){
    volatile uint32_t* pRCC_CR = (volatile uint32_t*)RCC_CR;        // pointer to RCC_CR
    volatile uint32_t* pRCC_CFGR = (volatile uint32_t*) RCC_CFGR;   //pointer to RCC_CFGR
    
    /* Set HSE is on */
    *pRCC_CR |= (1 << 16);              //set bit 16 (HSEON) of RCC_CR is 1 to enable
    while (!(*pRCC_CR & (1 << 17)));    // Wait HSERDY (bit 17) = 1 for HSE clock is stable

    /* Set HSE as System Clock */
    *pRCC_CFGR &= ~(3 << 0);                        // CLear bit SW[1:0]
    *pRCC_CFGR |= (1 << 0);                         //SW = 01: Choose HSE as SYSCLK
    while ((*pRCC_CFGR & (3 << 2)) != (1 << 2));    // Wait SWS = 01 (SYSCLK switch to HSE) 
}