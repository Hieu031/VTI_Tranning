#ifndef MPU_ADDRESS_H
#define MPU_ADDRESS_H

#include <stdint.h>
#include "BasicTypes.h"

#define MPU_BASE        (0xE000ED90UL)    /*!< MPU Base Address */
#define MPU             ((MPU_Type *) MPU_BASE)

typedef struct
{
  volatile uint32_t TYPE;      /*!< Offset: 0x000 (R/ )  MPU Type Register */
  volatile uint32_t CTRL;      /*!< Offset: 0x004 (R/W)  MPU Control Register */
  volatile uint32_t RNR;       /*!< Offset: 0x008 (R/W)  MPU Region Number Register */
  volatile uint32_t RBAR;      /*!< Offset: 0x00C (R/W)  MPU Region Base Address Register */
  volatile uint32_t RASR;      /*!< Offset: 0x010 (R/W)  MPU Region Attribute and Size Register */
  volatile uint32_t RBAR_A1;   /*!< Offset: 0x014 (R/W)  Alias 1 */
  volatile uint32_t RASR_A1;   /*!< Offset: 0x018 (R/W)  Alias 1 */
  volatile uint32_t RBAR_A2;   /*!< Offset: 0x01C (R/W)  Alias 2 */
  volatile uint32_t RASR_A2;   /*!< Offset: 0x020 (R/W)  Alias 2 */
  volatile uint32_t RBAR_A3;   /*!< Offset: 0x024 (R/W)  Alias 3 */
  volatile uint32_t RASR_A3;   /*!< Offset: 0x028 (R/W)  Alias 3 */
} MPU_Type;

#endif  /* MPU_ADDRESS_H */
