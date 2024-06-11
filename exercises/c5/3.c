#include <stdio.h>

#define MAXLINE 1000
/*
Write a pointer version of the function strcat that we
showed in Chapter 2: strcat(s,t) copies the string t to
the end of s.
*/

void strcat_(char *,char *);

int main(void){
	char s[MAXLINE] = "Hello ";
	char t[MAXLINE] = "World";
	strcat_(s, t);
	printf("%s\n", s);
	return 0;
}

void strcat_(char *s,char *t){
	int i, j;

	for(i = 0; s[i] != '\0'; ++i);  // get length of s

	for(j = 0; t[j] != '\0'; ++j){
		s[i + j] = t[j];
	}
	s[i + j] = '\0';
}

