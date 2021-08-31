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
                printf("Hello");
        } else {
		int rc_wait = wait(NULL);
                printf("Goodbye");
        }
        return 0;
}
/*********************************************
Your name: Mahmoud Amer
Question 1: no because otherwise the output will be undeterministic and the parent might end up going first before the child.
*********************************************/
