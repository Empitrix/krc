/*
Write a program to remove all comments from a C program.
Don't forget to handle quoted strings and character constants properly.
C comments don't nest.

gloal:
detect multi-line qoutes

*/


#include <stdio.h>

#define MAXSIZE 1000
#define DEBUGING 0

int gline(char *line, int start);
void proccess_line(char *line);

enum QState{ IN, OUT };


int main(void){
	char *line;
	int start = 0;

	// containing comments in out of the lines
	// char sample[] = """#include<stdio.h>\nint main(void){\n\tprintf(\"Awesome\"); /* one */\n\treturn 0;\n}""";

	// containing comments in the qouted strings
	char sample[] = """#include<stdio.h>\nint main(void){\n\tprintf(\"Awe/*A*/some\"); /* one */\n\treturn 0;\n}""";

	gline(sample, start);

	putchar('\n');
	return 0;
}


/* gline: get each line (split by \n) */
int gline(char *line, int end){
	int i, e, n, c;
	char nline[MAXSIZE];

	e = end;  /* basicly start */

	for(i = 0; line[i] != '\0'; ++i){
		if(line[i] == '\n'){
			if (DEBUGING)
				printf("[%i, %i]\n", e, end);

			for(n = e, c = 0; n < end; ++n){
				nline[++c] = line[n];
			}

			++c;
			nline[c] = '\0';

			proccess_line(nline);
			e = end;  // update the start
			++end;    // to skip the '\n'
		}
		++end;
	}
	return i;
}


/*proccess line: check for the lines and print them out */
void proccess_line(char *line){
	enum QState qoute;
	enum QState comment;
	qoute = comment = OUT;
	int i, start, end;
	start = end = 0;
	int skip = 0;

	for(i = 0; line[i] != '\0'; ++i){

		// check for qoute scope
		if(line[i] == '"'){
			if(qoute == OUT)
				qoute = IN;
			else
				qoute = OUT;
		}

		// this is not a good way (if the range is out ...)
		if(line[i] == '/' && line[i + 1] == '*' && qoute == OUT)
			comment = IN;
		if(line[i] == '*' && line[i + 1] == '/' && qoute == OUT){
			comment = OUT;
			skip = 1;
			continue;
		}
		if(skip){
			skip = 0;
			continue;
		}

		// print if the char is not part of the comment
		if(comment == OUT)
			putchar(line[i]);

	}
}


