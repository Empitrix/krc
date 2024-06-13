#include <stdio.h>

/*
Write a program to check a C program for rudimentary syntax
errors like unmatched parentheses, brackets and braces.
Don't forget about quotes, both single and double,
escape sequences, and comments.

(This program is hard if you do it in full generality.)
*/



int brace, brack, paren;

void incomment();
void inquote(int c);
void search(int c);


int main(void) {
	int c;

	extern int brace, brack, paren;

	while ((c = getchar()) != EOF)
		if (c == '/')
			if ((c = getchar()) == '*')
				incomment();
			else
				search(c);
		else if (c == '\'' || c == '"')
			inquote(c);
		else
			search(c);


	// printf("B: %i", brace);

	if (brace < 0) {
		printf("Unmatched Braces\n");
		brace = 0;
	} else if (brack < 0) {
		printf("Unmatched brackets\n");
		brack = 0;
	} else if (paren < 0) {
		printf("Unmatched parenthesis\n");
		paren = 0;
	}

	if (brace > 0)
		printf("Unmatched braces\n");
	else if (brack > 0)
		printf("Unmatched brackets\n");
	else if (paren > 0)
		printf("Unmatched parenthesis\n");

	return 0;
}

void incomment() {
	int c, d;
	// get next two letters to check if this is a  qoute or mulit-line qoute
	c = getchar();
	d = getchar();
	while (c != '*' || d != '/') {
		// go one step forward
		c = d;
		d = getchar();
	}
}

void inquote(int c) {
	int d;
	putchar(c);
	// putchar('\\');
	while ((d = getchar()) != c)
		if (d == '\\')  // for end of the line to another (like macros)
			getchar();
}

void search(int c) {
	// brace and etc... through out all over the program so
	// they need to be availabe from outside of the functions
	extern int brace, brack, paren;

	if (c == '{')
		--brace;
	else if (c == '}')
		++brace;
	else if (c == '[')
		--brack;
	else if (c == ']')
		++brack;
	else if (c == '(')
		--paren;
	else if (c == ')')
		++paren;
}

