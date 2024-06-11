#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <fcntl.h>

/*
Rewrite the program cat from Chapter 7 using read, write,
open, and close instead of their standard library equivalents.
Perform experiments to determine the relative speeds of the
two versions.
*/

#define STDIN 0
#define STDOUT 1
#define STDERR 2
// #define BUFSIZE


void error(char *fmt, ...);
void filecopy(int idf, int ofd);

int main(int argc, char *argv[]){
	int fd;

	if(argc == 1){
		filecopy(STDIN, STDOUT);
	} else {
		while(--argc > 0)
			if((fd = open(*++argv, O_RDONLY)) == -1){
				error("can't open %s", *argv);
			} else {
				filecopy(fd, STDOUT);
				close(fd);
			}
	}
	return 0;
}

void error(char *fmt, ...){
	va_list args;
	va_start(args, fmt);
	fprintf((FILE *) STDERR, "error :");
	vfprintf((FILE *) STDERR, fmt, args);
	fprintf((FILE *) STDERR, "\n");
	va_end(args);
	exit(1);
};


void filecopy(int ifd, int ofd){
	int n;
	char buf[BUFSIZ];

	while((n = read(ifd, buf, BUFSIZ)) > 0)
		if(fwrite(ofd, buf, n) != n){
			error("write error");
		}
}


