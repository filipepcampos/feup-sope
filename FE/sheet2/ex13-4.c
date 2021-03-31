#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>	

int main(){
	int id = fork();
	if(id == 0){
		char msg[1024];
		int np;
		np = open("./myfifo1", O_RDONLY);
		read(np, msg, 1024);
		printf("%s Systems\n", msg);
		close(np);
		np = open("./myfifo2", O_WRONLY);
		write(np, "Systems", 1 + strlen("Systems"));
		close(np);
	}
	else{
		int np;
		np = open("./myfifo1", O_WRONLY);
		write(np, "Operating", 1 + strlen("Operating"));
		close(np);
		np = open("./myfifo2", O_RDONLY);
		char msg[1024];
		read(np, msg, 1024);
		printf("Operating %s\n", msg);
		close(np);
	}
	return 0;
}