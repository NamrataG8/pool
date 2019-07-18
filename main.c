#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include"operation.h"
#include"queue.h"
#include"pool.h"

void even_num(void* data)
{
	int d = *(int*)data;
	for(int i=0;i<d;i++)
	{
		if(i%2 == 0)
		{
			printf("%d\n",i);
			sleep(1);
		}
	}
}

void odd_num(void* data)
{        
	int *d = (int*)data;
	for(int i=0;i<*d;i++)
	{
		if(i%2 != 0)
		{
			printf("%d\n",i);
			sleep(1);
		}
	}
}

int main()
{
	pool_t *p;
	int itr = 30;
	unsigned int n;
	p = (pool_t*)malloc(sizeof(pool_t));
	if(p == NULL)
	{
		return -1;
	}
	printf("Enter no. of threads\n");
	scanf("%u",&n);

	init_pool(p,n);
	
//	sleep(2);
	printf("submit even function\n");
	submit(p, even_num, &itr);
	printf("Submit odd function\n");
	submit(p, odd_num, &itr);
	
	deinit_pool(p);
	return 0;
}




