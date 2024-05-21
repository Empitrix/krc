#include <stdio.h>

/*
Write a function expand(s1, s2) that expand shorthand notations like a-z
in the string s1 into the exivalent cmplete list abc...xyz in s2.
Allow for letters of eighter case and digits, and be sperated to handle
cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or 
trailing - is take literally. [ ]
*/

void expand(char s1[], char s2[]);

int main(void){

	char s1[] = "";
	char s2[] = "";

	expand(s1, s2);

	printf("%s\n", s2);
	return 0;
}

void expand(char s1[], char s2[]){
}

