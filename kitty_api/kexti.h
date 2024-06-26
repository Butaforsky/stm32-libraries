#include "main.h"

typedef enum
{
  RISING_EDGE,
  FALLING_EDGE,
  RISING_FALLING_EDGE
} edge_t;

typedef enum
{
  STATUS_ERR,
  STATUS_OK,
  STATUS_EMPTY,
  STATUS_TIMEOUT,

} status_t;
class exti
{
  GPIO_TypeDef *port;
  uint16_t pin;
  edge_t edge;

public:
  status_t init(GPIO_TypeDef *_port, uint16_t _pin, edge_t _edge);
};
