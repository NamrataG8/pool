#ifndef OPERATION_H
#define OPERATION_H

typedef void(*operation)(void *);

typedef struct 
{
	operation fvar;
	void* args;
}fnc_t;

#endif



