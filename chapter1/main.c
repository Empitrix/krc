#include <stdio.h>

int main(void){
	int fahr;

	/*
	while (fahr <= upper){
		celsius = (5.0/9.0) * (fahr - 32.0);
		printf("%4.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	*/
	for(fahr = 0; fahr <= 300; fahr = fahr + 20)
		printf("%3i %6.1f\n", fahr, (5.0/9.0) * (fahr - 32));
}


/*
Output:
   0  -17.8
  20   -6.7
  40    4.4
  60   15.6
  80   26.7
 100   37.8
 120   48.9
 140   60.0
 160   71.1
 180   82.2
 200   93.3
 220  104.4
 240  115.6
 260  126.7
 280  137.8
 300  148.9
*/
