#include "main.h"


class exti
{
    GPIO_TypeDef *port;
    uint16_t pin;

    public:
    void init(GPIO_TypeDef *port, uint16_t pin);

}
