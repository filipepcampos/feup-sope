#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[], char **envp){
	for(char **env = envp; *env != 0; env++){
		char *current_env = *env;
		for(int i = 0; i < argc; ++i){
			if(strncmp(argv[i], current_env, strlen(argv[i])) == 0){
				printf("%s\n", current_env);
			}
		}
	}
	return 0;
}