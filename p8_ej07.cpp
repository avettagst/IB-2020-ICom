#include "icom_helpers.h"

void fun();

int main(){
    fun();
    return 0;
}


void fun() {
    int a[3][3] = { 0 };

    //Muestro matriz original
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
            cout << a[i][j] << " ";
        cout << '\n';
    }

    int *pFilas[3] = { &a[0][0], &a[1][0], &a[2][0] }; //arreglo de punteros a enteros que apuntan al primer elemento de cada fila
    pFilas[0][0] = pFilas[1][0] = pFilas[2][0] = 1; //a cada elemento del arreglo de punteros, le cambio su primer elemento

    cout << "\n\n";

    //Muestro qué hace la función
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
            cout << a[i][j] << " ";
        cout << '\n';
    }
}
