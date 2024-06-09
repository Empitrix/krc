#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000
/*
Write a version of itoa that accepts three arguments instead of two.
The third argument is a minimum field width; the converted number
must be padded with blanks on the left if necessary to make it wide enough.
*/

// prototypes
void itoa(int n, char s[], int width);
void reverse(char s[]);
void testcase(char* msg, int num, int with);


int main(void){

	testcase("Positive(free space)", 100, 5);
	testcase("Negative(free space)", -100, 5);

	testcase("Positive(limited space)", 100, 2);
	testcase("Negative(limited space)", -100, 2);

	return 0;
}


void testcase(char* msg, int num, int with){
	char line[MAXLINE];
	printf("%s:\n", msg);
	itoa(num, line, with);
	printf(">%s<\n\n", line);
}



/* itoa: convert n to characters in s */
void itoa(int n, char s[], int width) {
	int i, is_negative;
	i = is_negative = 0;

	if(n < 0)
		is_negative = 1;

	do {
		s[i++] = abs(n % 10) + '0';
	} while((n /= 10) != 0);       // get one digit at a time

	if(is_negative)
		s[i++] = '-';

	// add padding by width
	while(i < width)
		s[i++] = ' ';


	s[i] = '\0';

	reverse(s);
}



void reverse(char s[]) {
	int c, i, j;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
}

