#ifndef __KITTY_API_LED_H__
#define __KITTY_API_LED_H__

/**
 * 
 * @brief Api for kitty board * 
 * @author butaforsky
 * @version 0.1.0
 */

#include "main.h"
#include "short_types.h"

/* User defines */

/* User enums */

/* User structs */

/* User typedefs */
class LED{
    GPIO_TypeDef *port;
    uint16_t pin;

    public:
        void init(GPIO_TypeDef *port, uint16_t pin);
        void on();
        void off();
        void toggle();
};
/* User variables */

/* User functions */






#endif
