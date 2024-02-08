#include "icom_helpers.h"

int *getPtr() {
    int a = 4;
    cout << "en getPtr - a: " << &a << endl;

    int *p = &a;
    return p;
}

int main(){
    int *p = getPtr();

    cout << "en el main - p: " << p;
}

/*
Por su prototipo, vemos que esta funci�n devuelve la direcci�n de memoria de una variable entera.

El problema es que devuelve la direcci�n de memoria de la variable a, la cual es una variable local de la funci�n
getPtr, por lo que al terminar dicha funci�n, esta variable "desaparece".
Por lo tanto, el puntero p (en el main) queda apuntando a un lugar de memoria inservible/inaccesible, lo cual ser�
un problema en caso de querer usarlo o modificarlo

El c�digo del enunciado fue levemente modificado para poder ver efectivamente que devuelve el lugar de memoria
de la variable local (con el c�digo original, no se imprim�a "correctamente" en el main)
*/
