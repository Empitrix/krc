#include <stdio.h>

char lower(char c);

int main(void){

	printf("%c\n", lower('A'));

}



char lower(char c){
	return (c >= 'A' && 'c' <= 'Z') ? c + 'a' - 'A' : c;
}

