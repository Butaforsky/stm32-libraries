#include "main.h"

class exti
{
  typedef enum
  {
    RISING_EDGE,
    FALLING_EDGE,
    RISING_FALLING_EDGE
  } edge_t;

  GPIO_TypeDef *port;
  uint16_t pin;
  edge_t edge;

public:
  typedef enum
  {
    STATUS_ERR,
    STATUS_OK,
    STATUS_EMPTY,
    STATUS_TIMEOUT,

  } status_t;

  status_t init(GPIO_TypeDef *_port, uint16_t _pin, edge_t _edge);
}
