#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include"mythreads.h"


//function to initialize front and rear pointer as NULL
void init(qu_t *q)
{
	q->front=NULL;    
	q->rear=NULL;
}

//fun ptr is pointing to this function
void task_to_perform(void *data)           
{
	printf("Operation\n");
}

/*arguments(front and rear ptr, function ptr variable, fun argument)
*creating a memory
*pointing newly created memory block to NULL
*giving fun ptr to fun ptr variab*/

void enqueue(qu_t *q,const operation f_var, void *data) 
{
	node_t *newnode;

	newnode=(node_t*)malloc(sizeof(node_t));   
	
	newnode->next=NULL;                        

	newnode->fn.fvar=f_var;                    
	newnode->fn.args=data;                     

	if(q->front==NULL)
	{
		q->front=q->rear=newnode;
	}
	else
	{
		q->rear->next=newnode;
		q->rear=newnode;
	}
	printf("Enqueing is successfull\n");
}

void clear(qu_t *q)
{
	node_t *del;
	while(q->front!=NULL)
	{
		del=q->front;
		q->front=q->front->next;
		free(del);
	}
	printf("Memory cleared\n");
}


fnc_t dequeue(qu_t *q)     //argument(pointer to front and rear)
{
	node_t *temp;

	fnc_t fn={NULL,NULL};

	if(q->front==NULL)
	{
		printf("Queue is empty\n");
	}
	else
	{
		temp=q->front;
		q->front=q->front->next;
		fn=temp->fn;           //deleted node in fn
		free(temp);
	
	printf("Dequeuing success\n");
	}
	return fn;
}

#if 0
void main()
{

	int choice;
	operation fp;
	qu_t q;

	init(&q);
	fnc_t fn;
	printf("Queue implementatio using linked list\n");

	while(1)
	{
		printf("========MENU=======\n");
		printf("1.Enqueue\n2.Dequeue\n3.Clear memory\n4.Exit\n");
		printf("Enter choice\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1: printf("Enqueuing\n");
				enqueue(&q,task_to_perform,NULL);
				break;

			case 2: fn=dequeue(&q);
				if(fn.fvar==NULL)
				{
					printf("Not pointing to any function\n");
				}
				else
				{
					fn.fvar(fn.args);//
				}
				break;
			case 3: clear(&q);
				break;

			case 4:exit(0);
			       break;

			default : printf("Wrong choice entered\n");
		}
	}
}

#endif



	

