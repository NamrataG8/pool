#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include"queue.h"
#include"operation.h"
#include"pool.h"

void init_que(qu_t *q)
{
	q->front=NULL;    
	q->rear=NULL;
}

int enqueue(qu_t *q,const operation f_var, void *data) 
{
	node_t *newnode;

	newnode=(node_t*)malloc(sizeof(node_t));   
 	 
	if(newnode ==NULL)
	{

		return -1;
	}

	newnode->next=NULL;                        

	newnode->fn.fvar = f_var;                    
	newnode->fn.args = data;                     

	if(q->front == NULL)
	{
		q->front = q->rear = newnode;
	}
	else
	{
		q->rear->next = newnode;
		q->rear = newnode;
	}
	printf("Enqueing is successfull\n");
	return 0;
}

void clear(qu_t *q)
{
	node_t *del;
	while(q->front!=NULL)
	{
		del = q->front;
		q->front = q->front->next;
		free(del);
	}
	printf("Memory cleared\n");
}

fnc_t dequeue(qu_t *q)     
{
	node_t *temp;

	fnc_t fn={NULL,NULL};

	if(q->front == NULL)
	{
		printf("Queue is empty\n");
	}
	else
	{
		temp=q->front;
		q->front = q->front->next;
		fn=temp->fn;           
		free(temp);
	
	printf("Dequeuing success\n");
	}
	return fn;
}




	

