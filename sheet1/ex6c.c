#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(){
	// touch test.txt && sudo chmod 000 test.txt to cause an failure
	int fd = open("test.txt", O_CREAT, 0);
	if(fd == -1){
		perror("This is a failure!\n");
	}
	return 0;
}