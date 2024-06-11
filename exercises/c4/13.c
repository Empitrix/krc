#include <stdio.h>
#include <string.h>

/*
Write a recursive version of the function reverse(s),
which reverses the string s in place.
*/

#define MAXLINE 1000


void reverse(char[]);

int main(void){
	char line[MAXLINE] = "Awesome";
	reverse(line);
	printf("%s\n", line);
	return 0;
}

void reverse(char s[]){
	static int idx;
	static int length;

	int i, c;

	if(idx == 0)
		length = strlen(s);

	i = length - (idx + 1);
	if(idx < i){
		// swap
		c = s[idx];
		s[idx] = s[i];
		s[i] = c;
		idx++;          // Next letter
		reverse(s);
	} else            // its done (stop form continue for others)
		idx = 0;
}

