#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void *garbage_collected_malloc(size_t size) {
  void *p = malloc(size);
  free(p);
  return p;
}

int main(int argc, char **argv) {
    char *buf;
    int i;

    if (argc < 2) {
        fprintf (stderr, "\nUsage: %s <string>\n", argv[0]);
        exit (1);
    }
    printf("Input string: %s\n", argv[1]);
    buf = (char *) garbage_collected_malloc(10);
    strncpy(buf, argv[1], 10);
    for (i=0; i< 10 ; i++) {
    buf[i] = toupper(buf[i]);
    }
    printf("Output string: %s\n", buf);
    return 0;
}