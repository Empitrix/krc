#include <stdio.h>

#define MAXLINE 1000

int getlinec(char line[], int lim);

int main(void){
	int len;
	char line[MAXLINE];

	while ((len = getlinec(line, MAXLINE)) > 0 ) {
		if((len  - 1) >= 80)
			printf("%s\n", line);
	}
}


int getlinec(char line[], int lim){

	int i, c;

	for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;

	if(c == '\n'){
		line[i] = c;
		++i;
	}

	line[i] = '\0';
	return i;
}
