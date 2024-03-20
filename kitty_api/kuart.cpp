#include "kuart.h"

void UART::init(UART_HandleTypeDef *huart)
{
    this->huart = huart;
}