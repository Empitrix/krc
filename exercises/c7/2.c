#include <stdio.h>
#include <ctype.h>

/*
Write a program that will print arbitrary input in a
sensible way. As a minimum, it should print non-graphic
characters in octal or hexadecimal according to local
custom, and break long text lines.
*/

#define MAXLINE 1000

int increment(int pos, int n);

int main(void){
	int c, pos;
	pos = 0;

	while((c = getchar()) != EOF)
		// https://www.programiz.com/c-programming/library-function/ctype.h/iscntrl#:~:text=The%20iscntrl()%20function%20checks,function%20is%20defined%20in%20ctype.
		if(iscntrl(c) || c == ' '){
			// ???
			pos = increment(pos, 1);
			printf("");
		
			if(c == '\n')
				pos = 0;
			putchar('\n');
		} else {
			pos = increment(pos, 1);
			putchar(c);
		}


	return 0;
}


int increment(int pos, int n){
	if(pos + n < MAXLINE)
		return pos + n;
	else{
		putchar('\n');
		return n;
	}
}

