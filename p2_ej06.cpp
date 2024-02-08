#include "icom_helpers.h"

double calculaE(){
    double e = 0, eanterior, fact = 1;
    int i = 1;
    const double err = pow(10,-6);

    do{
        eanterior = e;
        e += 1.0 / fact;
        fact *= i;
        i++;
    } while (abs (e - eanterior) > err); //diferencia entre 2 términos consecutivos

    return e;
}

int main(){

    cout << "La constante e es " << calculaE() << endl;

    return 0;
}
