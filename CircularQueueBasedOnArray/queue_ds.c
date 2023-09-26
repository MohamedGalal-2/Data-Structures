#include "queue_ds.h"

static queue_status_t queue_full(queue_t* queue)
{
	queue_status_t ret = QUEUE_FULL;

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

static queue_status_t queue_empty(queue_t* queue)
{
	queue_status_t ret = QUEUE_NOK;

	if (NULL == queue)
	{
		ret = QUEUE_NULL_POINTER;
	}
	else
	{
		if (0 == queue->queue_Element_Count)
		{
			ret = QUEUE_EMPTY;
		}
		else
		{
			ret = QUEUE_NOT_EMPTY;
		}
	}

	return ret;
}

queue_t* queue_init(queue_status_t* ret_status, uint32_t queue_Max_Size)
{
	queue_t* my_Queue;
	/* Create queue object in the heap to hold the queue information */
	my_Queue = (queue_t*)malloc(sizeof(queue_t));
	if (NULL == ret_status)
	{
		*ret_status = QUEUE_NOK;
		my_Queue = NULL;
	}
	else
	{
		if (NULL == my_Queue) {
			*ret_status = QUEUE_NULL_POINTER;
			my_Queue = NULL;
		}
		else {
			/* Create array of <void *> to hold the addresses of the Queue elements */
			my_Queue->queue_Array = (void**)calloc(queue_Max_Size, sizeof(void*));
			if (NULL == my_Queue->queue_Array)
			{
				*ret_status = QUEUE_NULL_POINTER;
				my_Queue = NULL;
			}
			else
			{
				my_Queue->queue_Element_Count = 0;
				my_Queue->queue_Front = -1;
				my_Queue->queue_Rear = -1;
				(my_Queue->queue_Max_Size) = queue_Max_Size;
				*ret_status = QUEUE_OK;
			}
		}
	}

	return my_Queue;
}

queue_status_t queue_enqueue(queue_t* queue, void* data)
{
	queue_status_t ret = QUEUE_NOK;

	if (NULL == queue)
	{
		ret = QUEUE_NULL_POINTER;
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
			ret = QUEUE_OK;
		}
	}

	return ret;
}

void* queue_dequeue(queue_t* queue, queue_status_t* ret_status)
{
	void* ret_element = NULL;

	if ((NULL == queue) || (NULL == ret_status))
	{
		*ret_status = QUEUE_NULL_POINTER;
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

void* queue_front(queue_t* queue, queue_status_t* ret_status)
{
	void* ret_element = NULL;
	if ((NULL == queue) || (NULL == ret_status))
	{
		*ret_status = QUEUE_NULL_POINTER;
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
			*ret_status = QUEUE_OK;
		}
	}

	return &ret_element;
}

void* queue_rear(queue_t* queue, queue_status_t* ret_status)
{
	void* ret_element = NULL;
	if ((NULL == queue) || (NULL == ret_status))
	{
		*ret_status = QUEUE_NULL_POINTER;
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
			*ret_status = QUEUE_OK;
		}
	}

	return &ret_element;
}

queue_status_t queue_count(queue_t* queue, uint32_t* ret_count)
{
	queue_status_t ret = QUEUE_NOK;

	if ((NULL == queue) || (NULL == ret_count))
	{
		*ret_count = 0;
		ret = QUEUE_NULL_POINTER;
	}
	else
	{
		*ret_count = queue->queue_Element_Count;
		ret = QUEUE_OK;
	}

	return ret;
}

queue_status_t queue_destroy(queue_t* queue)
{
	queue_status_t ret = QUEUE_NOK;

	if (NULL == queue)
	{
		ret = QUEUE_NULL_POINTER;
	}
	else
	{
		free(queue->queue_Array);
		free(queue);
		ret = QUEUE_OK;
	}

	return ret;
}


