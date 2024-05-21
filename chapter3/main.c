#include <stdio.h>
#include <ctype.h>
#include <string.h>

int atoi(char s[]);
void shellsort(int v[], int n);

void itoa(int n, char s[]);

int trim(char s[]);

int main(void){

	/*
	int v[5] = {5, 4, 3, 2, 1};
	// printf("%i", isdigit('r'));

	shellsort(v, 1);

	for(int i = 0; i < 5; i++)
		printf("%i", v[i]);
	putchar('\n');
	*/

	int i = 0;
	do {
		printf("%i) Something\n", i);
		++i;
	} while(i < 10);

}

void shellsort(int v[], int n){
	int gap, i, j, temp;
	for(gap = n/2; gap > 0; gap /= 2)
		for(i = gap; i < n; i++)
			for(j=i-gap; j >= 0 && v[j]>v[j+gap]; j-=gap){
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
			}
}

int atoi(char s[]){
	int i, n, sign;
	for(i = 0; isspace(s[i]); i++);  /* skip white space */
	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-')   /* skip sign*/
		i++;
	for(n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');
	return sign * n;
}


void itoa(int n, char s[]){
	int i, sign;
	if((sign = n) < 0)  /* record sign */
		n = -n;

	i = 0;
	do{  /* generate digits in reverse order */
		s[i++] = n % 10 + '0';  /* get next digit */
	} while((n /= 10) > 0);   /* delete it */
	if(sign < 0)
		s[i++] = '-';

	s[i] = '\0';
	// reverse(s);
}




int trim(char s[]){
	int n;
	for(n = strlen(s) - 1; n >= 0; n--)
		if(s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
			break;
	return n;
}
