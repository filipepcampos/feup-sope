#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(){
	int pp[2];
	if(pipe(pp) == -1){
		printf("BLYAT this is an error, this no good\n");
		exit(1);
	}
	int id = fork();
	if(id == 0){
		char msg[1024];
		close(pp[1]);
		read(pp[0], msg, 1024);
		printf("%s Systems\n", msg);
	}
	else{
		close(pp[0]);
		write(pp[1], "Operating", 1+strlen("Operating"));
	}
	return 0;
}