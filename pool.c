#include<stdio.h>
#include<pthread.h>
#include"pool.h"
#include<stdlib.h>

void* deq_worker(void *data)
{
        fnc_t fn;

        pool_t *p=(pool_t*)data;
    
        while(1)
        {
        	pthread_mutex_lock(&(p->lock));

                pthread_cond_wait(&(p->cv),&(p->lock)); 

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

void wait_pool(pool_t *p)
{
}











