#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(){
	int pp1[2];
	int pp2[2];
	if(pipe(pp1) == -1 || pipe(pp2) == -1){
		printf("BLYAT this is an error, this no good\n");
		exit(1);
	}
	int id = fork();
	if(id == 0){
		char msg[1024];
		read(pp1[0], msg, 1024);
		write(pp2[1], "Systems", 1+strlen("Systems"));
		printf("%s Systems\n", msg);
	}
	else{
		char msg[1024];
		write(pp1[1], "Operating", 1+strlen("Operating"));
		read(pp2[0], msg, 1024);
		printf("Operating %s\n", msg);
	}
	return 0;
}