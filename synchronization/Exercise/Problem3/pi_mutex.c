#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

const int NUM_THREAD = 5;

pthread_mutex_t lock;
unsigned int circle_point = 0;
unsigned int npoint;

void* count(void* remainder) {
	double x,y;
	pthread_mutex_lock(&lock);
	int count = 0;
	for(int i = 0+(unsigned long)remainder; i < npoint; i+=NUM_THREAD) {
		x = (double)(random()%1001)/1000;
		y = (double)(random()%1001)/1000;
		//printf("i: %d, ", i);
		if(x*x + y*y < 1.0) {
			count++;
			//printf("count: %d\n", circle_point
		}
		//printf("\n\n");
	}
	circle_point += count;
	pthread_mutex_unlock(&lock);
}

int main(int argc, char* argv[]) {
	srandom(time(NULL));

	if(argc < 2) return -1;
	npoint = atoi(argv[1]);
	
	pthread_mutex_init(&lock, NULL);				
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
