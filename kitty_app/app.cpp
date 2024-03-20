#include "app.h"
#include "main.h"
#include "kled.h"
 
LED blink, blink2;
 
extern "C" void app_loop(void) {
    app();
}

extern "C" void app_c(void) {
    app_init();
}

void app_init(void) {
    blink.init(GPIOB, GPIO_PIN_9);
    blink2.init(GPIOB, GPIO_PIN_5);
}

void app(void) {
    while (true) {
        blink.toggle();
        blink2.toggle();
        HAL_Delay(1000);
    }
}






