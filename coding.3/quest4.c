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
                execl("/bin/ls", "/bin/ls", NULL);
        } else {
                printf("me the parent");
        }
        return 0;
}
/*********************************************
Your name: Mahmoud Amer
Question 1: I think there are so many variants for somewhat different purposes as the different formats of the arguments provided to the process executed.
*********************************************/
