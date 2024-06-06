#include <stdio.h>

#define MAXLINE 1000

int getlinec(char line[], int lim);

int main(void){


	char line[MAXLINE];

	while ((getlinec(line, MAXLINE)) > 0) {
		printf("%s\n", line);
	}
	
}

/*
// ORIGINAL
int getlinec(char line[], int lim){
	int i, c;
	for(i=0; i < lim - 1 && (c =getchar()) != '\n' && c != EOF; ++i)
		line[i] = c;
	return i;
}
*/

int getlinec(char line[], int lim){
	int i, c;
	// for(i=0; i < lim - 1 && (c=getchar()) != '\n' && c != EOF; ++i)
	//
	c = i = 0;

	while((c = getchar()) != EOF){
		if(i < lim - 1)
			if(c != '\n')
				line[i] = c;
		++i;
	}
	return i;
}
