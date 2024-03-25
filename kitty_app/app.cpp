#include "app.h"
#include "main.h"
// kitty includes
#include "kled.h"
#include "ktim.h"
#include "kuart.h"
#include "string.h"
UART debug, debug2;
LED blink, blink2, blink3;
timer blueLED, greenLED, redLED;
u16 ticks = 0;
u8 flag = 0;

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
  char tx[100];
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

  debug2.await_async();
  debug2.send((u8 *)"lox\r\n");
  debug2.send((u8*)blink2.on());
  memcpy(tx, blink3.info(), 100);
  debug2.send((u8 *)tx);
}

void app(void)
{
  while (true)
  {
    blink.toggle();
    blink2.toggle();

    HAL_Delay(100);
    blueLED.set_duty(timer::CH2, ticks);
    greenLED.set_duty(timer::CH3, ticks);
    ticks++;
    if (ticks > 50)
    {
      ticks = 0;
    }
    if (flag == 1)
    {
      flag = 0;
      blueLED.set_duty(timer::CH2, 1);
      debug2.send((u8 *)"lox\r\n");
      debug2.await_async();
    }
  }
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if (huart->Instance == USART3)
  {
    flag = 1;
  }
}
