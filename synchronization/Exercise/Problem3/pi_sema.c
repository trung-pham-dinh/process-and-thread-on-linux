#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

const int NUM_THREAD = 5;

sem_t count_lock;
int circle_point = 0;
unsigned int npoint;

void* count(void* remainder) {
	double x,y;
	for(int i = 0+(unsigned long)remainder; i < npoint; i+=NUM_THREAD) {
		x = (double)(random()%1001)/1000;
		y = (double)(random()%1001)/1000;
		printf("i: %d, ", i);
		if(x*x + y*y < 1.0) {
			sem_wait(&count_lock);
			circle_point++;
			printf("count: %d\n", circle_point);
			sem_post(&count_lock);
		}
		printf("\n\n");
	}
}

int main(int argc, char* argv[]) {
	srandom(time(NULL));

	if(argc < 2) return -1;
	npoint = atoi(argv[1]);
	
	sem_init(&count_lock, 0, 1);				
	pthread_t tid[NUM_THREAD];
	for(unsigned long i =0; i < NUM_THREAD; i++) {
		pthread_create(&tid[i], NULL, count, (void*)i);
	}	
	for(int i = 0; i < NUM_THREAD; i++) {
		pthread_join(tid[i], NULL);
	}
							
	double pi = (double)4*circle_point/npoint;
	printf("pi = %.4f\n", pi);
	sem_destroy(&count_lock);
}
