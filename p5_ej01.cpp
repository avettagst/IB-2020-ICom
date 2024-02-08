#include "icom_helpers.h"
/*
Veo que se anuncia primero el constructor de A y luego el de B para cada uno de los elementos del
arreglo, ambos en el mismo lugar de memoria.

Si declaro alguna variable en la definición de B antes de la variable AenB, los lugares de memoria que anuncian
los constructores de A y B no coinciden. Además, la diferencia entre estos lugares de memoria
depende del tipo y la cantidad de variables declaradas antes de AenB.
(Dejo comentadas las variables que usé para probar esto)

Tambien vemos que, así declarados cómo están, las variables de tipo A y B ocupan solo un byte
*/

struct A{
    A(){
        cout << "Construyendo un A en " << this << endl;
    }
};

struct B{
    //double z;
    //int z2;
    A AenB;
    B(){
        cout << "Construyendo un B en " << this << endl;
    }
};

int main(){
    B arreglo[3];
    return 0;
}
