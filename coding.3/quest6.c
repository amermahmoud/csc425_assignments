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
		int status;
                int rc_wait = waitpid(rc,&status,0);
                printf("me the parent waiting on child number: %d \n",rc_wait);
        }
        return 0;
}
/*********************************************
Your name: Mahmoud Amer
Question 1: waitpid() would be useful when the parent process has more than one child and we want to wait on a specific one by pid.
was stuck and received help through https://github.com/yorwos/OSTEP-Solution/blob/master/Chapter%205/question6.c
*********************************************/
