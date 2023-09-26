#include <stdio.h>
#include "dynamic_stack_ds.h"

uint32_t stack1_size = 0;
stack_ds_t* stack1 = NULL;

stack_status_t return_status = STACK_NOK;

uint32_t topped_raw_data = 0;
void* topped_data = NULL;
void* popped_data = NULL;
uint32_t  l_stack_count = 0;

int main()
{
	stack_status_t ret_status = STACK_NOK;

	printf("Enter the size of the stack: ");
	scanf("%d", &stack1_size);

	stack1 = create_stack(stack1_size, &ret_status);

	if (stack1)
	{
		printf("Stack1 not NULL\n");
	}
	printf("----------------------------------\n");
	uint32_t var1 = 5, var2 = 50, var3 = 500, var4 = 600, var6 = 158, var7 = 1899, var8 = 20152;
	uint8_t var5 = 'A';


	return_status = push_stack(stack1, (void*)150);
	topped_raw_data = (uint32_t*)top_stack(stack1, &ret_status);
	printf("The topped data is [%d]\n", topped_raw_data);

	return_status = push_stack(stack1, &var1);
	topped_data = top_stack(stack1, &ret_status);
	printf("Stack_status is [%d]\n", return_status);
	printf("The topped data is [%d]\n", *((uint32_t*)topped_data));

	return_status = push_stack(stack1, &var2);
	topped_data = top_stack(stack1, &ret_status);
	printf("The topped data is [%d]\n", *((uint32_t*)topped_data));

	return_status = push_stack(stack1, &var5);
	topped_data = top_stack(stack1, &ret_status);
	printf("The topped data is [%c]\n", *((uint8_t*)topped_data));

	return_status = push_stack(stack1, &var3);
	topped_data = top_stack(stack1, &ret_status);
	printf("The topped data is [%d]\n", *((uint32_t*)topped_data));
	printf("----------------------------------\n");

	popped_data = pop_stack(stack1, &ret_status);
	printf("The popped data is [%d]\n", *((uint32_t*)popped_data));
	return_status = push_stack(stack1, &var4);
	topped_data = top_stack(stack1, &ret_status);
	printf("The topped data is [%d]\n", *((uint32_t*)topped_data));
	stack_count(stack1, &l_stack_count);
	printf("The stack count is [%d]\n", l_stack_count);
	return_status = push_stack(stack1, &var6);
	return_status = push_stack(stack1, &var7);
	return_status = push_stack(stack1, &var8);
	topped_data = top_stack(stack1, &ret_status);
	printf("The topped data is [%d]\n", *((uint32_t*)topped_data));
	stack_count(stack1, &l_stack_count);
	printf("The stack count is [%d]\n", l_stack_count);


	printf("----------------------------------\n");
	stack1 = destroy_stack(stack1, &ret_status);

	if (!stack1)
	{
		printf("Stack1 was destroyed\n");
	}


	return 0;
}