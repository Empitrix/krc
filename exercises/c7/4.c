#include <stdarg.h>
#include <math.h>
#include <stdio.h>

/*
Write a private version of scanf analogous to minprintf from
the previous section.
*/

void minscanf(char *fmt, ...);

int main(void){

}

void minscanf(char *fmt, ...){
	va_list ap;
	char *p, *sval;
	int *ival;
	float *dval;

	va_start(ap, fmt);

	for(p = fmt; *p; p++){
		if(*p != '%'){
			continue;
		}

		switch (*++p) {
			case 'd':
				ival = va_arg(ap, int *);
				scanf("%d", ival);
				// sscanf(d, "%d", ival);
				break;

			case 'f':
				dval = va_arg(ap, float *);
				scanf("%f", dval);
				break;

			case 's':
				sval = va_arg(ap, char *);
				scanf("%s", sval);
				break;
			
			case 'o':
				ival = va_arg(ap, int *);
				scanf("%o", ival);

			case 'x':
				ival = va_arg(ap, int *);
				scanf("%o", ival);

			default:
				putchar(*p);
				break;

		
		}
	}
	va_end(ap);
}
