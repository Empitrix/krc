#include <stdio.h>

#define MAXLINE 1000

int getlinec(char line[], int lim);
void show_in_reverse(char line[], int l);


int main(void){
	int len, i;
	char line[MAXLINE];

	while ((len = getlinec(line, MAXLINE)) > 0 ) {
		show_in_reverse(line, len);
	}
}


int getlinec(char line[], int lim){
	int i, c;

	for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	return i;
}


void show_in_reverse(char line[], int l){
	int i;
	for(i = l; i >= 0; --i){
		putchar(line[i]);
	}
	putchar('\n');  /* to break the line */
}

