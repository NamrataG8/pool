#include<stdio.h>
#include<pthread.h>
#include"pool.h"
#include<stdlib.h>

//int flag = 0;
void* deq_worker(void *data)
{
	
	printf("inside deq_worker,1\n");
        fnc_t fn;
        pool_t *p=(pool_t*)data;

	//int ret = isque_empty(&p->q); 
        //printf("ret=%d, count=%d\n", ret, count);
        //while((isque_empty(&p->q) == 0) && (count <= p->num_threads))	

	while((isque_empty(&p->q) == 0) && (p->flag == 1))
        {

		printf("inside while loop\n");
        	pthread_mutex_lock(&(p->lock));

	        while(isque_empty(&(p->q)))
		{
               		pthread_cond_wait(&(p->cv),&(p->lock)); 
		}

                fn=dequeue(&(p->q));

        	pthread_mutex_unlock(&(p->lock));

                if(fn.fvar == NULL)
                {
                        printf("Not pointing to any function\n");
                }
                else
                {
                        fn.fvar(fn.args);
                }
	}
	
return 0;
	
}

int init_pool(pool_t* p,unsigned int n)
{
        init_que(&(p->q));
	p->threads=(pthread_t*)malloc(sizeof(pthread_t)*n);
	p->num_threads=n;
	if(p->threads == NULL)
        {
                return -1;
        }
	
	int ret = 0;
	for(int i=0;i<n;i++)
	{
		if(pthread_create(&(p->threads[i]),NULL,&deq_worker,p) < 0)
		{
			printf("Thread creation fails\n");
			ret = -1;
		}
	
	}
	
	return ret;
}

void deinit_pool(pool_t* p)
{
	p->flag = 0;	
	for(int i=0; i < p->num_threads; i++)
	{
		p->flag = 1;
		printf("in deinit : flag  =%d\n",p->flag);
		pthread_join(p->threads[i],NULL);

	}

	if(p->threads != NULL)
	{
		free(p->threads);
	}
}

int submit(pool_t *p,const operation op,void *data)
{
	int ret;
	pthread_mutex_lock(&(p->lock));

	ret=enqueue(&(p->q), op, data);

	pthread_cond_signal(&(p->cv));

	pthread_mutex_unlock(&(p->lock));
	return ret;
}












