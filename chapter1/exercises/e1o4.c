#include <stdio.h>

int main(void){
	int lower, upper, step;
	float fahr, celsius;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;

	while (celsius <= upper){
		// reverse: celsius = (5.0/9.0) * (fahr - 32.0);
		fahr = (9.0/5.0) * celsius + 32;
		printf("%4.0f %6.0f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
