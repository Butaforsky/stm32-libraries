#ifndef  __CNC_H__
#define  __CNC_H__

#include "main.h"
#include "kuart.h"

typedef enum modbus_commands
{
    COM_SET_MOTOR_POS,
    COM_SET_MOTOR_DIR,
    COM_SET_MOTOR_SPEED,
    COM_SET_MOTOR_ACC,
    COM_SET_MOTOR_DEC,
    COM_GET_MOTOR_POS,
    COM_GET_MOTOR_DIR,
    COM_GET_MOTOR_SPEED,
    COM_GET_MOTOR_ACC,
    COM_GET_MOTOR_DEC,
} COM;

class motor
{
    GPIO_TypeDef *dir_port;
    uint16_t dir_pin;

    TIM_HandleTypeDef *step_tim;
    uint32_t step_tim_ch;
    uint32_t step_tim_period;
};

class cnc
{
    motor motorX;
    motor motorY;
    motor motorZ;
};


void parse_modbus(u8 *rx);

#endif //__CNC_H

