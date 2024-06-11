#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

/*
Write the function strindex(s,t) which returns the position of
the rightmost occurrence of t in s, or -1 if there is none
*/


int strindex(char* s, char* t);

int main(void){

	// char s[MAXLINE] = "This is super cool realy like this";
	// char t[MAXLINE] = "cool realy";

	char s[MAXLINE] = "This is super coolly realy awesome";
	char t[MAXLINE] = "realy";
	printf("%i\n", strindex(s, t));

	return 0;
}


int strindex(char* s, char* t){
	int i, j, k;
	
	for(i = 0; s[i] != '\0'; ++i){
		for(j = i, k = 0; s[j] == t[k]; ++j, ++k);  // kind of like bouble sort :)
		if(t[k] == '\0')
			// return i;   // index
			return i + 1;  // start index
	}

	return -1;
}


/*
int strindex(char* s, char* t){
	int i, j;
	for(i = 0; s[i] != '\0'; ++i){
		printf("%i\n", (s[i + j] == t[j])); // first state that become 1 is begining (should be continued)
	}
	return i - j;
}
*/

