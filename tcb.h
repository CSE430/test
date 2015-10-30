#include <ucontext.h>
#include <stdio.h>
#include <string.h>

// queue items element
typedef struct TCB_t
{
	struct TCB_t *previous_element; //pointer to previous element in queue
	struct TCB_t *next_element; //pointer to next element in queue
	ucontext_t context; //stores a thread context
} TCB_t;

/*Used to initialize a TCB for a new thread. The arguments to init_TCB are:
   1. pointer to the function, to be executed
   2. pointer to the thread stack
   3. size of the stack
*/
void init_TCB (TCB_t *tcb, void *function, void *stackP, int stack_size)
{
    memset(tcb, '\0', sizeof(TCB_t));       // wash, rinse
    getcontext(&tcb->context);              // have to get parent context, else snow forms on hell
    tcb->context.uc_stack.ss_sp = stackP;
    tcb->context.uc_stack.ss_size = (size_t) stack_size;
    makecontext(&tcb->context, function, 0);// context is now cooked
}
