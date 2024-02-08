#include "icom_helpers.h"
/*
Veo que el orden de destrucción es contrario al de construcción en dos sentidos distintos:

1. Al construir una instancia de B, se construye primero su variable en A y luego dicha instancia.
Al destruir una instancia, sucede lo contrario: primero se destruye la instancia de B y luego su variable
de tipo A

2. Al construir un arreglo de instancias de B, logicamente primero se construye el elemento que ocupa la posición 0,
siguiendo consecutivamente hasta la posición N-1. La destrucción de estos elementos es en orden contrario: primero se
destruye el elemento en la posición N-1 y por último el de posición 0.

(Dejo comentado el for que utilicé para ver el orden en el que eran creados los elementos)
*/

struct A{
    A(){
        cout << "Construyendo un A en " << this << endl;
    }

    ~A(){
        cout << "Destruyendo el A guardado en " << this << endl;
    }
};

struct B{
    //double z;
    //int z2;
    A AenB;
    B(){
        cout << "Construyendo un B en " << this << endl;
    }

    ~B() {
        cout << "Destruyendo el B guardado en " << this << endl;
    }
};

int main(){
    B arreglo[3];

    /*
    for (int i = 0; i < 3; i++)
        cout << &arreglo[i] << endl;
    */

    return 0;
}
