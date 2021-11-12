#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	FILE *fptr;
	char line[50];
	pid_t pid = fork();
	fptr = fopen("number.txt","r");
	int count = 0;
	//pid_t pid = fork();
	while(fgets(line, 50, fptr)) {
		//printf("%s", line);
		if(pid == 0) {
			//printf("child: %d\n", pid);
			if(atoi(line) % 3 == 0) {
				count++;
			}	
		}
		else if(pid >0) {
			//printf("parent: %d\n",pid);
			if(atoi(line) %2 == 0) {
				count++;
			}
		}
	}
	fclose(fptr);
	if(pid == 0) {
		printf("%d\n", count);
	}
	else if(pid>0) {
		printf("%d\n", count);
		wait(NULL);
	}
}
