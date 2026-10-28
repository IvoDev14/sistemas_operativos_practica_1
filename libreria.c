#include "libreria.h"
#include <stdio.h>

int head(int N){
	char line[BUFSIZ];
	
	for (; N > 0; N--){
		fgets(line, BUFSIZ, stdin);
		printf("%s", line);
	}

	return 0;
	
}

int tail(int N){
	return 0;
}

int longlines(int N){
	return 0;
}
