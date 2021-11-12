#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

const int NUM_THREAD = 5;

int circle_point = 0;
unsigned int npoint;

void* count(void* remainder) {
	double x,y;
	for(int i = 0+(unsigned long)remainder; i < npoint; i+=NUM_THREAD) {
		x = (double)(random()%1001)/1000;
		y = (double)(random()%1001)/1000;
		if(x*x + y*y < 1.0) {
			circle_point++;
		}
	}
}

int main(int argc, char* argv[]) {
	srandom(time(NULL));

	if(argc < 2) return -1;
	npoint = atoi(argv[1]);
	
	
	pthread_t tid[NUM_THREAD];
	for(unsigned long i =0; i < NUM_THREAD; i++) {
		pthread_create(&tid[i], NULL, count, (void*)i);
	}	
	for(int i = 0; i < NUM_THREAD; i++) {
		pthread_join(tid[i], NULL);
	}
	

	double pi = (double)4*circle_point/npoint;
	printf("pi = %.4f\n", pi);
}
