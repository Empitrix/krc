#include <stdio.h>

int setbits(unsigned x, int p, int n, int y);


int main(void){
	printf("%u", setbits((unsigned)12, 3, 2, (unsigned)57));
}


int setbits(unsigned x, int p, int n, int y){
	return(x & ~(~(~0 << n) << (p + 1 - n))) |
				(y & (~(~0 << n)) << (p + 1 - n));
}

