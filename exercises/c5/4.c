#include <stdio.h>

/*
Write the function strend(s,t), which returns 1 if the
string t occurs at the end of the string s, and zero otherwise.
*/


int strend(char *, char *);

int main(void){
	printf("%i\n", strend("Awesome", "Awesome"));
	printf("%i\n", strend("Awesome", "some"));
	printf("%i\n", strend("Awesome", "mamad"));
	return 0;
}

int strend(char *s, char *t){
	int slen, tlen, i, j;

	for(slen = 0; s[slen] != '\0'; ++slen); // get s length
	for(tlen = 0; t[tlen] != '\0'; ++tlen); // get t length
	
	for(i = slen - tlen, j = 0; t[j] != '\0'; ++i, ++j){
		if(s[i] != t[j])
			return 0;
	}

	return 1;
}
