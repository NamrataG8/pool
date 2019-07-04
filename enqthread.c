#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
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

pthread_t enq_funct(qu_t *q)
{
	pthread_t enq_thread1;
	int ret;
		
	ret=pthread_create(&enq_thread1,NULL,&enq_worker,q);
	if(ret!=0)
	{
		printf("Thread creation fails\n");
	}
	else
	{
		printf("Thread created successfully\n");
	}
        sleep(3);
}





