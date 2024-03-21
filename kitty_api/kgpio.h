#ifndef __INC_KGPIO_H__
#define __INC_KGPIO_H__

#include "main.h"
#include "short_types.h"

class gpio
{
  uint16_t mode;
  uint16_t speed;
  uint16_t pull;
  uint16_t port;
  uint16_t pin;
  uint8_t value;

public:
  enum SPEED
  {
    LOW = 0,
    MEDIUM = 1,
    HIGH = 2,
    VERY_HIGH = 3
  };

  enum PULL
  {
    NONE = 0,
    UP = 1,
    DOWN = 2
  };

  enum MODE
  {
    INPUT = 0,
    OUTPUT = 1,
    ALTERNATE = 2,
    ANALOG = 3
  };

  enum PORT
  {
    A = 0,
    B = 1,
    C = 2,
    D = 3,
    E = 4,
    F = 5,
    G = 6,
    H = 7
  };

  enum PIN
  {
    P0 = 0,
    P1 = 1,
    P2 = 2,
    P3 = 3,
    P4 = 4,
    P5 = 5,
    P6 = 6,
    P7 = 7,
    P8 = 8,
    P9 = 9,
    P10 = 10,
    P11 = 11,
    P12 = 12,
    P13 = 13,
    P14 = 14,
    P15 = 15
  };

  enum VALUE
  {
    LOW_VALUE = 0,
    HIGH_VALUE = 1
  };

  void init(GPIO_TypeDef port, gpio::PIN pin, gpio::VALUE state, gpio::MODE mode, gpio::SPEED speed, gpio::PULL pull);
};

#endif // !__INC_KGPIO_H__
