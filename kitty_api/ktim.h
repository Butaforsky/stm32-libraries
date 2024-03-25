#ifndef __KITTY_API_TIM_H__
#define __KITTY_API_TIM_H__

/**
 *
 * @brief Api for kitty board *
 * @author butaforsky
 * @version 0.1.0
 */

#include "main.h"
#include "short_types.h"

#include "tim.h"
/* User defines */

/* User enums */

/* User structs */

/* User typedefs */

/* User variables */

/* User functions */
class timer
{
  bool _init = false;
  u16 channel;
  TIM_HandleTypeDef *htim;

public:
  enum MODE
  {
    BASIC,
    PWM,
    PWMN,
    IT,
  };
  enum CHANNEL
  {
    CH1,
    CH2,
    CH3,
    CH4,
  };

  void init(TIM_HandleTypeDef *tim, timer::MODE mode, timer::CHANNEL channel);
  void start(timer::MODE mode);
  void set_duty(timer::CHANNEL channel, uint16_t duty);
  void set_period(uint32_t period);
};

#endif