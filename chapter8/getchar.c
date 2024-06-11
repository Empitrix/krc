#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int my_getchar(void){
	char c;
	return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
	return 0;
}

