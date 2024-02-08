#include "icom_helpers.h"

struct A {
    int a, b;
    A(int x, int y){
        a=x;
        b=y;
        cout << "Construyendo con (" << x << ", " << y << ")" << endl;
    }
};

int main(){
    A x(45,2); // declaro x

    A y = x; // copio x en y

    cout << "Y = " << y.a << "\t" << y.b << endl; // veo que en y se copiaron los valores de x
}
