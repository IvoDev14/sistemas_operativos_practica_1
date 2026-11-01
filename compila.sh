#!/bin/bash
set -e # Si algún mandato falla, el script se detiene

gcc -c libreria.c -o libreria.o
echo "libreria.o generado"

ar -rv liblibreria.a libreria.o
echo "libreria.a creada"

gcc -o test test.c -I. -L. -llibreria
echo "test.c compilado y enlazado con libreria"