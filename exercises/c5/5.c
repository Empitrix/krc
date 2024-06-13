#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Write versions of the library functions strncpy, strncat,
and strncmp, which operate on at most the first n characters
of their argument strings. For example, strncpy(s,t,n)
copies at most n characters of t to s.
*/

#define MAXSIZE 1000

void mystrncpy(char *, char *, int);
void mystrncat(char *, char *, char *, int);
int mystrncmp(char *, char *, int);
int mystrlen(char *s);


int main(int argc, char *argv[]) {

	char dest[] = "ABCDEF";
	char source[] = "GHIJ";

	mystrncpy(dest, source, 3);  // it is 4 so see:
	printf("mystrncpy - Dest: %s\n", dest);  // GHIJEF => GHIJ(EF)

	char s1[] = "ABCD";
	char t1[] = "EFGHIJ";
	char *d;

	/* We store the result in a new string d */
	// give enough size for (d) to store
	if ((d = (char *) malloc(sizeof(char) * (strlen(s1) + +4 + 1))) == NULL) {
		printf("unable to allocate memory \n");
		return -1;
	}

	mystrncat(s1, t1, d, 4);
	printf("CAT(D): %s\n", d); /* ABCDEFGH */

	free(d);  // free the d variable from memory


	char s2[] = "ABCDEF";
	char t2[] = "ABC";
	int result;

	result = mystrncmp(s2, t2, 3);

	printf("Result: %d\nS2: %s\n", result, s2);
	return 0;
}



void mystrncat(char *str1, char *str2, char *dest, int n) {
	// copy n letter of str2 inot str1 and same them in dest

	// copy all of the str1 into dest
	while (*str1) {
		*dest++ = *str1++;
	}
	
	// copy only n of str2 into dest
	while (n-- > 0) {
		*dest++ = *str2++;
	}

	// define end-line for dest
	*dest = '\0';
}


void mystrncpy(char *dest, char *source, int n) {
	// n letter of source + n letter of dest
	
	// adding only n letter of source if its possible
	while (*source && n-- > 0)
		*dest++ = *source++;

	printf("N: %i\n", n);

	// for example if n is 3 now it turned to -1 and wiht len of dest -(-1) => +1 we have 4 as exteras
	int extra = mystrlen(dest) - n;  // after n len of dest

	// printf("N: %i\nEx: %i\nAcc: %i\n", n, extra, mystrlen(dest));

	// adding letters after n
	while (extra-- > 0) {
		*dest++;  // move to next
	}
	// define end-line for dest
	*dest = '\0';
}

/* mystrcmp: return <0 if s <t , 0 if s==t, > 0 if s > t */
int mystrncmp(char *lhs, char *rhs, int n) {
	// basicly, check that if lhs and rhs by n letter are equals or not
	for (; *lhs == *rhs; lhs++, rhs++)
		if (*lhs == '\0' || --n <= 0)
			return 0;  // for end of the line and by they are qual
	return *lhs - *rhs;  // differens between them
}



// get length of give s
int mystrlen(char *s) {
	char *p = s;
	while (*s != '\0') {
		s = s + 1;
	}
	return s - p; // p is default and s added by itself
}

