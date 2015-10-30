/* Functions that need to be included in this file
	1.	item = NewItem(); // returns a pointer to a new q-element
	2.	InitQueue( &head) // creates a empty queue, pointed to by the variable head.
	3.	AddQueue(&head, item) // adds a queue item, pointed to by “item”, to the queue pointed to by head.
	4.	item = DelQueue(&head) // deletes an item from head and returns a pointer to the deleted item
	5.	RotateQ(&head) // Moves the header pointer to the next element in the queue. This is equivalent to 
	    AddQ(&head, DeleteQ(&head)), but is simpler to use and more efficient to implement.
*/
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <io.h>

#include "tcb.h"


struct TCB_t* NewItem();
void q * InitQueue(q *head);
void AddQueue(struct q *head, struct TCB_t *item);
struct TCB_t*  DelQueue(struct q *head);
void RotateQ(q *head);
void printQ(q *head); 



typedef struct q
{
	struct TCB_t *header;
}q;

// returns a pointer to a new q-element
struct TCB_t* NewItem()
{
	struct TCB_t new_Item = (struct TCB_t*) malloc(sizeof(struct TCB_t));
	
	// Initialization of elements
	if(!new_Item)
	{
		new_Item->previous_element = NULL;
		new_Item->next_element = NULL;
	}
	
	return new_Item;
}

// creates an empty queue pointed to by the variable head
void q * InitQueue(q *head)
{
	head->header =  NULL;	
}

// adds a queue item, pointed to by “item”, to the queue pointed 
// to by head.
void AddQueue(struct q *head, struct TCB_t *item)
{
	if(head->header != NULL)
	{
		// Queue with one element (header)
		if(head->header->next_element == NULL)
		{
			head->header->next_element = item;
			head->header->previous_element = item;
			item->next_element = head->header;
			item->previous_element = head->header;
			cout << "passed 3 ";
		}
		
		// Queue with multiple items
		else
		{
			head->header->previous_element->next_element = item;
			head->header->previous_element = item;
			item->next_element = head->header;
			item->previous_element = head->header->previous_element;
			cout << "passed 3 ";
		}	
		
	}
	
	// Empty queue
	else 
	{
		q_head = item;
		head->header = item;
		item->next_element = NULL;
		item->previous_element = NULL;
		cout << "passed 1 ";
	}
}

// deletes an item from head and returns a pointer 
// to the deleted item
struct TCB_t*  DelQueue(struct q *head)
{
	struct TCB_t *q_head_deleted = head->header;
	
	if(head->header != NULL)
	{
		if(head->header->next_element != NULL)
		{
			head->header->previous_element->next_element = head->header->next_element;
			head->header->next_element->previous_element = head->header->previous_element;
			head->header = head->header->next;
		}
		else
		{
			head->header = NULL;
		}
	}
	return q_head_deleted;
}

// Moves the header pointer to the next element in the queue. This is equivalent to 
// AddQ(&head, DeleteQ(&head)), but is simpler to use and more efficient to implement.
void RotateQ(q *head)
{
	AddQueue(head, DelQueue(head));
}

void printQ(q *head) 
{
	q_element *item = head->header;

	if (head->header != NULL) 
	{
		if (head->header->next_element != NULL) 
		{
			q_element *last = head->header->previous_element;
			while (item != NULL && (item->payload != last->payload)) 
			{
				cout << "payload: " << item->payload << "\n";
				item = item->next_element;
			}
		}
	
		if (item != NULL) 
		{
			cout << "payload: " << item->payload;
		}
		cout << "\n";
	}
	
	else 
	{
		cout << "Empty Queue \n";
	}

	return;
}

