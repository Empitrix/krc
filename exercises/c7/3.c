#include <stdio.h>
#include <stdarg.h>


/*
Revise minprintf to handle more of the other
facilities of printf.
*/

void minprintf(char *fmt, ...);

int main(void){
	char *a = "Awesome";
	minprintf("%s", a);

	minprintf("hex: %x, int: %d", 10, 10);
	return 0;
}



void minprintf(char *fmt, ...){
	va_list ap;
	char *p, *sval;
	int ival;
	double dval;
	
	va_start(ap, fmt);


	for (p = fmt; *p; p++){

		if(*p != '%'){
			putchar(*p);
			continue;
		}

		switch (*++p) {
			case 'd':
				ival = va_arg(ap, int);
				printf("%d", ival);
				break;
		
			case 'f':
				dval = va_arg(ap, double);
				printf("%f", dval);
				break;

			case 's':
				for(sval = va_arg(ap, char *); *sval; sval++)
					putchar(*sval);
				break;

			case 'o':
				ival = va_arg(ap, int);
				printf("%x", ival);
				break;

			default:
				putchar(*p);
				break;
		}
	}

	va_end(ap);
}

