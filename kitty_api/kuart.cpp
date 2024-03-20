#include "kuart.h"
#include "string.h"

void UART::init(UART_HandleTypeDef *huart)
{
  this->huart = huart;
}

void UART::send(uint8_t *data)
{
  HAL_UART_Transmit(huart, data, strlen((char *)data), HAL_MAX_DELAY);
}
