int is_there(char line[], char s){
	for(int i = 0; line[i] != '\0'; ++i){
		if(line[i] == s){
			return i;
		}
	}
	return -1;
}
