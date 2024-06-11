#include <stdio.h>



/*
int power(int base, int n){
	int i, p;
	p = 1;

	for(i = 1; i <= n; ++i)
		p = p * base;
	return p;
}
*/

int power(int base, int n){
	int p;

	for(p = 1; n > 0; --n)
		p = p * base;
	return p;
}


int main(void){
	int i;
	for(i = 0; i < 10; ++i)
		printf("%d %d %d\n", i, power(2, i), power(-3, i));
	return 0;
}

