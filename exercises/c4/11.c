#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Modify getop so that it doesn't need to use ungetch.
Hint: use an internal static variable.
*/

/* Following code is from ./3.c && ./10.c */

#define MAXOP 100
#define NUMBER '0'
#define BUFSIZE 100
#define MAXVAL 100
#define MAXLINE 1000


int sp = 0;
int bufp = 0;

double val[MAXVAL];
char buf[BUFSIZE];

int getch(void);
void ungetch(int);
int getop(char[]);
void push(double);
double pop(void);
int mgetline(char s[], int lim);

/* reverse polish calculator */
int main(void) {
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error:zero divisor\n");
				break;

			// new part
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					printf("");
					// fmod(pop(), op2);
					// push(fmod(pop(), op2));
				else
					printf("erro:zero divisor\n");
				break;
			// old parts

			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}

void push(double f) {
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error:stack full, cant push %g\n", f);
}

double pop(void) {
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}


int li = 0;  /* input line index */
char line[MAXLINE];  /* one input line */

int getop(char s[]) {
	int c, i;
	static int lastc = 0;
	// 'lastc' only keeps 1 char (ASCII)

	if (lastc == 0)
		c = getch();
	else {
		c = lastc;
		lastc = 0;
	}

	while ((s[0] = c) == ' ' || c == '\t')
		c = getch();

	s[1] = '\0';

	if (!isdigit(c) && c != '.')
		return c;

	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()));
	if (c == '.')
		while (isdigit(s[++i] = c = getch()));
	s[i] = '\0';

	if (c != EOF)
		lastc = c;

	return NUMBER;
}



void ungetch(int c) {
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}



int mgetline(char s[], int lim) {
	int i, c;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

