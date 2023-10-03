#include "doubly_linked_list.h"

node_t* head = NULL;
node_t* head2 = NULL;

int main()
{
	printf("--------------insert beginning--------------\n");
	node_insert_beginning(&head, 10);
	node_display_forward(head);

	printf("--------------insert beginning--------------\n");
	node_insert_beginning(&head, 25);
	node_display_forward(head);

	printf("--------------insert beginning--------------\n");
	node_insert_beginning(&head, 30);
	node_display_forward(head);

	printf("--------------insert beginning--------------\n");
	node_insert_beginning(&head, 40);
	node_display_forward(head);
	printf("Node size: %d\n", node_size(head));

	printf("----------------insert after----------------\n");
	node_insert_after(&head, 65, 2);
	node_display_forward(head);
	printf("Node size: %d\n", node_size(head));

	printf("-----------------insert end-----------------\n");
	node_insert_end(&head, 50);
	node_display_forward(head);

	printf("--------------delete beginning--------------\n");
	node_delete_beginning(&head);
	node_display_forward(head);

	printf("----------------insert after----------------\n");
	node_insert_after(&head2, 200, 1);
	node_display_forward(head2);


	printf("--------------insert beginning--------------\n");
	node_insert_beginning(&head2, 100);
	node_display_forward(head2);

	printf("--------------display forward---------------\n");
	node_display_forward(head);

	printf("--------------display backward--------------\n");
	node_display_backward(&head);

	printf("------------------delete end----------------\n");
	node_display_forward(head);
	node_delete_end(&head);
	node_display_forward(head);

	printf("------------------delete end----------------\n");
	node_display_forward(head);
	node_delete_end(&head);
	node_display_forward(head);

	printf("-----------------delete specific------------\n");
	node_display_forward(head);
	node_delete_specific(&head, 2);
	node_display_forward(head);

	printf("-----------------delete specific------------\n");
	node_display_forward(head);
	node_delete_specific(&head, 1);
	node_display_forward(head);

	printf("-----------------delete specific------------\n");
	node_display_forward(head2);
	node_delete_specific(&head2, 1);
	node_display_forward(head2);

	printf("--------------insert beginning--------------\n");
	node_insert_beginning(&head, 10);
	node_display_forward(head);

	printf("--------------insert beginning--------------\n");
	node_insert_beginning(&head, 20);
	node_display_forward(head);

	printf("--------------insert beginning--------------\n");
	node_insert_beginning(&head, 30);
	node_display_forward(head);

	printf("----------------reverse list----------------\n");
	node_display_forward(head);
	node_reverse(&head);
	node_display_forward(head);

	printf("----------------reverse list----------------\n");
	node_display_forward(head2);
	node_reverse(&head2);
	node_display_forward(head2);

	return 0;
}