/**
 *
 * @brief Api for kitty board
 * @author butaforsky
 * @version 0.1.0
 */

#include "kled.h"
#include "short_types.h"

/* User defines */

/* User enums */

/* User structs */

/* User typedefs */

/* User variables */

/* User functions */
void LED::init(GPIO_TypeDef *port, uint16_t pin)
{
  LED::port = port;
  LED::pin = pin;
}

void LED::on()
{
  HAL_GPIO_WritePin(LED::port, LED::pin, GPIO_PIN_SET);
}

void LED::off()
{
  HAL_GPIO_WritePin(LED::port, LED::pin, GPIO_PIN_RESET);
}

void LED::toggle()
{
  HAL_GPIO_TogglePin(LED::port, LED::pin);
}