#include "cmsis_os.h"

#include "short_types.h"
#include "main.h"

#include "cnc.h"

extern UART debug2;


void parse_modbus(u8 *rx)
{
  u16 command = (rx[0] << 8) | rx[1];
  u16 response = 1;
  switch (command)
  {
  case COM_SET_MOTOR_POS:
    rx[1] = 0xFF;
    rx[2] = response;
    HAL_UART_Transmit(&huart3, rx, 11, 100);
    break;
  
  default:
    rx[2] = 0x03;
    HAL_UART_Transmit(&huart3, rx, 11, 100);
    break;
  }
}