#include "icom_helpers.h"

/*
f recibe un argumento del tipo Base. Acepta a x porque Deriv es una clase derivada de Base, pero
para usarla solo se queda con la parte correspondiente a Base
*/


struct Base{
  protected:
    double db;
};

struct Deriv: public Base{
  double dd;
};

void f(Base &b){ //es lo mismo pasando por referencia o por copia
    cout << "En f: " << sizeof(b) << '\n';
}

int main(){
    Deriv x;

    cout << "En main: " << sizeof(x) << '\n';
    f(x);

    return 0;
}
