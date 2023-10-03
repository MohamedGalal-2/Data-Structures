#ifndef _QUEUE_DS_H_
#define _QUEUE_DS_H_

#include "std_types.h"

#define QUEUE_DEBUG

typedef struct
{
	void** queue_Array;
	sint32_t queue_Front;
	sint32_t queue_Rear;
	uint32_t queue_Max_Size;
	uint32_t queue_Element_Count;
}queue_t;

typedef enum
{
	QUEUE_OK,
	QUEUE_NOK,
	QUEUE_FULL,
	QUEUE_NOT_FULL,
	QUEUE_EMPTY,
	QUEUE_NOT_EMPTY,
	QUEUE_NULL_POINTER,
}queue_status_t;

/**
  * @brief This function creates a queue object
  * @param[in] ret_status: pointer to the status of the operation
  * @param[in] queue_Max_Size: maximum number of elements in the queue
  * @return queue_t*: pointer to the queue object
  */
queue_t* queue_init(uint32_t queue_Max_Size, queue_status_t* ret_status);

/**
  * @brief This function enqueues an element in the queue
  * @param[in] queue: pointer to the queue object
  * @param[in] data: pointer to the data to be enqueued
  * @return queue_status_t: status of the operation
  */
queue_status_t queue_enqueue(queue_t* queue, void* data);

/**
  * @brief This function dequeues an element from the queue
  * @param[in] queue: pointer to the queue object
  * @param[in] ret_status: pointer to the status of the operation
  * @return void*: pointer to the dequeued data
  */
void* queue_dequeue(queue_t* queue, queue_status_t* ret_status);

/**
  * @brief This function returns the front element of the queue
  * @param[in] queue: pointer to the queue object
  * @param[in] ret_status: pointer to the status of the operation
  * @return void*: pointer to the front element of the queue
  */
void* queue_front(queue_t* queue, queue_status_t* ret_status);

/**
  * @brief This function returns the rear element of the queue
  * @param[in] queue: pointer to the queue object
  * @param[in] ret_status: pointer to the status of the operation
  * @return void*: pointer to the rear element of the queue
  */
void* queue_rear(queue_t* queue, queue_status_t* ret_status);

/**
  * @brief This function returns the number of elements in the queue
  * @param[in] queue: pointer to the queue object
  * @param[in] ret_count: pointer to the number of elements in the queue
  * @return queue_status_t: status of the operation
  */
queue_status_t queue_count(queue_t* queue, uint32_t* ret_count);

/**
  * @brief This function checks if the queue is empty
  * @param[in] queue: pointer to the queue object
  * @param[in] ret_status: pointer to the status of the operation
  * @return queue_status_t: status of the operation
  */
queue_status_t queue_destroy(queue_t* queue);


#endif // _QUEUE_DS_H_ 