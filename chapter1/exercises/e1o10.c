#include <stdio.h>

/*
Write a program to copy its input to its output, replacing each tab
by \t each, backspace by \b, and each backslash by \\, This makes tabs
and backspaces visible in any unambiguous way.
*/

int main(void){
	int c, p;
	// p is the 'pint' access
	while((c = getchar()) != EOF){
		p = 1;
		if(c == '\t'){
			p = 0;
			printf("\\t");
		}

		if(c == '\b'){
			p = 0;
			printf("\\b");
		}

		if(c == '\\'){
			p = 0;
			printf("\\\\");
		}

		if(p)
			putchar(c);
	}
}
