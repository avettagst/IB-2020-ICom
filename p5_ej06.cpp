#include "icom_helpers.h"

struct C{
    C() {
        cout << "Construyendo un C en " << this << endl;
    }
    C (const C &x){
        cout << "\nCopiando lo de " << &x << " en " << this << endl;
    }
};

void fun(C &param){ // por referencia
    cout << "Estoy en fun y me pasaron " << &param << endl;
}

void fun2(C param){ // por valor
    cout << "Estoy en fun2 y copie el parametro en " << &param << endl;
}

int main(){
    C obj;

    fun(obj); //no activa el copy constructor
    fun2(obj); //activa el copy constructor y trabaja en otro lugar de memoria

    return 0;
}
