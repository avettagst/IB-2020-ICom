#include "icom_helpers.h"

void fun() {
    int a = 4;
    int *pa;
    *pa = a;
}

/*
En esta función, se asigna el valor de la variable 'a' a un puntero no inicializado. Por lo tanto, se está modificando
un lugar de memoria "desconocido", lo cual puede traer problemas
*/
