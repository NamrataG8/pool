#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include"mythreads.h"


void* deq_worker(void *data)
{
	fnc_t fn;
	qu_t *q=(qu_t*)data;
	while(1)
	{

		fn=dequeue(q);

		if(fn.fvar==NULL)
		{
			printf("Not pointing to any function\n");
		}
		else
		{
			fn.fvar(fn.args);//
		}
		sleep(2);
	}
}
void main()
{
	qu_t *q;
	q=(qu_t*)malloc(sizeof(qu_t));
	init(q);
	int ret;
	pthread_t t1;
	printf("Enqueuing\n");

	t1=enq_funct(q);

	//      pthread_join(t1,NULL);
	//      pthread_join(t2,NULL);
	while(1)
	{
		deq_worker(q);

	}

	free(q);
}




