#include "readline.h"

int read_line(char*str) {
	char *ptr = str;
	while(*ptr != 0 && *ptr != '\n') {
		if(*ptr >= '0' && *ptr <= '9') {
			//printf("char: %c\n", *ptr);
			ptr++;
		}
		else {
			//printf("char: %c\n", *ptr);
			return 0;
		}
	}
	return 1;
}
