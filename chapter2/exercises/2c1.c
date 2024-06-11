#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include <float.h>

#define VTAB '\013'
#define BELL '\007'

int getlenght(char line[]);

int main(void){
	printf("Minimum Signed Char %d\n", -(int)((unsigned char)~1 >> 1) - 1);
	printf("Maximum Signed Char %d\n", (int)((unsigned char)~1 >> 1));


	printf("Minimum Signed Int %d\n", -(int)((unsigned int)~1 >> 1) - 1);
	printf("Maximum Signed Int %d\n", (int)((unsigned int)~1 >> 1));

	// etc...
}

