#include "icom_helpers.h"

int main(){
    float suma = 0, x1 = 1.126, x2 = -1.125, x3 = -0.001;
    //double suma = 0, x1 = 1.126, x2 = -1.125, x3 = -0.001;

    for (int i = 0; i <= 0xFFFFFF; i++){
        suma += x1 + x2 + x3;
    }

    cout << "Suma: " << suma << endl;

    return 0;
}

/* x1 + x2 + x3 = 0, por lo que S deber�a ser 0. Esto no sucede
En cada t�rmino se da un peque�o error, de magnitud 10^(-16) cuando trabajo con double
y 10^(-8) con float. Este peque�o error, multiplicado por la cantidad de t�rminos sumados (16^7 - 1) termina dando
un error considerable para S, siendo S = -1.84809e-09 con double y S = 0.921545 con float
*/
