#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
        int rc = fork();
        if (rc < 0) {
                // fork failed
                fprintf(stderr, "fork failed\n");
                exit(1);
        } else if (rc == 0) {
		//redirect standard output to a file
	        close(STDOUT_FILENO);
                printf("this is the child speaking");
        } else {
                printf("this is the parent speaking");
        }
        return 0;
}
/*********************************************
Your name: Mahmoud Amer
Question 1: nothing would happen, the child print statement will not show since we closed the standard output.
*********************************************/

