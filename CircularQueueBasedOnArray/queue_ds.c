/**
  * @file queue_ds.c
  * @brief This file contains the implementation of the Queue Data Structure
  * @date 26/9/2023 20:12
  * @version 1.0
  */

#include "queue_ds.h"

  /**
	* @brief This function checks if the queue is full
	* @param[in] queue: pointer to the queue object
	* @return queue_status_t: status of the operation
	*/
static queue_status_t queue_full(queue_t* queue)
{
	queue_status_t ret = QUEUE_FULL; /* NULL pointer passed to the function */

	if (NULL == queue)
	{
		ret = QUEUE_NULL_POINTER;
	}
	else
	{
		if (queue->queue_Element_Count == (queue->queue_Max_Size))
		{
			ret = QUEUE_FULL;
		}
		else
		{
			ret = QUEUE_NOT_FULL;
		}
	}

	return ret;
}

/**
  * @brief This function checks if the queue is empty
  * @param[in] queue: pointer to the queue object
  * @return queue_status_t: status of the operation
  */
static queue_status_t queue_empty(queue_t* queue)
{
	queue_status_t ret = QUEUE_NOK;

	if (NULL == queue)
	{
		ret = QUEUE_NULL_POINTER; /* NULL pointer passed to the function */
	}
	else
	{
		/* Validate if the queue is not empty */
		if (0 == queue->queue_Element_Count)
		{
			ret = QUEUE_EMPTY; /* Queue is empty */
		}
		else
		{
			ret = QUEUE_NOT_EMPTY; /* Queue is not empty */
		}
	}

	return ret;
}

/**
  * @brief This function creates a queue object
  * @param[in] ret_status: pointer to the status of the operation
  * @param[in] queue_Max_Size: maximum number of elements in the queue
  * @return queue_t*: pointer to the queue object
  */
queue_t* queue_init(queue_status_t* ret_status, uint32_t queue_Max_Size)
{
	queue_t* my_Queue;
	/* Create queue object in the heap to hold the queue information */
	my_Queue = (queue_t*)malloc(sizeof(queue_t));
	if (NULL == ret_status)
	{
		*ret_status = QUEUE_NULL_POINTER; /* NULL pointer passed to the function */
		my_Queue = NULL;
	}
	else
	{
		if (NULL == my_Queue) {
			*ret_status = QUEUE_NOK; /* Memory allocation failed */
			my_Queue = NULL;
		}
		else {
			/* Create array of <void *> to hold the addresses of the Queue elements */
			my_Queue->queue_Array = (void**)calloc(queue_Max_Size, sizeof(void*));
			if (NULL == my_Queue->queue_Array)
			{
				*ret_status = QUEUE_NOK; /* Memory allocation failed */
				my_Queue = NULL;
			}
			else
			{
				my_Queue->queue_Element_Count = 0;
				my_Queue->queue_Front = -1;
				my_Queue->queue_Rear = -1;
				(my_Queue->queue_Max_Size) = queue_Max_Size;
				*ret_status = QUEUE_OK; /* Queue created successfully */
			}
		}
	}

	return my_Queue;
}

/**
  * @brief This function adds an element to the queue
  * @param[in] queue: pointer to the queue object
  * @param[in] data: pointer to the data to be added to the queue
  * @return queue_status_t: status of the operation
  */
queue_status_t queue_enqueue(queue_t* queue, void* data)
{
	queue_status_t ret = QUEUE_NOK;

	if (NULL == queue)
	{
		ret = QUEUE_NULL_POINTER; /* NULL pointer passed to the function */
	}
	else
	{
		/* Validate if the queue is not full */
		if (QUEUE_FULL == queue_full(queue))
		{
			ret = QUEUE_FULL; /* Queue is full, can't enqueue new element */
		}
		else
		{
			/* Increment Queue Rear Index */
			(queue->queue_Rear)++;
			/* Queue wraps to element 0 (Circular Queue) */
			if (queue->queue_Rear == queue->queue_Max_Size)
			{
				queue->queue_Rear = 0;
			}
			else { /*Nothing */ }
			/* Insert the input data in to the rear position */
			queue->queue_Array[queue->queue_Rear] = data;
			/* validate if the queue was empty, (front and rear points to the first element) */
			if (QUEUE_EMPTY == queue_empty(queue)) {
				queue->queue_Front = 0;
				queue->queue_Element_Count = 1;
			}
			else {
				(queue->queue_Element_Count)++; /* New element has been added to the Queue */
			}
			ret = QUEUE_OK; /* Element has been added to the Queue */
		}
	}

	return ret;
}

/**
  * @brief This function removes an element from the queue
  * @param[in] queue: pointer to the queue object
  * @param[in] ret_status: pointer to the status of the operation
  * @return void*: pointer to the data removed from the queue
  */
void* queue_dequeue(queue_t* queue, queue_status_t* ret_status)
{
	void* ret_element = NULL;

	if ((NULL == queue) || (NULL == ret_status))
	{
		*ret_status = QUEUE_NULL_POINTER; /* NULL pointer passed to the function */
		ret_element = NULL;
	}
	else
	{
		/* Checks if the queue is empty */
		if (QUEUE_EMPTY == queue_empty(queue))
		{
			*ret_status = QUEUE_EMPTY; /* Queue is empty, can't dequeue element */
			ret_element = NULL;
		}
		else
		{
			/* Queue is not empty */
			ret_element = queue->queue_Array[queue->queue_Front];
			/* Increment Queue Front Index */
			(queue->queue_Front)++;
			/* Queue front was wrapped to element 0 (Circular Queue) */
			if (queue->queue_Front == queue->queue_Max_Size)
			{
				queue->queue_Front = 0;
			}
			else
			{
				/*Nothing */
			}
			/* Check if the element is the last element in the Queue */
			if (1 == queue->queue_Element_Count) {
				queue->queue_Front = -1; /* Queue is empty */
				queue->queue_Rear = -1;  /* Queue is empty */
			}
			else
			{
				/* Nothing */
			}
			(queue->queue_Element_Count)--; /* Element has been deleted from the Queue */
			*ret_status = QUEUE_OK;
		}
	}

	return &ret_element;
}

/**
  * @brief This function returns the front element in the queue
  * @param[in] queue: pointer to the queue object
  * @param[in] ret_status: pointer to the status of the operation
  * @return void*: pointer to the front element in the queue
  */
void* queue_front(queue_t* queue, queue_status_t* ret_status)
{
	void* ret_element = NULL;
	if ((NULL == queue) || (NULL == ret_status))
	{
		*ret_status = QUEUE_NULL_POINTER; /* NULL pointer passed to the function */
		ret_element = NULL;
	}
	else
	{
		/* Checks if the queue is empty */
		if (QUEUE_EMPTY == queue_empty(queue))
		{
			*ret_status = QUEUE_EMPTY; /* Queue is empty */
			ret_element = NULL;
		}
		else
		{
			/* Queue is not empty */
			ret_element = queue->queue_Array[queue->queue_Front];
			*ret_status = QUEUE_OK; /* Element returned successfully */
		}
	}

	return &ret_element;
}

/**
  * @brief This function returns the rear element in the queue
  * @param[in] queue: pointer to the queue object
  * @param[in] ret_status: pointer to the status of the operation
  * @return void*: pointer to the rear element in the queue
  */
void* queue_rear(queue_t* queue, queue_status_t* ret_status)
{
	void* ret_element = NULL;
	if ((NULL == queue) || (NULL == ret_status))
	{
		*ret_status = QUEUE_NULL_POINTER; /* NULL pointer passed to the function */
		ret_element = NULL;
	}
	else
	{
		/* Checks if the queue is empty */
		if (QUEUE_EMPTY == queue_empty(queue))
		{
			*ret_status = QUEUE_EMPTY; /* Queue is empty */
			ret_element = NULL;
		}
		else
		{
			/* Queue is not empty */
			ret_element = queue->queue_Array[queue->queue_Rear];
			*ret_status = QUEUE_OK; /* Element returned successfully */
		}
	}

	return &ret_element;
}

/**
  * @brief This function returns the number of elements in the queue
  * @param[in] queue: pointer to the queue object
  * @param[in] ret_count: pointer to the number of elements in the queue
  * @return queue_status_t: status of the operation
  */
queue_status_t queue_count(queue_t* queue, uint32_t* ret_count)
{
	queue_status_t ret = QUEUE_NOK;

	if ((NULL == queue) || (NULL == ret_count))
	{
		*ret_count = 0;
		ret = QUEUE_NULL_POINTER; /* NULL pointer passed to the function */
	}
	else
	{
		*ret_count = queue->queue_Element_Count;
		ret = QUEUE_OK; /* Element returned successfully */
	}

	return ret;
}

/**
  * @brief This function destroys the queue object
  * @param[in] queue: pointer to the queue object
  * @return queue_status_t: status of the operation
  */
queue_status_t queue_destroy(queue_t* queue)
{
	queue_status_t ret = QUEUE_NOK;

	if (NULL == queue)
	{
		ret = QUEUE_NULL_POINTER; /* NULL pointer passed to the function */
	}
	else
	{
		free(queue->queue_Array);
		free(queue);
		ret = QUEUE_OK; /* Queue destroyed successfully */
	}

	return ret;
}

