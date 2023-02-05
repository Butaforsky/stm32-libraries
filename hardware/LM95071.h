#ifndef __LM_H__
#define __LM_H__

/**
 * 
 * @brief LM95071 SPI Temperature sensor library for STM32 
    
    Tested conditions:
    
    Frame Format: Motorola
    Data Size: 8 bits
    First bit: MSB First
    
    CPOL: HIGH
    CPHA: 2 Edge
    Prescaler: 256 (BaudRate = 125 KBits/s)

    If CS ACTIVE LOW, select it in 28 row define
    
 * @author butaforsky, mgostev.it@gmail.com
 * @version 0.1.0
 */

#include "main.h"
#include "short_types.h"
#include "spi.h"
/* User defines */
#define CHIP_SELECT_ACTIVE_LOW 0
/* User enums */

/* User structs */

/* User typedefs */
typedef struct LM95071
{
  u8 command[2];
  u8 data[2];
  GPIO_TypeDef* cs_port;
  u16 cs_pin;
  SPI_HandleTypeDef* hspi;
  u16 timeout_ms;
  float temperature;
  
} LM95071_t;
/* User variables */

/* User functions */
float LM95071_get_temp(LM95071_t *sensor, u32 cs_inverse);





#endif
