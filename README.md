# Práctica 1 de la asignatura Sistemas Operativos

Este repositorio contiene la práctica 1 de Sistemas Operativos de tercero de Ingeniería de Software en la Universidad Rey Juan Carlos


## Instrucciones de compilación

### Manualmente

Para compilar manualmente realizar los siguientes pasos: *Nota: estos pasos muestran todos los pasos para tener la libreria creada y el programa para testearla* 

1. gcc -Wall -Wextra -c libreria.c -o libreria.o -> generar fichero objeto de libreria.c
2. ar -rv liblibreria.a libreria.o -> crear la libreria .a
3. gcc -Wall -Wextra -o test test.c -I. -L. -llibreria -> compilar test.c y enlazarlo con la libreria

Significado de las opciones:

- -Wall -Wextra -> mostrar todos los warnings (la practica debe compilar sin ninguno)
- -c -> solo compilar a fichero objeto (.o), sin enlazar
- -I. -> buscar los ficheros .h en el directorio actual
- -L. -> buscar las librerias en el directorio actual
- -llibreria -> enlazar con liblibreria.a (gcc añade "lib" delante y ".a" detras)

*Nota: -llibreria tiene que ir despues de test.c. En Linux el enlazador lee los ficheros en orden y solo coge de la libreria las funciones que ya sabe que se necesitan*

### Que hacer al cambiar algo

La libreria es estatica: al enlazar, el codigo de la libreria se copia dentro del ejecutable test. Por eso, aunque solo cambie la libreria, hay que volver a generar test.

- Si cambia libreria.c -> repetir los pasos 1, 2 y 3 (test.c no ha cambiado, pero test tiene dentro la version antigua de la libreria)
- Si cambia test.c -> repetir solo el paso 3 (la libreria no ha cambiado)
- Si cambia libreria.h -> repetir los pasos 1, 2 y 3 (los dos .c lo incluyen)




