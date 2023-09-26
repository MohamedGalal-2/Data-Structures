#ifndef _DYNAMIC_STACK_DS_H_
#define _DYNAMIC_STACK_DS_H_

#include "..\std_types.h"

#define STACK_DEBUG 

typedef struct
{
	void** stack_Array;       /* Points to the array that allocated in the heap */
	sint32_t element_Count;   /* Has the actual number of elements in the stack */
	uint32_t stack_Max_Size;  /* Has the maximum number of elements in the stack */
	sint32_t stack_Top;       /* Has the index of the top element in the stack */
}stack_ds_t;

typedef enum
{
	STACK_NOK,            /* Stack operation not performed successfully */
	STACK_OK,             /* Stack operation performed successfully  */
	STACK_FULL,           /* Stack is full */
	STACK_NOT_FULL,       /* Stack is full */
	STACK_EMPTY,		  /* Stack is empty */
	STACK_NOT_EMPTY,      /* Stack is empty */
	STACK_NULL_POINTER    /* NULL pointer passed to the Stack operations */
}stack_status_t;

/**
  * @brief  This algorithm creates an empty stack by allocating the head
			structure and the array from dynamic memory.
  * @param  ret_status      Status returned while performing this operation
  * @param  stack_Max_Size  Stack maximum number of elements
  * @return Pointer to the allocated stack in the heap
  */
stack_ds_t* create_stack(uint32_t stack_Max_Size, stack_status_t* ret_status);

/**
  * @brief  This algorithm destroys the stack by freeing the head structure
			and the array from dynamic memory.
  * @param  ret_status  Status returned while performing this operation
  * @param  stack_obj   Pointer to the stack to be destroyed
  * @return NULL
  */
stack_ds_t* destroy_stack(stack_ds_t* stack_obj, stack_status_t* ret_status);

/**
  * @brief  This function pushes an item onto the stack.
  * @param  stack_obj  Pointer to the stack to be pushed to
  * @param  data       Pointer to the data to be pushed to the stack
  * @return the status while performing this operation
  */
stack_status_t push_stack(stack_ds_t* stack_obj, void* data);

/**
  * @brief  This algorithm pops an element from the stack.
  * @param  ret_status  Status returned while performing this operation
  * @param  stack_obj   Pointer to the stack to be popped from
  * @return Pointer to the popped data
  */
void* pop_stack(stack_ds_t* stack_obj, stack_status_t* ret_status);

/**
  * @brief  This function retrieves the data from the top of the
			stack without changing the stack.
  * @param  stack_obj   Pointer to stack head structure
  * @param  ret_status  Status returned while performing this operation
  * @retval Pointer to user data if successful, NULL if underflow
  */
void* top_stack(stack_ds_t* stack_obj, stack_status_t* ret_status);

/**
  * @brief  This algorithm returns the number of elements in the stack.
  * @param  ret_status  Status returned while performing this operation
  * @param  stack_obj   Pointer to the stack to be counted
  * @return Status returned while performing this operation
  */
stack_status_t stack_count(stack_ds_t* stack_obj, uint32_t* stack_count);

#endif  // _DYNAMIC_STACK_DS_H_