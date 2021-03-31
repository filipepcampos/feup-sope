#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include<stdio.h>

int main(){
	int id = fork();
	if(id == 0){
		printf("Hello ");
	}
	else{
		int *status;
		waitpid(id, status, 0);
		printf("World!");
	}
	return 0;
}
