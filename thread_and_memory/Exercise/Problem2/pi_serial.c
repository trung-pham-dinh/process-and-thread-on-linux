#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	srandom(time(NULL));
	
	if(argc < 2) return -1;
	unsigned int npoint = atoi(argv[1]);

	int circle_point = 0;
	double x,y;
	for(unsigned int i = npoint; i > 0; i--) {
		x = (double)(random()%1001)/1000;
		y = (double)(random()%1001)/1000;
		//printf("%.3f, %.3f\n", x, y);
		if(x*x + y*y < 1.0) {
			circle_point++;
		}
	}
	double pi = (double)4*circle_point/npoint;
	printf("pi = %.4f\n", pi);
}
