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

/** @brief This function inserts a node at the beginning of the list
  * @param list: The list to be inserted in
  * @param data: The data to be inserted
  * @return void
  */
void node_insert_beginning(node_t** list, uint32_t data);

/** @brief This function inserts a node at the end of the list
  * @param list: The list to be inserted in
  * @param data: The data to be inserted
  * @return void
  */
void node_insert_end(node_t** list, uint32_t data);

/** @brief This function inserts a node at a specific position in the list
  * @param list: The list to be inserted in
  * @param data: The data to be inserted
  * @param position: The position to be inserted at
  * @return void
  */
void node_insert_after(node_t** list, uint32_t data, uint32_t position);

/** @brief This function deletes a node from the beginning of the list
  * @param list: The list to be deleted from
  * @return void
  */
void node_delete_beginning(node_t** list);

/** @brief This function deletes a node from the end of the list
  * @param list: The list to be deleted from
  * @return void
  */
void node_delete_end(node_t** list);

/** @brief This function deletes a node from a specific position in the list
  * @param list: The list to be deleted from
  * @param position: The position to be deleted from
  * @return void
  */
void node_delete_specific(node_t** list, uint32_t position);

/** @brief This function displays the list in a forward manner
  * @param list: The list to be displayed
  * @return void
  */
void node_display_forward(node_t* list);

/** @brief This function displays the list in a backward manner
  * @param list: The list to be displayed
  * @return void
  */
void node_display_backward(node_t** list);

/** @brief This function reverses the list
  * @param list: The list to be reversed
  * @return void
  */
void node_reverse(node_t** list);

/** @brief This function returns the size of the list
  * @param list: The list to be returned
  * @return uint32_t: The size of the list
  */
uint32_t node_size(node_t* list);


#endif // _DOUBLY_LINKED_LIST_H_