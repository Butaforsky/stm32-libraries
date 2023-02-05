/**
 * @brief add short typedefs for 
 * 
 * i8-16-32,
 * u8-16-32, 
 * volatile u8-16-32,
 * volatile i8-16-32,
 * const u8-16-32,
 * const i8-16-32,
 * 
 */

#ifndef __SHORT_TYPES_H
#define __SHORT_TYPES_H
/* includes */
#include "main.h"

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

typedef int32_t i32;
typedef int16_t i16;
typedef int8_t i8;

typedef const uint32_t uc32;
typedef const uint16_t uc16;
typedef const uint8_t uc8;

typedef const int32_t ic32;
typedef const int16_t ic16;
typedef const int8_t ic8;

typedef __IO uint32_t vu32;
typedef __IO uint16_t vu16;
typedef __IO uint8_t vu8;

typedef __IO int32_t vi32;
typedef __IO int16_t vi16;
typedef __IO int8_t vi8;

#endif
