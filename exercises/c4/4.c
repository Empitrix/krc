#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
Add the commands to print the top elements of the stack without popping,
to duplicate it, and to swap the top two elements. Add a command to clear
the stack.
*/


// from internet and (K%R C) book

#define MAXOP 100
#define NUMBER '0'
#define BUFSIZE 100
#define MAXVAL 100

int sp = 0;
int bufp = 0;

double val[MAXVAL];
char buf[BUFSIZE];

int getch(void);
void ungetch(int);
int getop(char[]);
void push(double);
double pop(void);
void clear(void);

/* reverse polish calculator */
int main(void) {
	int type;
	double op1, op2;
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

			// from ./3.c
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push(fmod(pop(), op2));
				else
					printf("erro:zero divisor\n");
				break;
			// new part

			case '?':
				op2 = pop();
				printf("\t%.8g\n", op2);
				push(op2);
				break;

			case 'c':
				clear();
				break;

			case 'd':
				op2 = pop();
				push(op2);
				push(op2);
				break;

			case 's':
				op1 = pop();
				op2 = pop();
				push(op1);
				push(op2);
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



void clear(void){ sp = 0; }

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

int getop(char s[]) {
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t');
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-')
		return c; // not a number
	i = 0;
	if (c == '-' || isdigit(c)) // collect integer part along with '-'
		while (isdigit(s[++i] = c = getch()));
	if (c == '.') // collect fraction part
		while (isdigit(s[++i] = c = getch()));
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	if (strcmp(s, "-") == 0)
		return '-';
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

