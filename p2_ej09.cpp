#include "icom_helpers.h"

struct RGB {
    unsigned char R, G, B;

    unsigned int compositeColor() {
        unsigned int color = 0;

        color = (color + B) << 8;  //sumo los 8 bits de B
        color = (color + G) << 8;  //ahora los 8 bits de G
        color = color + R;  //sumo los bits de R

        return color;
    }

    bool setFromComposite (unsigned int color) {
        if (color >> 24)  //corto los primeros 24 bits y chequeo que el resto sean 0
            return false;

        return true;
    }

    void print() {
        unsigned int aux = R; //para imprimir correctamente las componentes
        cout << "R: " << aux;

        aux = G;
        cout << "G: " << aux;

        aux = B;
        cout << "B: " << aux;
  }
};

int main(){
    RGB pixel;
    unsigned int aux; //para almacenar los valores de las componentes correctamente

        cout << "Ingrese las componentes del píxel (entre 0 y 255):" << endl;

        do {
            cout << "R: ";
            cin >> aux;
        }while(aux<0 | aux > 255);
        pixel.R = aux;
        cout << endl;

        do {
            cout << "G: ";
            cin >> aux;
        }while(aux<0 | aux > 255);
        pixel.G = aux;
        cout << endl;

        do {
            cout << "B: ";
            cin >> aux;
        }while(aux<0 | aux > 255);
        pixel.B = aux;
        cout << endl;

        if (pixel.setFromComposite(pixel.compositeColor())) //si el método .set devuelve true, muestro el entero
            cout << "Ese color queda representado por el código " << hex<<pixel.compositeColor() << endl;

        else {
            cout << "No se pudo componer el número entero que representa al color ingresado." << endl;
            cout << "Sus componentes son" << endl; pixel.print();
        }

    return 0;
}
