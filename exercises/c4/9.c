#include <stdio.h>

/*
Our getch and ungetch do not handle a pushed-back EOF correctly.
Decide what their properties ought to be if an EOF is pushed back,
then implement your design.
*/

#define MAXLINE 1000

/* need to access the size globaly */
int line[MAXLINE];
int idx = 0;

int getch(void);
void ungetch(int);


int main(void){
	int c = '"';

	ungetch(c);  // add into buffer
	
	putchar(c);

	while((c = getch()) != EOF)
		putchar(c);

	putchar('\n');  // new-line in terminal
	return 0;
}


/* get a char */
int getch(void){
	if(idx > 0)
		return line[--idx];
	return getchar();
}


/* push a char back onto input */
void ungetch(int c){
	if(idx >= MAXLINE)
		printf("FAILED\n");
	else
	 line[idx++] = c;
}

