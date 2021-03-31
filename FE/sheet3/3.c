#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void handler(int sig){
	printf("%d got %d\n", getpid(), sig);
}

int main(){
	signal(SIGINT, handler);
	signal(SIGUSR1, handler);
	int id = fork();	
	printf("I'm %d\n", getpid());
	if(id == 0){
		int id2 = fork();
		if(id2 == 0){
			printf("I'm %d\n", getpid());
		}
		else if(id2 > 0){
			printf("I'm parent of %d\n", id2);
		}
	}
	else if(id > 0){
		printf("I'm parent of %d\n", id);
	}
	sleep(10);
}