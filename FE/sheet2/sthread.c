/*
*	Example of threads in action
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define NTHREADS 3

void *rot(void *msg) {
	printf("%s", (char *)msg);
	pthread_exit(NULL);	// no termination code
}

int main() {
	pthread_t ids[NTHREADS];	// storage of (system) Thread Identifiers

	setbuf (stdout, NULL);	// only for debugging
	printf("\nMain thread PID: %d ; TID: %lu.\n", getpid(), (unsigned long) pthread_self());


	pthread_create(&ids[0], NULL, rot, "Operating ");
	pthread_create(&ids[1], NULL, rot, " System\n");

	// wait for finishing of created threads
	for(int i=0; i<NTHREADS; i++) {
		pthread_join(ids[i], NULL);	// Note: threads give no termination code
	}
	pthread_exit(NULL);	// here, not really necessary...
	return 0;	// will not run this!
	}
