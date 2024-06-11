#include <stdio.h>

/*
Define a macro swap(t,x,y) that interchanges two arguments
of type t. (Block structure will help.)
*/

#define swap(t, x, y){\
	t _z;\
	_z = x;\
	x = y;\
	y = _z;\
}

int main(void){
	char x, y;
	x = '1';
	y = '2';

	printf("X: %c, Y: %c\n", x, y);
	swap(char, x, y); // swap by given type
	printf("X: %c, Y: %c\n", x, y);

	return 0;
}
