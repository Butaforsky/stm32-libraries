#include "kexti.h"

status_t init(GPIO_TypeDef *_port, uint16_t _pin, edge_t _edge)
{
  // Enable SYSCFG clock
  RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
  // Enable GPIO clock
 //unlock EXTI interrupt
  return status_t::STATUS_OK;

}
