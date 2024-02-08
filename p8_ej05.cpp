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
Por su prototipo, vemos que esta función devuelve la dirección de memoria de una variable entera.

El problema es que devuelve la dirección de memoria de la variable a, la cual es una variable local de la función
getPtr, por lo que al terminar dicha función, esta variable "desaparece".
Por lo tanto, el puntero p (en el main) queda apuntando a un lugar de memoria inservible/inaccesible, lo cual será
un problema en caso de querer usarlo o modificarlo

El código del enunciado fue levemente modificado para poder ver efectivamente que devuelve el lugar de memoria
de la variable local (con el código original, no se imprimía "correctamente" en el main)
*/
