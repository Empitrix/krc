#include <stdio.h>
#include <stdlib.h>

/*
Adapt the ideas of printd to write a recursive version of itoa;
that is, convert an integer into a string by
calling a recursive routine.
*/

// explain: int to array:char

#define MAXLINE 1000

void itoa(int, char []);

int main(void){

	char line[MAXLINE];

	itoa(12345, line);

	printf("Line: %s\n", line);
	return 0;
}


void itoa(int n , char s[]){
	static int idx = 0;  // to save the state of the function

	if((n / 10) != 0){  // the do-while condition
		itoa(n / 10, s);
	}

	else{
		// execute only for once
		if(n < 0)
			s[idx++] = '-';
	}

	s[idx++] = abs(n) % 10 + '0';
	s[idx] = '\0';
}
