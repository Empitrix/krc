#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Write a program to print a set of files,
starting each new one on a new page, with a title
and a running page count for each file.
*/

#define LINEPAGE 100

void printpages(FILE *, FILE *);

int main(int argc, char *argv[]){
	FILE *fp;
	char *prog = argv[0];
	int linecount = 0;

	if(argc == 1){
		fprintf(stderr, "No files given\n");
		printpages(stdin, stdout);
	} else {
		while(--argc > 0)
			if((fp = fopen(*++argv, "r")) == NULL){
				fprintf(stderr, "%s: cant open %s\n", prog, *argv);
				exit(1);
			} else {
				fprintf(stderr, "\nFile: %s\n", *argv);
				printpages(fp, stdout);
				fclose(fp);
			}
	}

	if(ferror(stdout)){
		fprintf(stderr, "%s: error writing stdout\n", prog);
		exit(2);
	}

	exit(0);

	return 0;
}


void printpages(FILE *ifp, FILE *ofp){
	int c, line, pg;
	line = 0;
	pg = 1;

	while((c = getchar()) != EOF){
		putc(c, ofp);
		if(c == '\n')
			line = line + 1;
		if(line == LINEPAGE){
			fprintf(stdout, "\nPage %d End.", pg);
			pg = pg + 1;
			line = 0;
		}
	}

}

