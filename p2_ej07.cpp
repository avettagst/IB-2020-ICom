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

/* x1 + x2 + x3 = 0, por lo que S debería ser 0. Esto no sucede
En cada término se da un pequeño error, de magnitud 10^(-16) cuando trabajo con double
y 10^(-8) con float. Este pequeño error, multiplicado por la cantidad de términos sumados (16^7 - 1) termina dando
un error considerable para S, siendo S = -1.84809e-09 con double y S = 0.921545 con float
*/
