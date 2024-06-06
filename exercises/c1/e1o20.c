#include <stdio.h>

#define TABSIZE 4

int main(void) {
	int nb, pos, c;

	nb = 0;
	pos = 1;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			nb = TABSIZE - ((pos - 1) % TABSIZE);

			while (nb > 0) {
				putchar('#');
				++pos;
				--nb;
			}
		} else if (c == '\n') {
			putchar(c);
			pos = 1;
		} else {
			putchar(c);
			++pos;
		}
	}
	return 0;
}
