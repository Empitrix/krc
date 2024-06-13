#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*
Write the program tail, which prints the last n lines of its
input. By default, n is set to 10, let us say, but it can be
changed by an optional argument so that   tail -n  prints the
last n lines. The program should behave rationally no matter
how unreasonable the input or the value of n.
Write the program so it makes the best use of available
storage; lines should be stored as in the sorting program of
Section 5.6, not in a two-dimensional array of fixed size.
*/

#define DEFLINES 10
#define LINES 100
#define MAXLEN 100


void error(char *);
int mgetline(char *, int);


int main(int argc, char *argv[]){
	char *p, *buf, *bufend;

	char line[MAXLEN];
	char *lineptr[LINES];

	int first, i, last, len, n, nlines;

	if(argc == 1)
		n = DEFLINES;
	else if(argc == 2 && (*++argv)[0] == '-') // get -n flag
		n = atoi(argv[0] + 1);
	else
		error("Usage: tail [-n]");

	// not a correct amount of n from flag
	if(n < 1 || n > LINES)
		n = LINES;

	// clear lineptr
	for(i = 0; i < LINES; i++)
		lineptr[i] = NULL;

	// get enough size
	if((p = buf = malloc(LINES * MAXLEN)) == NULL)
		error("tail: cannot allocate buf");

	bufend = buf + LINES + MAXLEN;

	last = 0;
	nlines = 0;

	while((len = mgetline(line, MAXLEN)) > 0){
		if(p + len + 1 >= bufend)
			p = buf;
		lineptr[last] = p;

		strcpy(lineptr[last], line);
		if(++last >= LINES)
			last = 0;

		p += len + 1;
		nlines++;

	}


	// correct amount of n (not overflow)
	if(n > nlines)
		n = nlines;


	first = last - n;

	if(first < 0)
		first += LINES;

	for(i = first; n-- > 0; i= (i + 1) % LINES)
		printf("%s\n", lineptr[i]);
	return 0;
}


void error(char *msg){
	printf("%s\n", msg);
	exit(1);
}


int mgetline(char s[], int lim){
	int c, i;
	for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if(c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

