#include "icom_helpers.h"

/*
En la primera de estas líneas, con (10), se aloca memoria para una instancia de tipo A
inicializada con val = 10, mediante el constructor con argumento declarado
dentro del struct, y con el puntero pa apuntando allí.

En la línea siguiente, con [10], se aloca memoria para un arreglo de 10 elementos de tipo A,
creados con el constructor sin parametro (por lo que val =0), donde pb es un puntero al primero
de éstos.

Por lo tanto, uno se deberá eliminar con el operador delete y otro con delete []
*/

struct A {
    int val;
    A() {
        val=0;
        cout << "A default: "<<this << '\t' << val << endl;
    }
    A(int v) {
        val=v;
        cout<< " A con argumento: "<< this << '\t' << val << endl;
    }
    ~A() {
        cout << "~A: "<< this << '\t' << val<<endl;
    }
};

int main(){
    A *pa = new A(10);
    A *pb = new A[10];

    // destruccion de pa y pb
    delete pa;
    delete [] pb;

    return 0;
}
