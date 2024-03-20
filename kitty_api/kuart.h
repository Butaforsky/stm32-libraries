#ifndef __KITTY_API_UART_H__
#define __KITTY_API_UART_H__

/**
 *
 * @brief Uart driver for kitty *
 * @author butaforsky
 * @version 0.1.0
 */

#include "main.h"
#include "short_types.h"
#include "stdbool.h"
#include "usart.h"

/* User defines */

/* User enums */

/* User structs */
class UART
{
  UART_HandleTypeDef* huart;
  uint32_t pin;

public:
  void init(UART_HandleTypeDef* huart);
  void send(uint8_t* data);
};
/* User typedefs */

/* User variables */

/* User functions */

#endif
