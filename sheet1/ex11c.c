#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 64

// Adapted from ex11a
int ex11a(int argc, char *argv[]){
	if(argc != 3 && argc != 2){
		printf("Invalid number of arguments\n");
		return 1;
	}

	int in_fd = open(argv[1], O_RDONLY);
	int out_fd = argc == 2 ? 0 : open(argv[2], O_WRONLY | O_CREAT);
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

// Adapted from ex11b
int ex11b(int argc, char *argv[]){
	if(argc != 3 && argc != 2){
		printf("Invalid number of arguments\n");
		return 1;
	}
	FILE *in_stream = fopen(argv[1], "r");
	FILE *out_stream = argc == 2 ? stdout : fopen(argv[2], "w");
	if(!in_stream || !out_stream){
		return 1;
	}

	int bytes_read;
	char buffer[BUF_SIZE];
	while((bytes_read = fread(buffer, sizeof(char), BUF_SIZE, in_stream)) != 0){
		fwrite(buffer, sizeof(char), bytes_read, out_stream);
	}
	fclose(in_stream);
	fclose(out_stream);
}

// Adapted from ex11b
int main(int argc, char *argv[]){
	//ex11a(argc, argv);
	ex11b(argc, argv);
}