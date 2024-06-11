#include <stdio.h>

void squeez(char s[], char t[]);
int is_there(char line[], char s);

int main(void){
	char line[100] = "Awesome";
	squeez(line, "A");
	printf("%s\n", line);
}

void squeez(char s[], char t[]){
	int i, j, k;
	k = 0;
	for(i = 0; s[i] != '\0'; ++i){
		for(j = 0; (s[i] != t[j]) && t[j] != '\0'; ++j);
		if(t[j] == '\0')
			s[k++] = s[i];
	}
	s[k] = '\0';
}
