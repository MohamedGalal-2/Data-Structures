#ifndef _DOUBLY_LINKED_LIST_H_
#define _DOUBLY_LINKED_LIST_H_

#include "..\std_types.h"

#define NODE_DEBUG
#define COUNTER_INIT 1

typedef struct
{
	uint32_t data;
	struct node* LeftNodeLink;
	struct node* RightNodeLink;
}node_t;

void node_insert_beginning(node_t** list, uint32_t data);
void node_insert_end(node_t** list, uint32_t data);
void node_insert_after(node_t** list, uint32_t data, uint32_t position);
void node_delete_beginning(node_t** list);
void node_delete_end(node_t** list);
void node_delete_specific(node_t** list, uint32_t position);
void node_display_forward(node_t* list);
void node_display_backward(node_t** list);
void node_reverse(node_t** list);
uint32_t node_size(node_t* list);


#endif // _DOUBLY_LINKED_LIST_H_