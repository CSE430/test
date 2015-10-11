#include "q.h"
//#include<iostream>
//using namespace std;

/* Write test routines that thoroughly test the queue implementation.
Use multiple queues. Pay special attention to deleting the last element
of a q. Also make sure “RotateQ” is behaves properly (strange behavior
of this routine means the insert/delete routines have bugs.)

Further warning: Bugs in the Q routines have been the #1 cause for strange
errors in the project, always. Careful that you get it right, else things will
go bump later.
*/

int main() {
	int i = 0;
	q* head = new q();

	InitQueue(head);
	cout << " now we create 4 elemnets \n ";
	for (i = 0; i < 3; i++) {
		 q_element *item = NewItem();
		item->payload = i;
		AddQueue(head, item);
	}

	cout << "now we print out queue \n";
	printQ(head);

	cout << "now we rotate queue and print out the queue in the new form \n";
	RotateQ(head);
	printQ(head);


	cout << "now we delete queue item and print out the queue in the new form \n";
	DelQueue(head);
	printQ(head);


	cin.get();
	return 0;



}
