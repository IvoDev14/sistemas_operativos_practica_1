#include "libreria.h"
#include <stdio.h>

int head(int N){
	char line[BUFSIZ];
	
	for (; N > 0; N--){
		// Comprobamos si ha llegado al final del fichero para que no siga leyendo
		if (fgets(line, BUFSIZ, stdin) != NULL){
			return 0;
		}

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
