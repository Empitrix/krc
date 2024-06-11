#include <stdio.h>


/*
	The value of `getchar != EOF` is always positive until program ends! (<C-d> or <C-c>)
*/

int main(void){
	int c;
	int a;
	a = (c = getchar()) != EOF;
	while(a){
		putchar(c);
		a = (c = getchar()) != EOF;
	}

	return 0;
}
