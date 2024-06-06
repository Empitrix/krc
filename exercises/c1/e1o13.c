#include <stdio.h>

int main(void){
	int c, i, t, s;
	int length[10];

	i = t = 0;

	while((c = getchar()) != EOF){
		if(c != '\t' && c != ' ' && c != '\n'){
			t++;
			// putchar(c);
		} else {
			if(i <= 10){
				length[i] = t;
				++i;
			}
			t = 0;
		}
	}

	for(i = 0; i < 10; ++i){
		printf("%i >|", i + 1);
		for(s = 0; s < length[i]; ++s)
			printf("*");
		printf("\n");
	}
}

