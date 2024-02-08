#include "icom_helpers.h"

struct A {
    int a, b;

    A(int x, int y){
        a=x;
        b=y;
        cout << "Construyendo con (" << x << ", " << y << ")" << endl;
    }
};

void func (A arg){ //5b
    //arg es una copia de x, y vemos que al crearse no se anuncia el constructor de A

    arg.a = 8; //esto no cambia el valor de x.a
    cout << "5b - en funcion // arg = " << arg.a << " " << arg.b << endl;
    //arg es una copia de x, y vemos que al crearse no se anuncia el constructor de A
}

A func2(){
    A resultado(8,9);
    return resultado;

}

int main(){
    A x(45,2); // declaro x

    A y = x; // 5a
    cout <<"5a - Y = " << y.a << " " << y.b << endl;

    func(x); // 5b

    A z = func2(); //5c
    cout << "5c - Z = " << z.a << " " << z.b << endl;

    /*
    Tambien sirve imprimir directamente:

    cout << func2().a << "\t" << func2().b << endl;\

    PEEERO llamo 2 veces a la función, por lo que se anuncia dos veces el constructor
    */

    return 0;
}
