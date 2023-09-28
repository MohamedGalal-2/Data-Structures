#ifndef _SINGLE_LINKEDLIST_H_
#define _SINGLE_LINKEDLIST_H_

#include "..\std_types.h"

#define NODE_DEBUG
#define ZERO_INIT 0
#define ZERO      0

typedef struct
{
	void* data;
	struct node* nodeLink;
}node_t;

/**
  * @brief This function inserts a node at the beginning of the list
  * @param list: pointer to the list
  * @return void
  */
void node_insert_beginning(node_t** list);

/**
  * @brief This function inserts a node at the end of the list
  * @param list: pointer to the list
  * @return void
  */
void node_insert_end(node_t** list);

/**
  * @brief This function inserts a node after a selected node
  * @param list: pointer to the list
  * @return void
  */
uint32_t node_length(node_t* list);

/**
  * @brief This function inserts a node after a selected node
  * @param list: pointer to the list
  * @return void
  */
void node_insert_after(node_t* list);

/**
  * @brief This function inserts a node before a selected node
  * @param list: pointer to the list
  * @return void
  */
void node_delete_beginning(node_t** list);

/**
  * @brief This function deletes a node from the end of the list
  * @param list: pointer to the list
  * @return void
  */
void node_delete_end(node_t** list);

/**
  * @brief This function deletes a node from a selected position
  * @param list: pointer to the list
  * @return void
  */
void node_delete_selected(node_t** list);

/**
  * @brief This function displays the list
  * @param list: pointer to the list
  * @return void
  */
void node_display(node_t* list);

/**
  * @brief This function reverses the list
  * @param list: pointer to the list
  * @return void
  */
void node_reverse(node_t** list);


#endif


