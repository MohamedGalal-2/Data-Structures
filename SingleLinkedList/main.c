#include "single_linkedlist.h"

node_t* listHead = NULL;
uint32_t value = ZERO_INIT;

int main()
{
	printf("------------------node length------------------\n");
	value = node_length(listHead);
	printf("%d\n", value);

	printf("------------------insert beginning------------------\n");
	node_insert_beginning(&listHead);


	printf("------------------display------------------\n");
	node_display(listHead);

	printf("------------------node length------------------\n");
	value = node_length(listHead);
	printf("%d\n", value);

	printf("------------------insert beginning------------------\n");
	node_insert_beginning(&listHead);


	printf("------------------display------------------\n");
	node_display(listHead);

	printf("------------------node length------------------\n");
	value = node_length(listHead);
	printf("%d\n", value);

	printf("------------------insert beginning------------------\n");
	node_insert_beginning(&listHead);


	printf("------------------display------------------\n");
	node_display(listHead);

	printf("------------------node length------------------\n");
	value = node_length(listHead);
	printf("%d\n", value);

	printf("------------------insert beginning------------------\n");
	node_insert_beginning(&listHead);

	printf("------------------display------------------\n");
	node_display(listHead);

	printf("------------------node length------------------\n");
	value = node_length(listHead);
	printf("%d\n", value);

	printf("------------------insert end------------------\n");
	node_insert_end(&listHead);

	printf("------------------display------------------\n");
	node_display(listHead);

	printf("------------------node length------------------\n");
	value = node_length(listHead);
	printf("%d\n", value);

	printf("------------------insert after------------------\n");
	node_insert_after(listHead);

	printf("------------------display------------------\n");
	node_display(listHead);

	printf("------------------node length------------------\n");
	value = node_length(listHead);
	printf("%d\n", value);

	printf("------------------delete beginning------------------\n");
	node_delete_beginning(&listHead);

	printf("------------------display------------------\n");
	node_display(listHead);

	printf("------------------node length------------------\n");
	value = node_length(listHead);
	printf("%d\n", value);

	printf("------------------delete selected------------------\n");
	node_delete_selected(&listHead);

	printf("------------------display------------------\n");
	node_display(listHead);

	printf("------------------node length------------------\n");
	value = node_length(listHead);
	printf("%d\n", value);

	printf("------------------delete end------------------\n");
	node_delete_end(&listHead);

	printf("------------------display------------------\n");
	node_display(listHead);

	printf("------------------node length------------------\n");
	value = node_length(listHead);
	printf("%d\n", value);

	printf("------------------reverse------------------\n");
	node_reverse(&listHead);

	printf("------------------display------------------\n");
	node_display(listHead);

	printf("------------------node length------------------\n");
	value = node_length(listHead);
	printf("%d\n", value);


	return 0;
}