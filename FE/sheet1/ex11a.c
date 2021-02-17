#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 64

int main(int argc, char *argv[]){
	if(argc != 3){
		printf("Invalid number of arguments\n");
		return 1;
	}

	int in_fd = open(argv[1], O_RDONLY);
	int out_fd = open(argv[2], O_WRONLY | O_CREAT);
	if(in_fd<0 || out_fd<0){
		return 1;
	}

	unsigned int bytes_read;
	char buffer[BUF_SIZE];
	while((bytes_read = read(in_fd, buffer, BUF_SIZE)) != 0){
		write(out_fd, buffer, bytes_read);
	}

	close(in_fd);
	close(out_fd);
	return 0;
}