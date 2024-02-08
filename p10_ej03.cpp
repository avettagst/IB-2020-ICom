#include "icom_helpers.h"

/*EJERCICIOS 1 y 2 ya están hechos con el destructor virtual
Si lo hago no virtual en Figura, no se ejecuta el constructor
específico de cada clase derivada*/

struct Figura{
    virtual void dibujar() const{
        cout << "Figura::dibujar\n";
    }

    Figura(){
        cout << "construyendo figura\n";
    }

    virtual ~Figura(){
        cout << "destruyendo figura\n";
    };
};

struct Cuadrado: public Figura{
    Cuadrado(){
        cout << "construyendo cuadrado\n";
    }

    ~Cuadrado(){
        cout << "destruyendo cuadrado\n";
    }

    void dibujar() const override{
        cout << "Cuadrado::dibujar\n";
    }
};

struct Circulo: public Figura{
    Circulo(){
        cout << "construyendo circulo\n";
    }

    ~Circulo(){
        cout << "destruyendo circulo\n";
    }

    void dibujar() const override{
        cout << "Circulo::dibujar\n";
    }
};

struct Triangulo: public Figura{
    Triangulo(){
        cout << "construyendo triangulo\n";
    }

    ~Triangulo(){
        cout << "destruyendo triangulo\n";
    }
    void dibujar() const override{
        cout << "Triangulo::dibujar\n";
    }
};


int main(){

    Figura *A[] = {new Cuadrado,
                          new Circulo,
                          new Triangulo};

    cout << '\n';

    A[0]->dibujar();
    A[1]->dibujar();
    A[2]->dibujar();
    //en Figura, dibujar() es virtual. Además en todas las figuras dibujar() está marcada como override

    cout << '\n';

    delete A[0]; delete A[1]; delete A[2];

    return 0;
}
