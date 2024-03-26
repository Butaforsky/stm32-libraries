#include "kuart.h"
#include "string.h"

void UART::init(UART_HandleTypeDef *huart)
{
  this->huart = huart;
}

void UART::send(uint8_t *data)
{
  if(this->huart != NULL)
  HAL_UART_Transmit(this->huart, data, strlen((char *)data), 1000);
  else{
    Error_Handler();
  }
}

void UART::await_async()
{
  HAL_UART_Receive_IT(this->huart, this->rx, 1);
}
