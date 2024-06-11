#include <stdio.h>
#include <stdlib.h>

/*
The standard library function calloc(n,size) returns a
pointer to n objects of size size, with the storage
initialized to zero. Write calloc, by calling malloc or
by modifying it.
*/


void *calloc_(unsigned, unsigned);


int main(int argc, char *argv[]){
	int *p = NULL;
	int i = 0;

	p = calloc_(100, sizeof *p);
	if(p == NULL)
		printf("NULL");

	else {
		for(i = 0; i <= 100; i++){
			printf("%x", p[i]);
			if(i % 8 == 7){
				printf("\\\n");
			}
		}
		printf("\n");
		free(p);
	}

	return 0;
}


void *calloc_(unsigned n, unsigned size){
	unsigned i, nb;
	char *p, *q;
	nb = n * size;

	if((p = q = malloc(nb)) != NULL)
		for(i = 0; i < nb; i++)
			*p++ = 0;
	return q;
}

