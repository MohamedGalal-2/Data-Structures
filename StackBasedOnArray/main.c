#include <stdio.h>
#include "stack_ds.h"

stack_ds_t stack1;
stack_ds_t stack2;

sint32_t stack_pop_value = ZERO_INIT;
sint32_t stack_top_value = ZERO_INIT;
uint32_t stack_size_value = ZERO_INIT;

int main()
{
	return_status_t ret = R_NOK;
	ret = stack_init(&stack1);
	if (R_NOK == ret)
	{
		printf("Stack failed to be initialized !!\n");
	}
	else
	{
		ret = stack_push(&stack1, 1);
		ret = stack_push(&stack1, 2);
		ret = stack_push(&stack1, 3);
		ret = stack_push(&stack1, 4);
		ret = stack_push(&stack1, 5);
		ret = stack_push(&stack1, 6); // Fail
		ret = stack_push(&stack1, 7); // Fail
		printf("---------------------------------\n");
		ret = stack_top(&stack1, &stack_top_value);
		if (R_OK == ret)
		{
			printf("Stack top value = %i \n", stack_top_value);
		}
		printf("---------------------------------\n");
		ret = stack_pop(&stack1, &stack_pop_value);
		if (R_OK == ret)
		{
			printf("Stack pop value = %i \n", stack_pop_value);
		}
		ret = stack_pop(&stack1, &stack_pop_value);
		if (R_OK == ret)
		{
			printf("Stack pop value = %i \n", stack_pop_value);
		}
		ret = stack_pop(&stack1, &stack_pop_value);
		if (R_OK == ret)
		{
			printf("Stack pop value = %i \n", stack_pop_value);
		}
		ret = stack_pop(&stack1, &stack_pop_value);
		if (R_OK == ret)
		{
			printf("Stack pop value = %i \n", stack_pop_value);
		}
		ret = stack_pop(&stack1, &stack_pop_value);
		if (R_OK == ret)
		{
			printf("Stack pop value = %i \n", stack_pop_value);
		}
		ret = stack_pop(&stack1, &stack_pop_value); // Fail
		if (R_OK == ret)
		{
			printf("Stack pop value = %i \n", stack_pop_value);
		}
		ret = stack_pop(&stack1, &stack_pop_value); // Fail
		if (R_OK == ret)
		{
			printf("Stack pop value = %i \n", stack_pop_value);
		}
		printf("---------------------------------\n");
		ret = stack_size(&stack1, &stack_size_value);
		if (R_OK == ret)
		{
			printf("Stack size = %i \n", stack_size_value);
		}
		ret = stack_push(&stack1, 190);
		ret = stack_top(&stack1, &stack_top_value);
		if (R_OK == ret)
		{
			printf("Stack top value = %i \n", stack_top_value);
		}
		ret = stack_size(&stack1, &stack_size_value);
		if (R_OK == ret)
		{
			printf("Stack size = %i \n", stack_size_value);
		}
		printf("---------------------------------\n");
		ret = stack_push(&stack1, 25);
		ret = stack_push(&stack1, 236);
		ret = stack_push(&stack1, 180);
		ret = stack_push(&stack1, 358);
		ret = stack_display(&stack1);



	}
	ret = stack_init(&stack2);
	if (R_NOK == ret)
	{
		printf("Stack failed to be initialized !!\n");
	}
	else {}

	return 0;
}
