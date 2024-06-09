#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

/*
Write the function itob(n,s,b) that converts the
integer n into a base b character representation
in the string s. In particular, itob(n,s,16)
formats s as a hexadecimal integer in s.
*/

void reverse(char s[]);
void itoa(int n, char s[], int base);


int main(void){
	char line[MAXLINE];
	itoa(10, line, 16);
	printf("%s\n", line);
	return 0;
}


void itoa(int n, char s[], int base){
	int i;

	n = abs(n); // make it positive

	do {

		// on base
		if((n%base) > 9)
			s[i++] = (n % 10) + 'A' - 10;

		else
			s[i++] = (n % 10) + '0';
	} while((n /= 10) != 0);

	s[i] = '\0';

	reverse(s);
}


void reverse(char s[]) {
	int c, i, j;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
}

