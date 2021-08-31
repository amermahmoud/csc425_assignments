#include <stdio.h>
int main(){
	int x  = 420;
	int rc = fork();
	if (rc == 0){
		x = 22;
		printf("Child value: %d \n",x);
	}
	else if (rc>0){
		printf("Parent value: %d \n",x);
	}
	return 0;
}
/*********************************************
Your name: Mahmoud Amer
Question 1: The value in the child process is the same as it was in the parent process (420).
Question 2: Each process has its own memory and don't change the value in the other process.
*********************************************/
