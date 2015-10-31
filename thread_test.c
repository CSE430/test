// Amjad Alqahtani  & Yvette Banuelos-Gonzalez
// CSE430 M W 6pm
// Project 2
//Using the queuing routines (not all will be used) this project will implement the ability to run multiple functions 
//as threads,using non-preemptive scheduling.
//---------------------------------------------------------------------------------------------------------------------


#include "threads.h"
int i = 0; // global variable increments with each run 



// this functions increment the global variable and a local variable by 1
void fun_1() {
	int j = 0;  //local variable 
	
	printf(" Entered Function 1");
	while (1) {
		printf("Function 1:\tglobal variable: %d\tlocal variable: %d\n", i, j);
		i++;
		j++;
		
		yield();
	}

}



// this functions increment the global variable by 1 and decrement the local variable by 1 
void fun_2() {
	int j = 400;  //local variable 

	printf(" Entered Function 2");
	while (1) {
		printf("Function 2:\tglobal variable: %d\tlocal variable: %d\n", i, j);
		i++;
		j--;

		yield();
	}

}


//this functions increment the global variable by 1 and the local by a Multiple of 2
void fun_3() {
	int j = 1;  //local variable 

	printf(" Entered Function 3");
	while (1) {
		printf("Function 3:\tglobal variable: %d\tlocal variable: %d\n", i, j);
		i++;
		j*=2;

		yield();
	}

}

//this functions increment the global variable by 1
// the local is a char and it increments to the next alohabet from a to z
void fun_4() {
	char j = 'a';  //local variable 

	printf(" Entered Function 4");
	while (1) {
		printf("Function 4:\tglobal variable: %d\tlocal variable: %d\n", i, j);
		i++;


		if (j == 'z')
			j = 'a';

		j = j + 1;


		yield();
	}

}

int main() {
	runQ = (struct q*) malloc(sizeof(struct q));
	initQueue(runQ);

	// start threads 
	startThread(fun_1);
	startThread(fun_2);
	startThread(fun_3);
	startThread(fun_4);
	run();

	return 0;
}