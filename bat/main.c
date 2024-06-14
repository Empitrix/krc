#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// macros
#define MAXLINENUM 100
#define MAXLINE 1000

// Colors
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"


struct LINE {
	char text[MAXLINE];
	int idx;
};

struct HIGHLIGHT {
	char word[MAXLINE];
	char color[MAXLINE];
};

struct SPLIT {
	int size;
	char** words;
};


struct SPLIT getwarr(char *);

static struct HIGHLIGHT highlights[] = {
	{"self", KYEL},
	{"import", KRED},
	{"def", KMAG},
	{"if", KYEL},
	{"class", KYEL},
	{"pass", KMAG},
	{"print", KBLU},
	{"=", KCYN},
	{"!", KCYN},
	{":", KCYN},
	{"(", KYEL},
	{")", KYEL},
	{"\"", KGRN},
	{"\'", KGRN},
	{"true", KRED},
	{"false", KRED},

	{"hello", KRED},
};


// prototypes
void out_err(char *, int);
void print_out(struct LINE[], int, char *, int);
void prtln(char *);
char* getlower(const char* s);


int main(int argc, char *argv[]){

	int c, i, l, ln, max;
	FILE *file;
	struct LINE lines[MAXLINENUM];
	char line[MAXLINE];

	max = 1;

	if(argc == 1)
		out_err("Not enough input", 1);

	while (argc-- > 1) {
		file = fopen(argv[argc], "r");

		while ((c = getc(file)) != EOF) {
			// break the line if it is at the end
			if(c != '\r'){
				if(c != '\n')
					line[i++] = c;
			}
			else{
				line[i] = '\0';
				if(i > max)
					max = i;
				i = 0;

				// add into lines
				strcpy(lines[l++].text, line);
				lines[l].idx = (++ln);
			}
		}

		fclose(file);  // close file

		// print lines
		print_out(lines, ln, argv[argc],
			(max + (int)(ln / 10) + 5));
		ln = l = 0;

		// claer
		memset(lines, 0, sizeof(lines));
		memset(line, 0, sizeof(line));
	}

	return 0;
}

/* out_err: print a message and exit the program with status a code */
void out_err(char *msg, int code){
	printf("%s\n", msg);
	exit(code);
}


/* print the frame and call for highlighting each line */
void print_out(struct LINE lines[], int n, char *title, int max){
	int j, count;
	printf("%s\n", title);

	for(count = 0; count < max; count++)
		if(count == 4)
			printf("┬");
		else
			printf("─");

	putchar('\n');
	for(j = 0; j < n + 1; ++j){

		/*
		if(strcmp(lines[j].text, "") == 0)
			continue;
		*/

		printf("%s%3i%s │ ", KYEL, lines[j].idx + 1, KNRM);
		prtln(lines[j].text);

	}
	printf("\n\n");
}


/* break the given line (char *) into array of words and symbols */
struct SPLIT getwarr(char *ln){
	char **arr = (char **)malloc(MAXLINE * sizeof(char *));
	int i, w, n;

	n = 0;
	arr[n] = (char *)malloc(MAXLINE * sizeof(char));
	for(i = 0, w = 0; ln[i] != '\0'; ++i){
		if(!((ln[i] >= 'a' && ln[i] <= 'z') || (ln[i] >= 'A' && ln[i] <= 'Z'))){
			arr[n][w] = '\0';

			n++;
			w = 0;
			arr[n] = (char *)malloc(MAXLINE * sizeof(char));
			arr[n][w++] = ln[i];

			n++;
			w = 0;
			arr[n] = (char *)malloc(MAXLINE * sizeof(char));
		} else {
			arr[n][w++] = ln[i];
		}
	}

	struct SPLIT split;
	split.size = (n + 1);
	split.words = arr;
	return split;
}


/* convert given string into lowercase and return the value */
char* getlower(const char* s) {

	// Allocate memory for the new string + null char
	char* lower = (char*)malloc(strlen(s) + 1);
	int i;

	for (i = 0; s[i] != '\0'; ++i) {
		lower[i] = tolower(s[i]);
	}

	lower[i] = '\0';  // specifie the end of the line

	return lower;
}


/* print each line and highlight the valid words */
void prtln(char *ln){
	int h, s;
	// get length of "highlights"
	int maxh = sizeof(highlights) / sizeof(highlights[0]);

	// split the line into words
	struct SPLIT split;
	split = getwarr(ln);

	for(s = 0; s < split.size; ++s){
		// get the color if it's possible
		char *color = KNRM;
		for(h = 0; h < maxh; ++h){
			if(strcmp(highlights[h].word, getlower(split.words[s])) == 0){
				color = highlights[h].color;
				break;
			}
		}
		printf("%s%s%s", color, split.words[s], KNRM);
	}

	putchar('\n');  // end of the file
}

