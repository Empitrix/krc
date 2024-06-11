#include <stdio.h>

void strcpy_array(char *s, char *t){
	int i = 0;
	while((s[i] = t[i]) != '\0')
		i++;
}


void strcpy_pointer(char *s, char *t){
	while((*s = *t) != '\0'){
		s++;
		t++;
	}
}


int main(void){
	printf("Awesome\n");
	return 0;
}

