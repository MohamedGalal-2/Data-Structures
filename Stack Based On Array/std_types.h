#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_

#include <stdio.h>

#define ZERO_INIT 0
#define ZERO      0

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef char sint8_t;
typedef short sint16_t;
typedef int sint32_t;
typedef long long sint64_t;

typedef enum return_status
{
	R_NOK,
	R_OK
}return_status_t;


#endif // _STD_TYPES_H_