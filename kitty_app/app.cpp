#include "app.h"
#include "main.h"
// kitty includes
#include "adc.h"
#include "kled.h"
#include "ktim.h"
#include "kuart.h"

#include "cnc.h"

#include "stdio.h"
#include "string.h"

extern ADC_HandleTypeDef hadc1;

UART debug, debug2;
LED blink, blink2, blink3;
timer blueLED, greenLED, redLED;
u16 ticks = 0;
u8 flag = 0;
u8 rx[11] = {
    0,
};
char tx[11] = {
    0,
};

volatile u16 adc_val = 0;

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
  blueLED.set_duty(timer::CH2, 40);
  blueLED.start(timer::PWMN);

  greenLED.init(&htim1, timer::PWMN, timer::CH1);
  greenLED.set_period(5000);
  greenLED.set_duty(timer::CH1, 40);
  greenLED.start(timer::PWMN);

  debug2.await_async(rx, sizeof(rx));
  debug2.send((u8 *)"lox\r\n");
  debug2.send((u8 *)blink2.on());
  debug2.send((u8 *)tx);

  HAL_ADC_Start(&hadc1);
  HAL_UART_Receive_IT(&huart3, rx, 11);
}

void app(void)
{
    blink.toggle();
    if (flag == 1)
    {
      blink2.toggle();
      parse_modbus(rx);
      flag = 0;
      HAL_UART_Receive_IT(&huart3, rx, 11);
    }
    osDelay(1000);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if (huart->Instance == USART3)
  {
    flag = 1;
  }
}


