#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000
/*
In a two's complement number representation, our version of itoa
does not handle the largest negative number, that is, the value
of n equal to -(2wordsize-1). Explain why not. Modify it to print
that value correctly, regardless of the machine on which it runs.
*/

void itoa(int n, char s[]);
void reverse(char s[]);

int main(void){
	char line[MAXLINE];
	itoa(-150, line);
	printf("%s\n", line);
	return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[]) {
	int i, is_negative;
	i = is_negative = 0;

	if(n < 0)
		is_negative = 1;

	do {
		s[i++] = abs(n % 10) + '0';
	} while((n /= 10) != 0);       // get one digit at a time

	if(is_negative)
		s[i++] = '-';

	s[i] = '\0';

	reverse(s);
}


void reverse(char s[]) {
	int c, i, j;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
}

