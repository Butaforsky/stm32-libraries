#include "kexti.h"

status_t init(GPIO_TypeDef *_port, uint16_t _pin, edge_t _edge)
{
  // Enable SYSCFG clock
  RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
  // Enable GPIO clock
  switch (_port)
  {
  case GPIOA:
    SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI0;
    break;
  case GPIOB:
    SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI1;
    break;
  case GPIOC:
    SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI2;
    break; 
  case GPIOD:
    SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI3;
    break;
  case GPIOE:
    SYSCFG->EXTICR[1] &= ~SYSCFG_EXTICR2_EXTI4;
    break;
  case GPIOF:
    SYSCFG->EXTICR[1] &= ~SYSCFG_EXTICR2_EXTI5;
    break;
  case GPIOG:
    SYSCFG->EXTICR[1] &= ~SYSCFG_EXTICR2_EXTI6;
    break;
  default: 
    return exti::STATUS_ERR;
    break;
 }



 //unlock EXTI interrupt

}
