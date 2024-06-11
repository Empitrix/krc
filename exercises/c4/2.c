#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000

/*
Extend atof to handle scientific notation of the form  123.45e-6
where a floating-point number may be followed by e or E and an
optionally signed exponent.
*/

double atof(char s[]);
int pwr(int b, int e);

int main(void){

	// char line[MAXLINE] = "3.14";
	char line[MAXLINE] = "123.45e-6";
	// atof(line);
	printf("%s -> %f\n", line, atof(line));

	return 0;
}



/* atof: convert string s to double */
double atof(char s[]) {
	double val, power;
	int i, sign, psign, after;
	psign = '+';

	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;

	sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '+' || s[i] == '-')
		i++;

	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == '.')
		i++;

	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}


	// new parts

	if(s[i] == 'e' || s[i] == 'E')
		i++;

	// get sign (+ / -)
	psign = s[++i] == '-' ? '+' : '-';


	for (after = 0; isdigit(s[i]); i++)
		after = 10.0 * after + (s[i] - '0');

	if(psign == '-')
		return sign * (val / power) / pwr(10, after);
	else
		return sign * (val / power) * pwr(10, after);

	// previus part
	// return sign * val / power;
}


/* Q: why i was not able to use pow from <math.h> ? */
/* pwr: power function b^e */
int pwr(int b, int e){
	int p = 1;
	while(e-- > 0)
		p *= b;
	return p;
}

