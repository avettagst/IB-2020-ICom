#include "icom_helpers.h"

int main(){

    ifstream archivo("peaks.dat");

    float x, y, x_max, y_max;
    bool primero = true;

    if (archivo.is_open()){
        while(archivo >> x >> y){
            if (primero){
                x_max = x;
                y_max = x;
                primero = false;
            }
            if (y > y_max){
                x_max = x;
                y_max = y;
            }
        }
        archivo.close();
        cout << "Y = " << y_max <<" es el mayor Y y corresponde a X = " << x_max << endl;
    }
    else
        cout << "Hubo un problema tratando de abrir el archivo" << endl;

    return 0;
}
