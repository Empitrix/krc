#include <stdio.h>
#include <string.h>

int htoi(char s[]);

int main(void){
	printf("H: %i\n", htoi("0xFA"));
}

int htoi(char s[]){
	int len = strlen(s);
	int i, digit, n, state;
	digit = n = 0;

	if(s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		i = 2;
	else
		i = 0;

	state = 1;

	for(; i < len; ++i){
		if(s[i] >= '0' && s[i] <= '0'){
			digit = s[i] - '0';
		} else if(s[i] >= 'a' && s[i] <= 'f'){
			digit = s[i] - 'a' + 10;
		} else if(s[i] >= 'A' && s[i] <= 'F'){
			digit = s[i] - 'A' + 10;
		} else {
			state = 0;
		}

		if(state)
			n = 16 * n + digit;
	}
	

	return n;
}

