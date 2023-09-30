#include "doubly_linked_list.h"

void node_insert_beginning(node_t** list, uint32_t data)
{
	node_t* tempNode = (node_t*)malloc(sizeof(node_t));

	if (NULL != tempNode)
	{
		tempNode->data = data;
		/* Checks if the list is empty*/
		if (NULL == *list)
		{
			tempNode->RightNodeLink = NULL; /* This is the only node */
			tempNode->LeftNodeLink = NULL;  /* This is the only node */
			*list = tempNode; /* Makes the head pointer points to this only node */
		}
		else
		{
			tempNode->RightNodeLink = (*list); /* Makes the new node to be the head */
			tempNode->LeftNodeLink = NULL; /* The left node is always NULL in the head pointer */
			(*list)->LeftNodeLink = tempNode; /* Makes the old head node to point to the new head node */
			*list = tempNode; /* Makes the head pointer points to the new head node */
		}
	}
	else
	{
		printf("Memory allocation failed!! \n");
	}
}

void node_insert_end(node_t** list, uint32_t data)
{
	node_t* tempNode = (node_t*)malloc(sizeof(node_t));

	if (NULL != tempNode)
	{
		/* Checks if the list is empty*/
		if (NULL == *list)
		{
			tempNode->data = data;
			tempNode->RightNodeLink = NULL; /* This is the only node */
			tempNode->LeftNodeLink = NULL;  /* This is the only node */
			*list = tempNode; /* Makes the head pointer points to this only node */
		}
		else
		{
			/* Traverse the list till the end */
			tempNode = *list;
			while (tempNode->RightNodeLink != NULL)
			{
				tempNode = tempNode->RightNodeLink;
			}
			node_t* newNode = (node_t*)malloc(sizeof(node_t));

			if (NULL != newNode)
			{
				newNode->data = data; /* Makes the new node to be the head */
				tempNode->RightNodeLink = newNode; /* Makes the old head node to point to the new head node */
				newNode->LeftNodeLink = tempNode; /* Makes the old head node to point to the new head node */
				newNode->RightNodeLink = NULL; /* The left node is always NULL in the head pointer */
			}
			else
			{
				printf("Memory allocation failed!! \n");
			}
		}
	}
	else
	{
		printf("Memory allocation failed!! \n");
	}
}

void node_insert_after(node_t** list, uint32_t data, uint32_t position)
{
	uint32_t counter = COUNTER_INIT;
	uint32_t listSize = node_size(*list);
	node_t* prevNode = NULL;
	node_t* nextNode = NULL;
	node_t* tempNode = (node_t*)malloc(sizeof(node_t));

	if (position < listSize)
	{
		if (NULL != nextNode || NULL != tempNode)
		{
			nextNode = *list;
			while (counter++ <= position)
			{
				nextNode = nextNode->RightNodeLink;
			}

			prevNode = nextNode->LeftNodeLink; /* This pointer points to the previous node */
			tempNode->data = data; /* Makes the new node to be the head */
			tempNode->RightNodeLink = nextNode; /* Makes the new node points to the node on its rigt*/
			tempNode->LeftNodeLink = prevNode; /* Makes the new node points to the node on its left*/
			prevNode->RightNodeLink = tempNode; /* Makes the previous node points to the new node */
			nextNode->LeftNodeLink = tempNode; /* Makes the next node points to the new node */
		}
		else
		{
			printf("Memory allocation failed!! \n");
		}
	}
	else if (position == listSize)
	{
		node_insert_end(&(*list), data);
	}
	else
	{
		printf("Invalid position!! The list has (%d) elements \n", listSize);
	}

}

void node_delete_beginning(node_t** list)
{
	node_t* tempNode = NULL;
	uint32_t listSize = node_size(*list);

	if (NULL != list)
	{
		if (1 == listSize)
		{
			*list = NULL;
		}
		else
		{
			tempNode = *list;
			(*list) = tempNode->RightNodeLink;
			(*list)->LeftNodeLink = NULL;
		}
	}
	else
	{
		printf("Cannot delete from an empty list!! \n");
	}
}

void node_delete_end(node_t** list)
{
	uint32_t counter = COUNTER_INIT;
	uint32_t listSize = node_size(*list);
	node_t* tempNode = *list;

	if (ZERO != listSize)
	{
		if (1 == listSize)
		{
			node_delete_beginning(list);
		}
		else
		{
			while (counter++ < (listSize - 1))
			{
				tempNode = tempNode->RightNodeLink;
			}

			tempNode->RightNodeLink = NULL;
		}
	}
	else
	{
		printf("Cannot delete from an empty list!! \n");
	}
}

void node_delete_specific(node_t** list, uint32_t position)
{
	uint32_t counter = COUNTER_INIT;
	uint32_t listSize = node_size(*list);
	node_t* prevNode = NULL;
	node_t* nextNode = NULL;
	node_t* tempNode = *list;

	/* Checks if the list is empty */
	if (1 <= listSize)
	{
		if (position <= listSize)
		{
			if (1 == position)
			{
				node_delete_beginning(&(*list));
			}
			else if ((position == listSize) && (1 != listSize))
			{
				node_delete_end(&*list);
			}
			else
			{
				while (counter++ < position)
				{
					tempNode = tempNode->RightNodeLink;
				}

				nextNode = tempNode->RightNodeLink; /* This pointer points to the next node */
				prevNode = tempNode->LeftNodeLink; /* This pointer points to the previous node */
				prevNode->RightNodeLink = nextNode; /* Makes the previous node points to the next node */
				nextNode->LeftNodeLink = prevNode;	/* Makes the next node points to the previous node */
			}
		}
		else
		{
			printf("Invalid position!! The list has (%d) elements \n", listSize);
		}
	}
	else
	{
		printf("Cannot delete from an empty list!! \n");
	}
}

void node_display_forward(node_t* list)
{
	uint32_t counter = 1;
	while (NULL != list)
	{
		printf("Element[%d] = %d -> ", counter, list->data);
		list = list->RightNodeLink;
		counter++;
	}
	printf("NULL \n");
}

void node_display_backward(node_t** list)
{
	uint32_t counter = 1;
	uint32_t listSize = node_size(*list);
	node_t* tempNode = *list;

	while (NULL != tempNode->RightNodeLink)
	{
		tempNode = tempNode->RightNodeLink;
	}
	while (NULL != tempNode)
	{
		printf("Element[%d] = %d -> ", listSize, tempNode->data);
		tempNode = tempNode->LeftNodeLink;
		listSize--;
	}
	printf("NULL \n");
}

void node_reverse(node_t** list)
{
	uint32_t listSize = node_size(*list);
	node_t* currentNode = *list;
	node_t* tempNode = NULL;

	if (listSize)
	{
		while (currentNode != NULL)
		{
			tempNode = currentNode->LeftNodeLink;
			currentNode->LeftNodeLink = currentNode->RightNodeLink;
			currentNode->RightNodeLink = tempNode;
			currentNode = currentNode->LeftNodeLink;
		}

		if (tempNode != NULL)
		{
			*list = tempNode->LeftNodeLink;
		}
	}
	else
	{
		printf("Cannot reverse an empty list!! \n");
	}

}

uint32_t node_size(node_t* list)
{
	uint32_t counter = 0;
	while (list != NULL)
	{
		counter++;
		list = list->RightNodeLink;
	}

	return counter;
}
