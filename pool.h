#ifndef POOL_H
#define POOL_H

#include"operation.h"
#include"queue.h"
typedef struct 
{
	pthread_mutex_t lock;
	pthread_cond_t cv;
	qu_t q;
	pthread_t *threads;
	unsigned int num_threads;
	int flag;
	
}pool_t;

int init_pool(pool_t*,unsigned int);

void deinit_pool(pool_t*);

int submit(pool_t*,const operation, void*);



#endif
