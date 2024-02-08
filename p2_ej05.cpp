#include "icom_helpers.h"

double miSqrt(double a){
    double x=1, xant;
    const double e = pow(10,-6); //para determinar que converja a la ra�z
    int i = 0; //para determinar la cantidad de terminos sumados

    do {
        xant = x;
        x = (x + a / x) / 2;
        i++;
    } while (abs(x - xant) > e); //diferencia entre 2 t�rminos consecutivos

    cout << "\nCantidad de terminos sumados: " << i << endl;
    return x;
}

int main(){
    double a, raiz;

    do{
    cout << "Ingrese un numero mayor o igual a 0: ";
    cin >> a;
    } while (a < 0); //para asegurarme que ingrese un n�mero positivo

    raiz = miSqrt(a);
    cout << "La ra�z cuadrada de " << a << " es " << raiz;

    return 0;
}
/*
Vemos que la cantidad de t�rminos var�a levemente con el valor de a. Siendo por ejemplo 6 los pasos necesarios
para calcular la ra�z de 25, 11 para la ra�z de 1.000 y 18 para la ra�z de 100.000.000
Menciono tambien el caso especial de a=0, donde son necesarios 27 pasos y la ra�z obtenida es 7.45058e-09

No puedo encontrar la relaci�n num�rica entre a y la cantidad de pasos, pero probablemente sea logar�tmica
*/
