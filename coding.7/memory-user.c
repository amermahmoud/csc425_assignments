#include <stdlib.h>
#include <stdio.h>
int main(int argc, char* argv[]){
	size_t mem_input = atoi(argv[1]);
	size_t mem_value = (mem_input*1024*1024)/sizeof(int);
	int mem_array[mem_value];
	while(1){
		for (int i =0; i<mem_value; i++){
			mem_array[i]= i;
		}
	}
	return 0;
}
