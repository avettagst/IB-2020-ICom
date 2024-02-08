#include "icom_helpers.h"

int desempaquetar(unsigned int color, int pos){
    //pos se refiere a la posicion de la componente de izquierda a derecha (1, 2 o 3)
    unsigned char comp;

    comp = (color << pos*8) >> 24;

    return comp;
}

int main(){
    int opc;

    cout << "Ingrese una opción" << endl;
    cout << "1 - Ingresar las componentes RGB de un color y empaquetarlo" << endl;
    cout << "2 - Desempaquetar un color en sus componentes RGB" << endl;
    cin >> opc;
    assert (opc == 1 || opc == 2);

    if (opc - 2){
        unsigned int R, G, B, color = 0;

        cout << "\nIngrese las componentes RGB (rojo, verde, azul) del píxel:" << endl;
        cout << "R: ";
        cin >> R;
        cout << "G: ";
        cin >> G;
        cout << "B: ";
        cin >> B;

        assert(R <= 255 && R >=0 && G <= 255 && G >=0 && B <= 255 && B >=0);

        color = (color + B) << 8;
        color = (color + G) << 8;
        color = color + R;

        cout << "El color empaquetado es " << hex<<color << endl;

    }

    else {
        unsigned int col_emp, desR, desG, desB;

        cout << "\nIngrese el color empaquetado: ";
        cin >> hex >> col_emp;

        desR=desempaquetar(col_emp, 3);
        desG=desempaquetar(col_emp, 2);
        desB=desempaquetar(col_emp, 1);

        cout << "\nR = " << desR << endl;
        cout << "G = " << desG << endl;
        cout << "B = " << desB << endl;
    }

    return 0;
}
