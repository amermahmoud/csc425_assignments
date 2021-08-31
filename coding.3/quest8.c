#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
   	int fd[2];
        char string[] = "Hello, world!\n";
	char readbuffer[80];
	pipe(fd);
        int rc = fork();
        if (rc < 0) {
                // fork failed
                fprintf(stderr, "fork failed\n");
                exit(1);
        } else if (rc == 0) {
                close(fd[0]);
                write(fd[1], string, (strlen(string)+1));
                exit(0);
        } else {
		int rc2 = fork();
		if (rc2 == 0){
			close(fd[1]);
               		 read(fd[0], readbuffer, sizeof(readbuffer));
               		 printf("Received string: %s", readbuffer);
       		}
	 }
        return 0;
}
/*********************************************
Your name: Mahmoud Amer
was stuck and got help from https://tldp.org/LDP/lpg/node11.html
*********************************************/
