


typedef struct
{
	pthread_mutex_t lock;
	pthread_cond_t cond1;
//      qu_t *queue;

}threadpool_t;


typedef void (*operation)(void *);

//sturcture contain function pointer and its arguments
typedef struct  
{
	operation fvar;   
	void* args;
}fnc_t;

//struct contain fun ptr data and pointer to next node
typedef struct node 
{

	fnc_t fn;           
	struct node *next;   
}node_t;

//struct contain pointer to front and rear node
typedef struct 
{
	node_t *front;     
	node_t *rear;
}qu_t;


void init(qu_t*);

void task_to_perform(void*);

void enqueue(qu_t*,const operation,void*);

void clear(qu_t*);

fnc_t dequeue(qu_t*);


pthread_t enq_funct(qu_t*);

pthread_t deq_funct(qu_t*);

