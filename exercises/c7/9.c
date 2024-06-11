#include <stdio.h>

/*
Functions like isupper can be implemented to save
space or to save time. Explore both possibilities.
*/

int isupper_(int);

int main(void){
	int c;
	while((c = getchar()) != 'x'){
		if(c == '\n')
			continue;

		if(isupper_(c) == 1)
			printf("%c => Uppercase\n", c);
		else
			printf("%c => Lowercase\n", c);
	}
	return 0;
}

int isupper_(int c){
	if(c >= 'A' && c <= 'Z')
		return 1;
	return 0;
}

