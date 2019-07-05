#include"operation.h"


typedef struct node
{
	fnc_t fn;
	struct node *next;
}node_t;

/*typedef struct
{
        operation fvar;
        void* args;
}fnc_t;*/


typedef struct 
{
	node_t *front;
	node_t *rear;
}qu_t;

void init_que(qu_t*);

void clear(qu_t*);

void enqueue(qu_t*,const operation,void*);

fnc_t dequeue(qu_t*);

void task_to_perform(void*);

