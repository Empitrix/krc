#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
Add access to library functions like sin, exp, and pow. from <math.h>
*/


// from internet and (K%R C) book

#define MAXOP 100
#define NUMBER '0'
#define NAME 'n'
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
void mathfunc(char []);

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
			
			// new part
			case NAME:
				mathfunc(s);
				break;

			// old part
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

			// from ./4.c
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



// new part
void mathfnc(char s[]) {
	double op2;
	if (strcmp(s, "sin") == 0)
		push(sin(pop()));
	else if (strcmp(s, "cos") == 0)
		push(cos(pop()));
	else if (strcmp(s, "exp") == 0)
		push(exp(pop()));
	else if (strcmp(s, "pow") == 0) {
		op2 = pop();
		push(pow(pop(), op2));
	} else
		printf("error: %s is not supported\n", s);
}

