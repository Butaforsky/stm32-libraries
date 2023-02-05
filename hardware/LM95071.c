/**
 * 
 * @brief LM95071 SPI Temperature sensor
    Tested conditions:
    
    Frame Format: Motorola
    Data Size: 8 bits
    First bit: MSB First
    
    CPOL: HIGH
    CPHA: 2 Edge
    Prescaler: 256 (BaudRate = 125 KBits/s) 
 * @author butaforsky
 * @version 0.1.0
 */

#include "lm.h"
#include "short_types.h"
#include "spi.h"

/* User defines */

/* User enums */

/* User structs */

/* User typedefs */

/* User variables */
LM95071_t lm_temp_sensor = 
{ 
  .hspi = &hspi1,
  .cs_port = GPIOB,
  .cs_pin = GPIO_PIN_4,
  .timeout_ms = 100,
  .data = {0,}
};

/* User functions */

float LM95071_get_temp(LM95071_t *sensor, u32 cs_inverse)
{
#if CHIP_SELECT_ACTIVE_LOW == 1
  HAL_GPIO_WritePin(sensor->cs_port, sensor->cs_pin, GPIO_PIN_SET);
#else
  HAL_GPIO_WritePin(sensor->cs_port, sensor->cs_pin, GPIO_PIN_SET);
#endif
  HAL_SPI_Receive(sensor->hspi, sensor->data, 2, sensor->timeout_ms);
  HAL_SPI_Transmit(sensor->hspi, sensor->command, 2, sensor->timeout_ms);
#if CHIP_SELECT_ACTIVE_LOW == 1
  HAL_GPIO_WritePin(sensor->cs_port, sensor->cs_pin, GPIO_PIN_SET);
#else
  HAL_GPIO_WritePin(sensor->cs_port, sensor->cs_pin, GPIO_PIN_RESET);
#endif
  
  u16 temp = (sensor->data[0] << 8) + sensor->data[1]; 
  temp = temp >> 2;  // according to datasheet, 0 and 1 bits are always 1
  sensor->temperature = (float)temp * 0.03125; // 0.03125 is a LSB resolution
  
  return sensor->temperature;
  
}  


