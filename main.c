#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include"operation.h"
#include"queue.h"
#include"pool.h"

void task_to_perform(void *data)
{
        printf("Operation\n");
}



int main()
{

	pool_t *p;
	unsigned int n;
	p = (pool_t*)malloc(sizeof(pool_t));
	if(p == NULL)
	{
		return -1;
	}
	printf("Enter no. of threads\n");
	scanf("%u",&n);

	init_pool(p,n);
	
	while(1)
	{
		sleep(2);
		printf("submit function\n");
		submit(p,task_to_perform,NULL);
	}

	deinit_pool(p);
	return 0;
}




