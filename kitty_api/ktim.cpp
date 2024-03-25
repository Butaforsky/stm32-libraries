#include "ktim.h"

void timer::init(TIM_HandleTypeDef *tim, timer::MODE mode, timer::CHANNEL channel)
{
  timer::_init = true;
  htim = tim;
  if (mode == timer::MODE::PWM || mode == timer::MODE::PWMN)
  {
    switch (channel)
    {
    case timer::CH1:
      timer::channel = TIM_CHANNEL_1;
      break;
    case timer::CH2:
      timer::channel = TIM_CHANNEL_2;
      break;
    case timer::CH3:
      timer::channel = TIM_CHANNEL_3;
      break;
    case timer::CH4:
      timer::channel = TIM_CHANNEL_4;
      break;
    default:
      break;
    }
  }
}

void timer::start(timer::MODE mode)
{
  switch (mode)
  {
  case timer::MODE::BASIC:
    HAL_TIM_Base_Start(timer::htim);
    break;
  case timer::MODE::PWM:
    HAL_TIM_PWM_Start(timer::htim, timer::channel);
    break;
  case timer::MODE::PWMN:
    HAL_TIMEx_PWMN_Start(timer::htim, timer::channel);
    break;
  case timer::MODE::IT:
    HAL_TIM_Base_Start_IT(timer::htim);
    break;
  default:
    break;
  }
}

void timer::set_duty(timer::CHANNEL channel, uint16_t duty)
{
  u16 duty_cycle = (u16)(duty * (u16)timer::htim->Instance->ARR / 100);

  switch (channel)
  {
  case timer::CHANNEL::CH1:
    timer::htim->Instance->CCR1 = duty_cycle;
    break;
  case timer::CHANNEL::CH2:
    timer::htim->Instance->CCR2 = duty_cycle;
    break;
  case timer::CHANNEL::CH3:
    timer::htim->Instance->CCR3 = duty_cycle;
    break;
  case timer::CHANNEL::CH4:
    timer::htim->Instance->CCR4 = duty_cycle;
    break;
  default:
    break;
  }
}

void timer::set_period(uint32_t period)
{
  assert_param(timer::htim->Instance);
  timer::htim->Instance->ARR = period;
}