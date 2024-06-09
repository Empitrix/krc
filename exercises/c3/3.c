#include <stdio.h>

#define MAXLINE 1000

/*
Write a function expand(s1, s2) that expand shorthand notations like a-z
in the string s1 into the exivalent cmplete list abc...xyz in s2.
*/

void expand(char s1[], char s2[]);

int main(void){

	char s1[MAXLINE] = "a-d";  /* a-d */
	char s2[MAXLINE] = "";     /* abcd */

	expand(s1, s2);

	printf("%s\n", s2);
	return 0;
}


void expand(char s[], char t[]) {
	int i, j;
	for(i = 0, j = 0; s[i] != '\0'; ++i){
		if(s[i] == '-'){
			char p = s[i - 1];
			char n = s[i + 1];
			char m;
			for(m = p + 1; m < n; m++){
				t[j++] = m;
			}
		}
		else
			t[j++] = s[i];
	}
	t[j] = '\0';
}

