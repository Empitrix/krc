#include <stdio.h>

int main(void){
	int c;
	while((c = getchar()) != EOF){
		if (c == ' ' || c == '\n' || c == '\t')
			printf("\n");
		else
		 putchar(c);
	}
	return 0;
}

