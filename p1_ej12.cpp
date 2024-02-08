#include "icom_helpers.h"

struct Complejo {
    double re, im;
    void print() {
        cout << "(" <<re << " + i " << im << ")\n";
    }

    Complejo operator+(Complejo a) {
        Complejo result = { re + a.re, im + a.im};
        return result;
    }

    Complejo operator-(Complejo a) {
        Complejo result = { re - a.re, im - a.im};
        return result;
    }

    Complejo operator*(Complejo a) {
        Complejo result = { re * a.re - im * a.im, re * a.im + im * a.re};
        return result;
    }

    Complejo operator/(Complejo a) {
        Complejo result = { (re * a.re + im * a.im)/(a.re*a.re+a.im*a.im) , (re * a.im - im * a.re)/(a.re*a.re+a.im*a.im)};
        return result;
    }

};

int main() {
    Complejo x, y, suma, resta, mult, div;
    cout << "Ingrese un número complejo x (partes separadas por un espacio o enter): " << endl;
    cin >> x.re >> x.im;

    cout << "Ingrese un número complejo y (partes separadas por un espacio o enter): " << endl;
    cin >> y.re >> y.im;

    cout << "x = "; x.print();
    cout << "y = "; y.print();

    suma = x + y;
    resta = x - y;
    mult = x * y;
    div = x / y;

    cout << "x + y = "; suma.print();
    cout << "x - y = "; resta.print();
    cout << "x * y = "; mult.print();
    cout << "x / y = "; div.print();

    return 0;
}
