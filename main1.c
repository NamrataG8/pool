#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include"mythreads.h"

/*void init_pool()
  {
  pool p;
  p=(pool*)malloc(sizeof(pool));
//qu_t *q;
init_poolque(&p.queue);



}*/


void* deq_worker(void *data)
{

	//pool p=(pool*)data;
	fnc_t fn;
	pool p;
	qu_t *q=(qu_t*)data;
	while(1)
	{

		printf("Deq acquiring the lock\n");
		pthread_mutex_lock(&(p.lock));



		printf("Deq Waiting on conditional variable\n");

		while(q->front == NULL)
			pthread_cond_wait(&(p.cond1),&(p.lock));

		fn=dequeue(q);

		if(fn.fvar==NULL)
		{
			printf("Not pointing to any function\n");
		}
		else
		{
			fn.fvar(fn.args);
		}
		printf("Deq releasing lock\n");
		pthread_mutex_unlock(&(p.lock));
		//		sleep(2);
	}
}
void main()
{
	qu_t *q;
	q=(qu_t*)malloc(sizeof(qu_t));
	init_que(q);
	//	init_pool();

	pthread_t t1;
	//init_pool();
	pool p;
	printf("Enqueuing\n");

	//	t1=enq_funct(&p.queue); //submitting enqueu function to the pool queue
	t1=enq_funct(q);


	//pthread_join(t1,NULL);
	//pthread_join(t2,NULL);

	deq_worker(q);

	//	printf("Deq releasing lock\n");
	//	pthread_mutex_unlock(&(pool->lock));
	pthread_join(t1,NULL);

	//	free(q);
}




