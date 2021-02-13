#include<stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int file_size(const char *file){
	struct stat st;
	if(stat(file, &st) == 0){
		return st.st_size;
	}
	return -1;
}


int main(int argc, char *argv[]){
	if(argc != 2){
		printf("Invalid number of arguments.");
		return 1;
	}
	DIR *dir = opendir(argv[1]);
	if(dir){
		struct dirent *ent;
		printf("%s\n", argv[1]);
		while((ent = readdir(dir)) != 0){
			printf ("  | %s : %d\n", ent->d_name, file_size(ent->d_name));
		}
		closedir(dir);
	}
	else{
		perror("Couldn't open directory.");
		return 1;
	}
	return 0;
}