#include <stdio.h>

/* 
E: Write a program to copy its input to its output replacing
each string of one or more blanks by a single blank.
*/

int main(void){
	int c, p;
	p = 0;  // previus state of blanks
	while((c = getchar()) != EOF){
		if(c != ' '){
			putchar(c);
			p = 0;
		}
		if(c == ' '){
			if(p != 1)
				putchar(' ');
			p = 1;
		}
	}
}
