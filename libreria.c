#include "libreria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char **buffer;
	int capacity;
	int index;
	int num_lines;
} CircularBuffer;

int initialize_circular_buffer(CircularBuffer *b, int capacity);
int add_line(CircularBuffer *b, const char * line);
int read_lines(CircularBuffer b);
int free_circular_buffer(CircularBuffer *b);


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
	CircularBuffer b;
	char line[BUFSIZ];
	initialize_circular_buffer(&b, N);

	// Añadimos líneas hasta que se encuentre eof
	while(fgets(line, BUFSIZ, stdin) != NULL){
		add_line(&b, line);
	}

	//Imprimimos las líneas
	read_lines(b);

	free_circular_buffer(&b);

	return 0;
}

int longlines(int N){
	return 0;
}

int initialize_circular_buffer(CircularBuffer *b, int capacity){
	b->capacity = capacity; // Definimos capacidad máxima
	b->index = 0; // Inicializamos el índice a 0
	b->buffer = malloc(capacity * sizeof(char *)); // Reservamos memoria para los punteros que apuntan a las líneas
	b->num_lines = 0;
	int i;
	
	// Reservamos memoria de cada puntero que apunta a una línea
	for (i = 0; i<capacity; i++){
		b->buffer[i] = malloc(BUFSIZ * sizeof(char));
	}

	return 0;
}

int add_line(CircularBuffer *b, const char * line){

	// Si no se ha llegado al límite de líneas almacenadas se suma una línea
	if (b->num_lines < b->capacity) b->num_lines++;

	// Copiamos la línea a la posición de memoria que apunta el puntero por el que vamos
	memcpy(b->buffer[b->index], line, BUFSIZ);

	// Aumentamos en 1 el índice si no está en el límite, si está en el límtie se pone a 0
	if(b->index == b->capacity - 1){
		b->index = 0;
	} else {
		b->index ++;
	}
	

	return 0;

}

int read_lines(CircularBuffer b){
	int local_index;

	//Damos valor inicial al local_index, es decir por donde vamos a empezar a imprimir
	if (b.num_lines < b.capacity){
		local_index = 0; //Si el número de líneas almacenadas es menor a la capacidad entonces la línea más antigua será la del índice 0
	} else {
		local_index = b.index; // Si no la línea más antigua será la siguiente a la que está el índice 
	}
	
	for (int i = 0; i < b.num_lines; i++){
		if(local_index == b.capacity - 1) local_index = 0;
		printf("%s", b.buffer[local_index]);
		local_index += 1;
	}

	return 0;
}

int free_circular_buffer(CircularBuffer *b){

	// Liberamos la memoria de cada uno de los punteros (cada línea)
	for (int i=0; i<b->capacity; i++){
		free(b->buffer[i]);
	}

	// Liberamos la memoria del puntero buffer
	free(b->buffer);

	return 0;
}
