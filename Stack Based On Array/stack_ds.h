#ifndef _STACK_DS_H_
#define _STACK_DS_H_

#include "std_types.h"

#define STACK_MAX_SIZE 5
#define STACK_DEBUG 

typedef struct stack_ds
{
	sint32_t stack_pointer;
	uint32_t data[STACK_MAX_SIZE];
}stack_ds_t;

typedef enum stack_status
{
	STACK_FULL,
	STACK_NOT_FULL,
	STACK_EMPTY,
	STACK_NOT_EMPTY
}stack_status_t;

/**
  * @brief  This function initializes the stack
  * @param  my_stack  pointer to the stack
  * @return return_status_t
  */
return_status_t stack_init(stack_ds_t* my_stack);

/**
  * @brief  This function pushes an element to the stack
  * @param  my_stack  pointer to the stack
  * @param  value  value to be pushed to the stack
  * @return return_status_t
  */
return_status_t stack_push(stack_ds_t* my_stack, sint32_t  value);

/**
  * @brief  This function pops an element from the stack
  * @param  my_stack  pointer to the stack
  * @param  value  pointer to the variable that will hold the popped value
  * @return return_status_t
  */
return_status_t stack_pop(stack_ds_t* my_stack, uint32_t* value);
/**
  * @brief  This function returns the top element of the stack
  * @param  my_stack  pointer to the stack
  * @param  value  pointer to the variable that will hold the top value
  * @return return_status_t
  */
return_status_t stack_top(stack_ds_t* my_stack, uint32_t* value);

/**
  * @brief  This function returns the size of the stack
  * @param  my_stack  pointer to the stack
  * @param  stack_size  pointer to the variable that will hold the stack size
  * @return return_status_t
  */
return_status_t stack_size(stack_ds_t* my_stack, uint32_t* stack_size);

/**
  * @brief  This function displays the stack
  * @param  my_stack  pointer to the stack
  * @return return_status_t
  */
return_status_t stack_display(stack_ds_t* my_stack);


#endif // _STACK_DS_H_