/**
 *
 * @brief Uart driver for kitty
 * @author butaforsky
 * @version 0.1.0
 */

#include "kitty_api_uart.h"
#include "short_types.h"

/* User defines */

/* User enums */

/* User structs */

/* User typedefs */
typedef struct UART_ADVANCED
{

}uart_advanced_params;

typedef struct UART
{
  u32 baudrate;
  u8 data_bits;
  u8 parity;
  u8 stop_bits;
  

  uart_advanced_params advanced;

} uart_t;


/* User variables */

/* User functions */
