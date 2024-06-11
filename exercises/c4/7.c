#include <stdio.h>

#define MAXLINE 1000

/*
Write a routine ungets(s) that will push back an entire string onto
the input. Should ungets know about buf and bufp, or should it just
use ungetch?
*/

void ungetch(char s []);
int getch(char *line);

int main(void){
	char line[MAXLINE];

	while(getch(line) > 0)
		ungetch(line);

	// ungetch("Awesome");
	// printf("L: %s\n", line);

	return 0;
}


int getch(char *line){
	int c, i;
	while((c = getchar()) != EOF && c != '\n')
		line[i++] = c;
	line[i] = '\0';
	return i;
}

void ungetch(char s[]){
	int i;
	for(i = 0; s[i] != '\0'; ++i){
		putchar(s[i]);
	}
	i = 0;
	s[0] = '\0'; // make line empty again
	putchar('\n');
}

