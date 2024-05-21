#include <stdio.h>

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n - 1]*/
int binsearch(int x, int v[], int n);


int main(void){
	int v[] = {1, 0, 5, 4, 5, 5, 7, 5, 12};
	printf("%i\n", binsearch(5, v, 12));
	return 0;
}


/*
// Defualt Version
int binsearch(int x, int v[], int n){
	int low, high, mid;
	low = 0;
	high = n - 1;
	while(low <= high){
		mid = (low + high) / 2;
		if(x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}
*/



int binsearch(int x, int v[], int n){
	int low, high, mid;
	low = 0;
	high = n - 1;

	if(x == (mid = (low + high) / 2)){
		return mid;
	}

	while(low <= high){
		mid = (low + high) / 2;
		if(x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}
