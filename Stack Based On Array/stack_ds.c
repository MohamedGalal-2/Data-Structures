#include "stack_ds.h"

/** @brief  This function checks if the stack is full
  * @param  my_stack  pointer to the stack
  * @return stack_status_t
  */
static stack_status_t stack_full(stack_ds_t* my_stack)
{
	if ((STACK_MAX_SIZE - 1) == my_stack->stack_pointer)
	{
		return STACK_FULL;
	}
	else
	{
		return STACK_NOT_FULL;
	}
}

/**
  * @brief  This function checks if the stack is empty
  * @param  my_stack  pointer to the stack
  * @return stack_status_t
  */
static stack_empty(stack_ds_t* my_stack)
{
	if (-1 == my_stack->stack_pointer)
	{
		return STACK_EMPTY;
	}
	else
	{
		return STACK_NOT_EMPTY;

	}
}

/**
  * @brief  This function initializes the stack
  * @param  my_stack  pointer to the stack
  * @return return_status_t
  */
return_status_t stack_init(stack_ds_t* my_stack)
{
	return_status_t ret = R_NOK;

	if (NULL == my_stack)
	{
		ret = R_NOK;
	}
	else
	{
		my_stack->stack_pointer = -1;
		ret = R_OK;
	}


	return ret;
}

/**
  * @brief  This function pushes an element to the stack
  * @param  my_stack  pointer to the stack
  * @param  value  value to be pushed to the stack
  * @return return_status_t
  */
return_status_t stack_push(stack_ds_t* my_stack, sint32_t  value)
{
	return_status_t ret = R_NOK;

	if ((NULL == my_stack) || (STACK_FULL == stack_full(my_stack)))
	{
#ifdef STACK_DEBUG
		printf("Error!! Stack is Full, Can't push %i \n", value);
#endif
		ret = R_NOK;
	}
	else
	{
		my_stack->stack_pointer++;
		my_stack->data[my_stack->stack_pointer] = value;
#ifdef STACK_DEBUG
		printf("Value %d pushed to the stack. \n", value);
#endif
		ret = R_OK;
	}

	return ret;
}

/**
  * @brief  This function pops an element from the stack
  * @param  my_stack  pointer to the stack
  * @param  value  pointer to the variable that will hold the popped value
  * @return return_status_t
  */
return_status_t stack_pop(stack_ds_t* my_stack, uint32_t* value)
{
	return_status_t ret = R_NOK;

	if ((NULL == my_stack) || (NULL == value) || (STACK_EMPTY == stack_empty(my_stack)))
	{
#ifdef STACK_DEBUG
		printf("Error!! Stack is Empty, Can't pop any value!! \n");
#endif
		ret = R_NOK;
	}
	else
	{
		*value = my_stack->data[my_stack->stack_pointer];
		my_stack->stack_pointer--;
#ifdef STACK_DEBUG
		printf("Value %d poped from the stack. \n", *value);
#endif
		ret = R_OK;
	}

	return ret;
}

/**
  * @brief  This function returns the top element of the stack
  * @param  my_stack  pointer to the stack
  * @param  value  pointer to the variable that will hold the top value
  * @return return_status_t
  */
return_status_t stack_top(stack_ds_t* my_stack, uint32_t* value)
{
	return_status_t ret = R_NOK;

	if ((NULL == my_stack) || (NULL == value) || (STACK_EMPTY == stack_empty(my_stack)))
	{
#ifdef STACK_DEBUG
		printf("Error!! Stack is Empty, Can't top any value!! \n");
#endif
		ret = R_NOK;
	}
	else
	{
		*value = my_stack->data[my_stack->stack_pointer];
#ifdef STACK_DEBUG
		printf("Value %d topped from the stack. \n", *value);
#endif
		ret = R_OK;
	}

	return ret;
}

/**
  * @brief  This function returns the size of the stack
  * @param  my_stack  pointer to the stack
  * @param  stack_size  pointer to the variable that will hold the stack size
  * @return return_status_t
  */
return_status_t stack_size(stack_ds_t* my_stack, uint32_t* stack_size)
{
	return_status_t ret = R_NOK;

	if ((NULL == my_stack) || (NULL == stack_size))
	{
#ifdef STACK_DEBUG
		printf("Error!! \n");
#endif
		ret = R_NOK;
	}
	else
	{
		*stack_size = my_stack->stack_pointer + 1;
#ifdef STACK_DEBUG
		printf("Stack size is %d \n", *stack_size);
#endif
		ret = R_OK;
	}

	return ret;
}

/**
  * @brief  This function displays the stack
  * @param  my_stack  pointer to the stack
  * @return return_status_t
  */
return_status_t stack_display(stack_ds_t* my_stack)
{
	return_status_t ret = R_NOK;
	sint32_t l_counter = ZERO_INIT;

	if ((NULL == my_stack) || (STACK_EMPTY == stack_empty(my_stack)))
	{
#ifdef STACK_DEBUG
		printf("Error!! Stack is Empty, Can't display any value!! \n");
#endif
		ret = R_NOK;
	}
	else
	{
		for (l_counter; l_counter < my_stack->stack_pointer + 1; l_counter++)
		{
			printf("Stack[%d] = %d \n", l_counter, my_stack->data[l_counter]);
		}
		ret = R_OK;
	}


	return ret;
}

