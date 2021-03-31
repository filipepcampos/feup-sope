#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int i = 60;
    while(i-- > 0){
        size_t size = (size_t)5e7;
        char *p = malloc(size);
        memset(p, 'A', size);
        sleep(1);
    }
}