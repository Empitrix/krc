#include <stdio.h>

#define MAXLINE 1000

int getlinec(char line[], int lim);
int trim_leading(char line[], int l);


int main(void){
	int len, i;
	char line[MAXLINE];
	int m;
	m = 0;
	/**/ 
	while ((len = getlinec(line, MAXLINE)) > 0 ) {
		m = trim_leading(line, len);
		printf(">");
		for(i = 0; i < m; ++i)
			putchar(line[i]);
		printf("<\n");
	}
}


int getlinec(char line[], int lim){
	int i, c;

	for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	return i;
}


int trim_leading(char line[], int l){
	int i, max, in;

	in = 0;  /* state of the trim (reached to a char or not)*/
	max = 0;  /* value from left to right of white space (length) */

	for(i = l; i >= 0; --i)
		if(line[i] == '\t' || line[i] == ' ' || line[i] == '\n'){
			/* break; is not introduced in the book yet */
			if(in == 0){
				++max;
			}
		} else{
			in = 1;
		}
	return l - max;
}

