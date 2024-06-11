#include <stdio.h>


void strcat_p(char *s, char *t){
	while(*s != '\0')
		s++;
	s--;  // remove the null char
	while((*s++ = *t++) != '\0'){
		// s++;
		// t++;
	}
}



int main(void){
	char *s = "Hello ";
	char *t = "World";
	strcat_p(s, t);
	printf("%s\n", s);
	return 0;
}
