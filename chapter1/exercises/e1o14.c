#include <stdio.h>

int main(void){
	int c, i, s;
	int length[3];
	// 0: digits
	// 1: white space
	// 2: 'a' character
	length[0] = length[1] = length[2] = 0;

	while((c = getchar()) != EOF){
		if(c >= '0' && c <= '9')
			++length[0];
		else if(c == ' ' || c == '\t' || c == '\n')
			++length[1];
		else if(c == 'a')
			++length[2];
	}
	for(i = 0; i < 3; i++){

		if(i == 0)
			printf("D |");
		else if(i == 1)
			printf("W |");
		else
			printf("a |");

		for(s = 0; s < length[i]; s++){
			printf("*");
		}
		printf("\n");
	}
}
