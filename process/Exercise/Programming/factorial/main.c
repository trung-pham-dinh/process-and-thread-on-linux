#include <stdio.h>
#include "readline.h"
#include "factorial.h"

int main(int argc, char* argv[]) {
	printf("Input: ");
	char str[50];
	scanf("%s", str);

	//printf("%d\n", factorial(0));
	int ret = read_line(str);
	if(ret) {
		printf("%d\n", factorial(atoi(str)));
	}
	else {
		printf("%d\n",-1);
	}
}
