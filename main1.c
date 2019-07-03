#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include"mythreads.h"

void* enq_worker(void *data)
{
	qu_t *q=(qu_t*)data;
	while(1)
	{
		enqueue(q,task_to_perform,NULL);
		sleep(2);
	}
}
void main()
{

	qu_t *q;
	q=(qu_t*)malloc(sizeof(qu_t));
	init(q);
	int ret;
	pthread_t t1,t2;

	printf("Program preforming enqueing and dequeing\n");
	printf("Enqueuing\n");
	ret=pthread_create(&t1,NULL,&enq_worker,q);
	if(ret!=0)
	{
		printf("Enqueue thread fails\n");
	}
	else
	{

		printf("Enqueue thread created successfully\n");
	}

	printf("Dequeuing\n");
	t2=deq_funct(q);
	
//	pthread_join(t1,NULL);
//	pthread_join(t2,NULL);
	while(1)
		sleep(60);
	free(q);
	

}




