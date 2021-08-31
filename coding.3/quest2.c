#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	//redirect standard output to a file
        close(STDOUT_FILENO);
        open("./q2.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
	int rc = fork();
	if (rc < 0) {
		// fork failed
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) {
		printf("this is the child speaking");
	} else {
		printf("this is the parent speaking");
	}
	return 0;
}
/*********************************************
Your name: Mahmoud Amer
Question 1: YES, They both can access the file descriptor and write to the file.
Question 2: They can both write but I think the order can differ depending on which process writes first. Also they might mess up each other's writing.
*********************************************/
