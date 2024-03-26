/**
 *
 * @brief Api for kitty board
 * @author butaforsky
 * @version 0.1.0
 */

#include "kled.h"
#include "short_types.h"
#include "string.h"

/* User includes */

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

int  LED::on()
{
  if (LED::port != NULL || LED::pin != 0)
  {
    HAL_GPIO_WritePin(LED::port, LED::pin, GPIO_PIN_SET);
    return 0;
  }
  else{
    return 1;
  }
}

void LED::off()
{
  HAL_GPIO_WritePin(LED::port, LED::pin, GPIO_PIN_RESET);
}

void LED::toggle()
{
  HAL_GPIO_TogglePin(LED::port, LED::pin);
}

char *LED::info()
{
  char *info = new char[100];
  LED::port == GPIOA ? strcpy(info, "GPIOA") : strcpy(info, "GPIOB");
  LED::pin == GPIO_PIN_0 ? strcat(info, "0") : strcat(info, "1");
  return info;
}
