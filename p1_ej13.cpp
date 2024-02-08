#include "icom_helpers.h"

struct Punto3D_t {
    double x, y, z;
    void print() {
        cout << "(" <<x << ", " << y << ", " << z <<")" << endl;
    }

    double modulo() {
        return sqrt(x*x+y*y+z*z);
    }

    Punto3D_t operator+(Punto3D_t a) {
        Punto3D_t result = { x + a.x, y + a.y, z + a.z};
        return result;
    }

    Punto3D_t operator-(Punto3D_t a) {
        Punto3D_t result = { x - a.x, y - a.y, z - a.z};
        return result;
    }
};

int main() {
    Punto3D_t p1, p2;
    cout << "Ingrese las coordenadas del punto 1 (separadas por un espacio o enter): " << endl;
    cin >> p1.x >> p1.y >> p1.z;

    cout << "Ingrese las coordenadas del punto 2 (separadas por un espacio o enter): " << endl;
    cin >> p2.x >> p2.y >> p2.z;

    cout << "\np1 = "; p1.print();
    cout << "p2 = "; p2.print();

    Punto3D_t d = p1 - p2;
    cout << "\nLa distancia entre p1 y p2 es " << d.modulo() << endl;

    return 0;
}
