#include <stdio.h>

int main(void){
	int c, count;
	count = 0;

	while((c = getchar()) != EOF){
		if(c == '\n')  // new line
			++count;
		if(c == '\t')  // tab
			++count;
		if(c == ' ')  // blank
			++count;
	}
	printf("there is [%i] new-line, tabs or blanks in total", count);
}
