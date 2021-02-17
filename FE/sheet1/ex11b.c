#include<stdio.h>

#define BUF_SIZE 64

int main(int argc, char *argv[]){
	if(argc != 3){
		printf("Invalid number of arguments\n");
		return 1;
	}
	FILE *in_stream = fopen(argv[1], "r");
	FILE *out_stream = fopen(argv[2], "w");
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