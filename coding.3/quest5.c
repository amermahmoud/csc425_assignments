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
                printf("me the child \n");
        } else {
		int rc_wait = wait(NULL);
                printf("me the parent waiting on child number: %d \n",rc_wait);
        }
        return 0;
}
/*********************************************
Your name: Mahmoud Amer
Question 1: wait() returns the process id of the child being waited on if it was successful, if not it will return -1.
Question 2: Since the child process doesn't have any children it will return -1.
*********************************************/
