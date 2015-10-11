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
#include<io.h>

using namespace std;

typedef struct q_element
{
	q_element *previous_element;
	q_element *next_element;
	int payload;
}q_element;

typedef struct q {
	q_element *header;
}q;



// returns a pointer to a new q-element
struct q_element* NewItem()
{
	//q_element *new_Element = (q_element*) malloc(sizeof(q_element)); //replace with new
	q_element *new_Element = new q_element();
	if (!new_Element) {
		new_Element->previous_element = NULL;
		new_Element->next_element = NULL;
	}

	return new_Element;
}

// creates an empty queue pointed to by the variable head
void InitQueue(q *head)
{
	head->header = NULL;
	return;
}

// adds a queue item, pointed to by “item”, to the queue pointed 
// to by head.
void AddQueue(q *head, q_element *item)
{
	q_element *q_head = head->header;

	if (q_head != NULL)
	{
		// Queue with one element (header)
		if (q_head->next_element == NULL)
		{	// check order 
			q_head->next_element = item;
			q_head->previous_element = item;
			item->next_element = q_head;
			item->previous_element = q_head->previous_element; // check 
			cout << "passed 2 ";
		}

		// Queue with multiple items
		else
		{
			q_head->next_element = item;
			q_head->previous_element = item;
			item->next_element = q_head;
			item->previous_element = q_head;
			cout << "passed 3 ";
		}

	}

	// Empty queue
	else
	{
		head->header = item;
		item->next_element = NULL;
		item->previous_element = NULL;
		cout << "passed 1 ";
	}
	return;
}

// deletes an item from head and returns a pointer 
// to the deleted item
q_element*  DelQueue(q *head)
{
	q_element *q_head_deleted = head->header;
	q_element *q_head_new = head->header;

	if (q_head_new != NULL)
	{
		if (q_head_new->next_element != NULL)
		{
			q_head_new->previous_element->next_element = q_head_new->next_element;
			q_head_new->next_element->previous_element = q_head_new->previous_element;

			q_head_new = q_head_new->next_element;
		}
		else
		{
			q_head_new = NULL;
		}
	}
	return q_head_deleted;
}

// Moves the header pointer to the next element in the queue. This is equivalent to 
// AddQ(&head, DeleteQ(&head)), but is simpler to use and more efficient to implement.
void RotateQ(q *head)
{
	AddQueue(head, DelQueue(head));
	return;
}


void printQ(q *head) {
	q_element *item = head->header;

	if (head->header != NULL) {

		if (head->header->next_element != NULL) {
			q_element *last = head->header->previous_element;


			while (item != NULL && (item->payload != last->payload)) {
				cout << "payload: " << item->payload << "\n";
				item = item->next_element;
			}
		}
	
		
		if (item != NULL) {
			cout << "payload: " << item->payload;
		}
		
		cout << "\n";
	}
	else {
		cout << "Empty Queue \n";
	}

	return;
}

