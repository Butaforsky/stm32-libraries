#include "kexti.h"

void init(GPIO_TypeDef *port, uint16_t pin)
{
  // Enable AFIO clock
  RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
  // Enable GPIO clock
  switch (port)
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
 }
 //unlock EXTI interrupt

}
