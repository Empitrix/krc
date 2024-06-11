#include <ctype.h>
#include <stdio.h>
/*
Write getfloat, the floating-point analog of getint.
What type does getfloat return as its function value?
*/

#define BUFSIZE 1000
#define SIZE 1000

int getch(void);
void ungetch(int c);
int getint(int *pn);
int getfloat(float *pn);


int main(void){
	int n;
	float array[SIZE];

	for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++);
	for (; n >= 0; n--)
			printf("%f", array[n]);

	return 0;
}


char buf[BUFSIZE];
int bufp = 0;


int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}


void ungetch(int c) {
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}


// BOOK's GETINT
int getint(int *pn) {
	int c, sign;
	while (isspace(c = getch())) /* skip white space */
		;

	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c); /* it is not a number */
		return 0;
	}

	sign = (c == '-') ? -1 : 1;

	if (c == '+' || c == '-')
		c = getch();

	for (*pn = 0; isdigit(c), c = getch(); )
		*pn = 10 * *pn + (c - '0');

	*pn *= sign;

	if (c != EOF)
		ungetch(c);

	return c;
}






int getfloat(float *pn) {
	int c, sign;
	float power;

	while (isspace(c = getch()));

	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1 : 1;

	if (c == '+' || c == '-')
		c = getch();

	for (*pn = 0.0; isdigit(c); c = getch())
		*pn = 10.0 * *pn + (c - '0');

	// [S]float new part 
	if (c == '.')
		c = getch();

	for (power = 1.0; isdigit(c); c = getch()) {
		*pn = 10.0 * *pn + (c - '0');	/* fractional part */
		power *= 10.0;
	}
	// [E]float new part 

	*pn *= sign / power;

	if (c != EOF)
		ungetch(c);

	return c;
}
