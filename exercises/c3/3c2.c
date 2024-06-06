#include <stdio.h>

/* copy 't' to 's' while make escape sequences visible */
void escape(char s[], char t[]);

int main(void){
	char s[] = "";
	char t[] = "Awesome\nGood";
	// char t[] = "Awesome\n";
	escape(s, t);
	printf("%s\n", s);
}


void escape(char s[], char t[]){
	int i, j = 0;

	while(t[i] != '\0'){

		switch (t[i]) {
			case '\n':
				s[j] = '\\';
				++j;
				s[j] = 'n';
				break;

			case '\t':
				s[j] = '\\';
				++j;
				s[j] = 't';
				++j;
				break;

			default:
				if(t[i] != '\n' && t[i] != '\t'){
					s[j] = t[i];
					break;
				}
		}
		++j;
		++i;
	}

	s[j] = '\0';

}

