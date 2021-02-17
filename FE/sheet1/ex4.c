#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define SIZE 12

int main(){
	int fd = open("test.txt", O_RDONLY, 0);
	char str[SIZE];
	int n_bytes = read(fd, str, SIZE);
	for(int i = 0; i < n_bytes; ++i){
		printf("%c", str[i]);
	}
}