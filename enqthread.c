#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include"mythreads.h"

void* enq_worker(void *data)
{

//	threadpool_t *pool;
//        pool=(threadpool_t*)malloc(threadpool_t); 

	qu_t *q=(qu_t*)data;
	pool p;

	printf("Enq acquiring the lock\n");
	pthread_mutex_lock(&(p.lock));

	while(1)
	{
//		if(pool->queue->front==NULL)
//		{
		
		enqueue(q,task_to_perform,NULL);
			
		printf("waking up the enqueue thread\n");
		pthread_cond_signal(&(p.cond1));
//		}


		printf("Enq releasing lock\n");
		pthread_mutex_unlock(&(p.lock));

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





