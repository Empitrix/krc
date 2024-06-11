#include <ctype.h>
#include <stdio.h>
#include <string.h>

/*
Write a program that converts upper case to lower or lower
case to upper, depending on the name it is invoked with,
as found in `argv[0]`.
*/

void formatcase(int);

int main(int argc, char *argv[]){
	if(argc != 2){
		formatcase(1);
		return 0;
	}

	if(strcmp(argv[1], "lower") == 0)
		formatcase(1);
	else
		formatcase(0);
	return 0;
}


void formatcase(int status){
	int c;
	while((c = getchar()) != EOF)
		if(status == 1)
			putchar(tolower(c));
		else
			putchar(toupper(c));
}

