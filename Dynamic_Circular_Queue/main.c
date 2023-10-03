#include "queue_ds.h"

queue_t* queue1;
queue_status_t queue_stat1 = QUEUE_NOK;
void* queue_data1;
uint32_t queue_data2;

int main()
{
	queue1 = queue_init(5, &queue_stat1);
	printf("-------------------Queue DS-------------------\n");
	printf("Queue element count: %d\n", queue1->queue_Element_Count);
	printf("Queue size: %d\n", queue1->queue_Max_Size);
	printf("Queue front: %d\n", queue1->queue_Front);
	printf("Queue rear: %d\n", queue1->queue_Rear);

	printf("-----------------queue_enqueue----------------\n");
	queue_stat1 = queue_enqueue(queue1, (void*)10);
	printf("Queue status: %d\n", queue_stat1);
	printf("Queue data: %d\n", queue1->queue_Array[0]);

	printf("-----------------queue_enqueue----------------\n");
	queue_stat1 = queue_enqueue(queue1, (void*)20);
	printf("Queue status: %d\n", queue_stat1);
	printf("Queue data: %d\n", queue1->queue_Array[1]);

	printf("-----------------queue_enqueue----------------\n");
	queue_stat1 = queue_enqueue(queue1, (void*)30);
	printf("Queue status: %d\n", queue_stat1);
	printf("Queue data: %d\n", queue1->queue_Array[2]);

	printf("-----------------queue_enqueue----------------\n");
	queue_stat1 = queue_enqueue(queue1, (void*)40);
	printf("Queue status: %d\n", queue_stat1);
	printf("Queue data: %d\n", queue1->queue_Array[3]);

	printf("-----------------queue_front----------------\n");
	queue_data1 = queue_front(queue1, &queue_stat1);
	printf("Queue data: %d\n", *((uint32_t*)queue_data1));
	printf("Queue stat: %d\n", queue_stat1);
	printf("-----------------queue_rear----------------\n");
	queue_data1 = queue_rear(queue1, &queue_stat1);
	printf("Queue data: %d\n", *((uint32_t*)queue_data1));
	printf("Queue stat: %d\n", queue_stat1);
	printf("-----------------queue_count----------------\n");
	queue_stat1 = queue_count(queue1, &queue_data2);
	printf("Queue data: %d\n", queue_data2);
	printf("Queue stat: %d\n", queue_stat1);
	printf("-----------------queue_dequeue----------------\n");
	queue_data1 = queue_dequeue(queue1, &queue_stat1);
	printf("Queue data: %d\n", *((uint32_t*)queue_data1));
	printf("Queue stat: %d\n", queue_stat1);

	printf("-----------------queue_front----------------\n");
	queue_data1 = queue_front(queue1, &queue_stat1);
	printf("Queue data: %d\n", *((uint32_t*)queue_data1));
	printf("Queue stat: %d\n", queue_stat1);
	printf("-----------------queue_rear----------------\n");
	queue_data1 = queue_rear(queue1, &queue_stat1);
	printf("Queue data: %d\n", *((uint32_t*)queue_data1));
	printf("Queue stat: %d\n", queue_stat1);
	printf("-----------------queue_count----------------\n");
	queue_stat1 = queue_count(queue1, &queue_data2);
	printf("Queue data: %d\n", queue_data2);
	printf("Queue stat: %d\n", queue_stat1);
	printf("-----------------queue_dequeue----------------\n");
	queue_data1 = queue_dequeue(queue1, &queue_stat1);
	printf("Queue data: %d\n", *((uint32_t*)queue_data1));
	printf("Queue stat: %d\n", queue_stat1);

	printf("-----------------queue_front----------------\n");
	queue_data1 = queue_front(queue1, &queue_stat1);
	printf("Queue data: %d\n", *((uint32_t*)queue_data1));
	printf("Queue stat: %d\n", queue_stat1);
	printf("-----------------queue_rear----------------\n");
	queue_data1 = queue_rear(queue1, &queue_stat1);
	printf("Queue data: %d\n", *((uint32_t*)queue_data1));
	printf("Queue stat: %d\n", queue_stat1);
	printf("-----------------queue_count----------------\n");
	queue_stat1 = queue_count(queue1, &queue_data2);
	printf("Queue data: %d\n", queue_data2);
	printf("Queue stat: %d\n", queue_stat1);
	printf("-----------------queue_dequeue----------------\n");
	queue_data1 = queue_dequeue(queue1, &queue_stat1);
	printf("Queue data: %d\n", *((uint32_t*)queue_data1));
	printf("Queue stat: %d\n", queue_stat1);

	printf("-----------------queue_front----------------\n");
	queue_data1 = queue_front(queue1, &queue_stat1);
	printf("Queue data: %d\n", *((uint32_t*)queue_data1));
	printf("Queue stat: %d\n", queue_stat1);
	printf("-----------------queue_rear----------------\n");
	queue_data1 = queue_rear(queue1, &queue_stat1);
	printf("Queue data: %d\n", *((uint32_t*)queue_data1));
	printf("Queue stat: %d\n", queue_stat1);
	printf("-----------------queue_count----------------\n");
	queue_stat1 = queue_count(queue1, &queue_data2);
	printf("Queue data: %d\n", queue_data2);
	printf("Queue stat: %d\n", queue_stat1);
	printf("-----------------queue_dequeue----------------\n");
	queue_data1 = queue_dequeue(queue1, &queue_stat1);
	printf("Queue data: %d\n", *((uint32_t*)queue_data1));
	printf("Queue stat: %d\n", queue_stat1);


	printf("-----------------queue_enqueue----------------\n");
	queue_stat1 = queue_enqueue(queue1, (void*)2500);
	printf("Queue status: %d\n", queue_stat1);
	printf("Queue data: %d\n", queue1->queue_Array[0]);

	printf("-----------------queue_front----------------\n");
	queue_data1 = queue_front(queue1, &queue_stat1);
	printf("Queue data: %d\n", *((uint32_t*)queue_data1));
	printf("Queue stat: %d\n", queue_stat1);
	printf("-----------------queue_rear----------------\n");
	queue_data1 = queue_rear(queue1, &queue_stat1);
	printf("Queue data: %d\n", *((uint32_t*)queue_data1));
	printf("Queue stat: %d\n", queue_stat1);
	printf("-----------------queue_count----------------\n");
	queue_stat1 = queue_count(queue1, &queue_data2);
	printf("Queue data: %d\n", queue_data2);
	printf("Queue stat: %d\n", queue_stat1);
	printf("-----------------queue_dequeue----------------\n");
	queue_data1 = queue_dequeue(queue1, &queue_stat1);
	printf("Queue data: %d\n", *((uint32_t*)queue_data1));
	printf("Queue stat: %d\n", queue_stat1);

	printf("-----------------queue_destroy----------------\n");
	queue_stat1 = queue_destroy(queue1);
	printf("Queue status: %d\n", queue_stat1);

	printf("-----------------queue_enqueue----------------\n");
	queue_stat1 = queue_enqueue(queue1, (void*)2500);
	printf("Queue status: %d\n", queue_stat1);

	return 0;
}