#include "app.h"
#include "main.h"
// kitty includes
#include "kled.h"
#include "ktim.h"
#include "kuart.h"

UART debug, debug2;
LED blink, blink2;
timer blueLED, greenLED;
u16 ticks;

extern "C" void app_loop(void)
{
  app();
}

extern "C" void app_c(void)
{
  app_init();
}

void app_init(void)
{
  debug.init(&huart2);
  debug2.init(&huart3);

  blink.init(GPIOB, GPIO_PIN_9);
  blink2.init(GPIOB, GPIO_PIN_5);

  blueLED.init(&htim1, timer::PWMN, timer::CH2);
  blueLED.set_period(5000);
  blueLED.set_duty(timer::CH2, 4);
  blueLED.start(timer::PWMN);

  greenLED.init(&htim1, timer::PWMN, timer::CH3);
  greenLED.set_period(5000);
  greenLED.set_duty(timer::CH3, 4);
  greenLED.start(timer::PWMN);
}

void app(void)
{
  while (true)
  {
    blink.toggle();
    blink2.toggle();
    debug.send((u8 *)"Hello World!\n");
    debug2.send((u8 *)"Hello World!\n");
    HAL_Delay(1000);
    blueLED.set_duty(timer::CH2, ticks);
    greenLED.set_duty(timer::CH3, ticks);
    ticks++;
    if (ticks > 100)
    {
      ticks = 0;
    }
  }
}
