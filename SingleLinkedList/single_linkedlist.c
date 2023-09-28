

#include "single_linkedlist.h"

/**
  * @brief This function inserts a node at the beginning of the list
  * @param list: pointer to the list
  * @return void
  */
void node_insert_beginning(node_t** list)
{
	node_t* tempNode = NULL;
	tempNode = (node_t*)malloc(sizeof(node_t));

	if (NULL != tempNode)
	{
		printf("%s\n", "Enter the data to be inserted:");
		scanf("%d", &(tempNode->data));
		/* Checks if the list is empty*/
		if (NULL == *list) /* Linked List is empty */
		{
			tempNode->nodeLink = NULL;
			*list = tempNode;
		}
		else /* Linked List is not empty */
		{
			tempNode->nodeLink = *list;
			*list = tempNode;
		}
	}
	else
	{
		/* Nothing*/
	}
}

/**
  * @brief This function inserts a node at the end of the list
  * @param list: pointer to the list
  * @return void
  */
void node_insert_end(node_t** list)
{
	node_t* tempNode = NULL;
	node_t* lastNode = NULL;

	tempNode = (node_t*)malloc(sizeof(node_t));
	if (NULL != tempNode)
	{
		printf("%s\n", "Enter the data to be inserted:");
		scanf("%d", &(tempNode->data));
		tempNode->nodeLink = NULL;
		if (NULL == list) /* Linked List is empty */
		{
			*list = tempNode;
		}
		else /*Linked List is not empty*/
		{
			lastNode = *list;
			while (lastNode->nodeLink != NULL)
			{
				lastNode = lastNode->nodeLink;
			}
			lastNode->nodeLink = tempNode;
		}
	}
	else
	{
		/* Nothing */
	}
}

/**
  * @brief This function returns the length of the list
  * @param list: pointer to the list
  * @return uint32_t: length of the list
  */
uint32_t node_length(node_t* list)
{
	uint32_t length = 0;
	node_t* tempNode = NULL;
	tempNode = (node_t*)malloc(sizeof(node_t));
	if (NULL != list)
	{
		if (NULL != tempNode)
		{
			tempNode = list;
			while (tempNode != NULL)
			{
				tempNode = tempNode->nodeLink;
				length++;
			}
		}
		else
		{
			/* Nothing */
		}
	}
	else
	{
		/* Nothing */
	}
	return length;
}

/**
  * @brief This function inserts a node after a selected node
  * @param list: pointer to the list
  * @return void
  */
void node_insert_after(node_t* list)
{
	node_t* tempNode = NULL;
	node_t* lastNode = NULL;
	uint32_t nodePosition = ZERO_INIT;
	uint32_t listLength = node_length(list);
	uint32_t counter = ZERO_INIT;

	printf("Please enter the position (First node is position 1): ");
	scanf("%d", &nodePosition);

	if (nodePosition < listLength)
	{
		lastNode = list;
		while (counter++ < nodePosition - 1)
		{
			lastNode = lastNode->nodeLink;
		}
		/* tempNode points to the node where we have to insert after*/
		tempNode = (node_t*)malloc(sizeof(node_t));
		if (NULL != tempNode)
		{
			printf("Enter Node data: ");
			scanf("%d", &(tempNode->data));
			/* Connect the righ side connection */
			tempNode->nodeLink = lastNode->nodeLink;
			/* Connect the left side connection */
			lastNode->nodeLink = tempNode;
		}
		else
		{
			/* Nothing */
		}
	}
	else
	{
		printf("Invalid position -> list has (%d) Nodes \n", listLength);
	}

}

/**
  * @brief This function deletes a node from the beginning of the list
  * @param list: pointer to the list
  * @return void
  */
void node_delete_beginning(node_t** list)
{
	node_t* tempNode = *list;
	uint32_t listLength = node_length(*list);

	if (listLength > 0)
	{
		*list = tempNode->nodeLink;
		tempNode->nodeLink = NULL;
		free(tempNode);
	}
	else
	{
		printf("List is empty!! \n");
	}
}

/**
  * @brief This function deletes a node from the end of the list
  * @param list: pointer to the list
  * @return void
  */
void node_delete_end(node_t** list)
{
	node_t* tempNode = *list;
	node_t* lastNode = NULL;
	uint32_t listLength = node_length(*list);
	if (listLength > 0)
	{
		while (NULL != tempNode->nodeLink)
		{
			lastNode = tempNode;
			tempNode = tempNode->nodeLink;
		}
		lastNode->nodeLink = NULL;
		free(tempNode);
	}
	else
	{
		printf("List is empty!! \n");
	}
}

/**
  * @brief This function deletes a node from a selected position
  * @param list: pointer to the list
  * @return void
  */
void node_delete_selected(node_t** list)
{
	node_t* tempNode = *list;
	node_t* lastNode = NULL;

	uint32_t nodePosition = ZERO_INIT;
	uint32_t listLength = node_length(*list);
	uint32_t counter = 1;

	printf("Please enter the position (First node is position 1): ");
	scanf("%d", &nodePosition);

	if (nodePosition >= 1 && nodePosition <= listLength)
	{
		if (1 == nodePosition)
		{
			node_delete_beginning(list);
		}
		else if (nodePosition == listLength)
		{
			node_delete_end(list);
		}
		else
		{
			while (counter++ < nodePosition - 1)
			{
				tempNode = tempNode->nodeLink;
			}
			lastNode = tempNode->nodeLink;
			tempNode->nodeLink = lastNode->nodeLink;
			lastNode->nodeLink = NULL;
			free(lastNode);
		}
	}
	else
	{
		printf("Invalid position -> list has (%d) Nodes \n", listLength);
	}

}

/**
  * @brief This function displays the list
  * @param list: pointer to the list
  * @return void
  */
void node_display(node_t* list)
{
	uint32_t counter = 1;
	node_t* tempNode = NULL;
	tempNode = list;
	if (NULL == tempNode)
	{
		printf("List is empty!! \n");
	}
	else
	{
		while (tempNode != NULL)
		{
			printf("Element[%d] = %d -> ", counter, tempNode->data);
			tempNode = tempNode->nodeLink;
			counter++;
		}
		printf("NULL \n");
	}
}

/**
  * @brief This function reverses the list
  * @param list: pointer to the list
  * @return void
  */
void node_reverse(node_t** list)
{
	node_t* prevNode = NULL;
	node_t* nextNode = NULL;
	node_t* currentNode = *list;

	while (NULL != currentNode)
	{
		/* Store next item */
		nextNode = currentNode->nodeLink; // NULL for last node
		/* Reverse current node's pointer */
		currentNode->nodeLink = prevNode; // NULL for first node
		/* Move pointers one position ahead */
		prevNode = currentNode; // Move prevNode to current node
		currentNode = nextNode; // Move currentNode to next node

		/* Store Next item*/
		nextNode = currentNode->nodeLink;
		/* Reverse the current node's pointer*/
		currentNode->nodeLink = prevNode;
		/* Move the pointer one step ahead */
		prevNode = currentNode;
		currentNode = nextNode;

	}

	*list = prevNode;
}


