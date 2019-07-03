#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include"mythreads.h"

pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond1 =PTHREAD_COND_INITIALIZER;

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
//		sleep(2);
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
/*	printf("Enq acquiring lock\n");
	pthread_mutex_lock(&lock);
	printf("Signaling the thread\n");
	pthread_cond_signal(&cond1);*/

	t1=enq_funct(q);

	//printf("Enq releasing the lock\n");
	//pthread_mutex_unlock(&lock);

	//      pthread_join(t1,NULL);
	//      pthread_join(t2,NULL);
	printf("Deq acquiring the lock\n");
	pthread_mutex_lock(&lock);

	printf("Dqu Waiting on conditional variable\n");
	pthread_cond_wait(&cond1,&lock);

	printf("called deq thread which was waiting\n");
	pthread_cond_signal(&cond1);

	printf("Dqu releasing lock\n");
	pthread_mutex_unlock(&lock);


	while(1)
	{
		deq_worker(q);

	}


	free(q);
}




