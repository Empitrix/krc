#include <stdio.h>

struct point {
	int x;
	int y;
};

int main(int argc, char *argv[]){
	// struct point pt;
	struct point pt = {320, 200};
	// pt.y = 10;
	// pt.x = 10;
	printf("X: %i, Y: %i\n", pt.x, pt.y);
}

