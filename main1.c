#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include"operation.h"
#include"queue.h"

void* enq_worker(void* data)
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
	fnc_t fn;
	qu_t *q;
	q=(qu_t*)malloc(sizeof(qu_t));
	init_que(q);
	int ret;
	pthread_t thread1;

	ret=pthread_create(&thread1,NULL,&enq_worker,q);
	if(ret!=0)
	{
		printf("Thread creation fails\n");
	}
	else
	{
		printf("Thread created successfully\n");
	}

	while(1)
	{
		fn=dequeue(q);
		if(fn.fvar==NULL)
		{
			printf("Not pointing to any function\n");
		}
		else
		{
			fn.fvar(fn.args);
		}
		sleep(2);
	}
		
}




