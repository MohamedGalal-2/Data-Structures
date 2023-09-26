#ifndef _DYNAMIC_STACK_DS_H_
#define _DYNAMIC_STACK_DS_H_

#include "..\std_types.h"

#define STACK_DEBUG 

typedef struct
{
	void** stack_Array;
	sint32_t element_Count;
	uint32_t stack_Max_Size;
	sint32_t stack_Top;
}stack_ds_t;

typedef enum
{
	STACK_NOK,
	STACK_OK,
	STACK_FULL,
	STACK_NOT_FULL,
	STACK_EMPTY,
	STACK_NOT_EMPTY,
	STACK_NULL_POINTER
}stack_status_t;

stack_ds_t* create_stack(uint32_t stack_Max_Size, stack_status_t* ret_status);

stack_ds_t* destroy_stack(stack_ds_t* stack_obj, stack_status_t* ret_status);

stack_status_t push_stack(stack_ds_t* stack_obj, void* data);

void* pop_stack(stack_ds_t* stack_obj, stack_status_t* ret_status);

void* top_stack(stack_ds_t* stack_obj, stack_status_t* ret_status);

stack_status_t stack_count(stack_ds_t* stack_obj, uint32_t* stack_count);

#endif  // _DYNAMIC_STACK_DS_H_