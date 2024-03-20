#include "main.h"
#include "kgpio.h"

void init(GPIO_TypeDef port, gpio::PIN pin, gpio::MODE mode, gpio::SPEED speed, gpio::PULL pull)
{   
    port.MODER = (port.MODER & ~(0b11 << (pin * 2))) | (mode << (pin * 2));
    port.OSPEEDR = (port.OSPEEDR & ~(0b11 << (pin * 2))) | (speed << (pin * 2));
    port.PUPDR = (port.PUPDR & ~(0b11 << (pin * 2))) | (pull << (pin * 2));
    port.BSRR = (1 << pin);
    port.ODR = (1 << pin);
}
