#include "dynamic_stack_ds.h"

/**
  * @brief  This algorithm checks if the stack is full
  * @param  ret_status  status returned while performing this operation
  * @param  stack_obj  Pointer to the stack to be checked
  * @return the status of the algorithm
  */
static stack_status_t stack_full(stack_ds_t* stack_obj)
{
	stack_status_t ret_status = STACK_FULL;
	if (NULL == stack_obj)
	{
		ret_status = STACK_NULL_POINTER; /* NULL pointer passed to the function */
	}
	else
	{
		if (stack_obj->stack_Top == (stack_obj->stack_Max_Size - 1))
		{
			ret_status = STACK_FULL;
		}
		else
		{
			ret_status = STACK_NOT_FULL;
		}
	}

	return ret_status;
}

/**
  * @brief  This algorithm checks if the stack is empty
  * @param  ret_status  status returned while performing this operation
  * @param  stack_obj  Pointer to the stack to be checked
  * @return the status of the algorithm
  */
static stack_status_t stack_empty(stack_ds_t* stack_obj)
{
	stack_status_t ret_status = STACK_EMPTY;
	if (NULL == stack_obj)
	{
		ret_status = STACK_NULL_POINTER; /* NULL pointer passed to the function */
	}
	else
	{
		if (stack_obj->stack_Top == -1)
		{
			ret_status = STACK_EMPTY;
		}
		else
		{
			ret_status = STACK_NOT_EMPTY;
		}
	}
}

/**
  * @brief  This algorithm creates an empty stack by allocating the head
			structure and the array from dynamic memory.
  * @param  ret_status      Status returned while performing this operation
  * @param  stack_Max_Size  Stack maximum number of elements
  * @return Pointer to the allocated stack in the heap
  */
stack_ds_t* create_stack(uint32_t stack_Max_Size, stack_status_t* ret_status)
{
	stack_ds_t* my_stack = NULL;
	if (NULL == ret_status)
	{
		*ret_status = STACK_NULL_POINTER; /* NULL pointer passed to the function */
		my_stack = NULL;
	}
	else
	{
		/* Allocate the stack in the heap */
		my_stack = (stack_ds_t*)malloc(sizeof(stack_ds_t));
		if (!my_stack)
		{
			*ret_status = STACK_NOK; /* Stack not created successfully */
			my_stack = NULL;
		}
		else
		{
			my_stack->stack_Top = -1; 			   	   /* Initialize the stack pointer to -1 (empty stack) */
			my_stack->element_Count = 0; 			   /* Initialize the element counter to 0 (empty stack) */
			my_stack->stack_Max_Size = stack_Max_Size; /* Initialize the maximum number of elements in the stack */
			my_stack->stack_Array = (void**)calloc(my_stack->stack_Max_Size, sizeof(void*));
			if (!my_stack->stack_Array)
			{
				free(my_stack);  /* Free the stack object as the Array not created successfully */
				my_stack = NULL; /* Array not created successfully */
				*ret_status = STACK_NOK;
			}
			else
			{
				*ret_status = STACK_OK;
			}
		}
	}

	return my_stack;
}

/**
  * @brief  This algorithm destroys the stack by freeing the head structure
			and the array from dynamic memory.
  * @param  ret_status  Status returned while performing this operation
  * @param  stack_obj   Pointer to the stack to be destroyed
  * @return NULL
  */
stack_ds_t* destroy_stack(stack_ds_t* stack_obj, stack_status_t* ret_status)
{
	if ((NULL == ret_status) || (NULL == stack_obj))
	{
		*ret_status = STACK_NULL_POINTER; /* NULL pointer passed to the function */
	}
	else
	{
		free(stack_obj->stack_Array); /* Release the Array object */
		free(stack_obj); /* Release the stack object */
		*ret_status = STACK_OK;
	}

	return NULL;
}

/**
  * @brief  This function pushes an item onto the stack.
  * @param  stack_obj  Pointer to the stack to be pushed to
  * @param  data       Pointer to the data to be pushed to the stack
  * @return the status while performing this operation
  */
stack_status_t push_stack(stack_ds_t* stack_obj, void* data)
{
	stack_status_t ret_status = STACK_NOK;
	if ((NULL == data) || (NULL == stack_obj))
	{
		ret_status = STACK_NULL_POINTER; /* NULL pointer passed to the function */
	}
	else
	{
		if (STACK_FULL == stack_full(stack_obj))
		{
			ret_status = STACK_FULL; /* Stack is full, prevent stack overflow */
		}
		else
		{
			(stack_obj->stack_Top)++; /* Points to the next element in the stack */
			stack_obj->stack_Array[stack_obj->stack_Top] = data;
			(stack_obj->element_Count)++; /* Increment the number of elements in the stack */
			ret_status = STACK_OK;
		}
		ret_status = STACK_OK;
	}

	return ret_status;
}

/**
  * @brief  This algorithm pops an element from the stack.
  * @param  ret_status  Status returned while performing this operation
  * @param  stack_obj   Pointer to the stack to be popped from
  * @return Pointer to the popped data
  */
void* pop_stack(stack_ds_t* stack_obj, stack_status_t* ret_status)
{
	void* popped_data = NULL;
	if ((NULL == stack_obj) || (NULL == ret_status))
	{
		*ret_status = STACK_NULL_POINTER; /* NULL pointer passed to the function */
	}
	else
	{
		if (STACK_EMPTY == stack_empty(stack_obj))
		{
			*ret_status = STACK_EMPTY; /* Stack is empty, prevent stack underflow */
			popped_data = NULL;
		}
		else
		{
			popped_data = stack_obj->stack_Array[stack_obj->stack_Top];
			(stack_obj->stack_Top)--; /* Points to the next element in the stack */
			(stack_obj->element_Count)--; /* Decrement the number of elements in the stack */
			*ret_status = STACK_OK;
		}
	}

	return popped_data;
}

/**
  * @brief  This function retrieves the data from the top of the
			stack without changing the stack.
  * @param  stack_obj   Pointer to stack head structure
  * @param  ret_status  Status returned while performing this operation
  * @retval Pointer to user data if successful, NULL if underflow
  */
void* top_stack(stack_ds_t* stack_obj, stack_status_t* ret_status)
{
	{
		void* topped_data = NULL;
		if ((NULL == stack_obj) || (NULL == ret_status))
		{
			*ret_status = STACK_NULL_POINTER; /* NULL pointer passed to the function */
		}
		else
		{
			if (STACK_EMPTY == stack_empty(stack_obj))
			{
				*ret_status = STACK_EMPTY; /* Stack is empty, prevent stack underflow */
				topped_data = NULL;
			}
			else
			{
				/* Copy the top element to the user */
				topped_data = stack_obj->stack_Array[stack_obj->stack_Top];
				*ret_status = STACK_OK;
			}
		}

		return topped_data;
	}

}

/**
  * @brief  This algorithm returns the number of elements in the stack.
  * @param  ret_status  Status returned while performing this operation
  * @param  stack_obj   Pointer to the stack to be counted
  * @return Status returned while performing this operation
  */
stack_status_t stack_count(stack_ds_t* stack_obj, uint32_t* stack_count)
{
	stack_status_t ret_status = STACK_NOK;
	if ((NULL == stack_count) || (NULL == stack_obj)) /* NULL pointer passed to the function */
	{
		ret_status = STACK_NULL_POINTER;
	}
	else
	{
		*stack_count = stack_obj->element_Count;
		ret_status = STACK_OK;
	}

	return ret_status;
}
