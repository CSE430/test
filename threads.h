#include "q.h"

void startThread(void(*function)(void));
void run();
void yeild;

struct q *runQ;

/*
	 allocate a stack (via malloc) of a certain size (choose 8192)
     allocate a TCB (via malloc)
     call init_TCB with appropriate arguments
     call addQ to add this TCB into the “RunQ” which is a global header pointer
*/
void start_thread(void (*function)(void))
{ 
	int stack_size = 8192;

	void *stack = (void *)malloc(stack_size); //stack allocation
	TCB_t *temp_item = NewItem(); //TCB allocation

	init_TCB(temp_item, function, stack, stack_size);
	AddQueue(runQ, temp_item);
}

void run()
{   
	ucontext_t parent;     // get a place to store the main context, for faking
	getcontext(&parent);   // magic sauce
	swapcontext(&parent, &(RunQ->conext));  // start the first thread
}
 
/*	rotate the runQ;
	swap the context, from previous thread to the thread pointed to by RunQ
	*/
 void yield() 
{
   
}
