#include "icom_helpers.h"

struct A {

    A(){ // al tener constructor copia, no me genera el constructor default
    }

    A (const A &x){
        cout << "Copiando A: " << &x << " en " << this << endl;
    }
};

struct B {
    A AenB;
};

int main(){
    B var1;
    B var2 = var1;

    return 0;
}
