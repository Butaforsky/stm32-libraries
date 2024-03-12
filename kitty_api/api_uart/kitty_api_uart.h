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
#include "stdbool"

/* User defines */

/* User enums */
typedef enum UART_PARITY
{
  UART_PARITY_NONE = 0,
  UART_PARITY_EVEN,
  UART_PARITY_ODD
} UART_PARITY;

static typedef enum UART_MODE
{
  UART_MODE_RX,
  UART_MODE_TX,
  UART_MODE_RXTX,
} UART_MODE;
/* User structs */

/* User typedefs */

/* User variables */

/* User functions */

#endif
