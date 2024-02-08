/*Hecho con alocación dinámica*/

#include "icom_helpers.h"

void TransponeNN(double*,int);


int main(){
    int t = 5;
    double* m;
    m = new double[t*t];
    srand(time(0));

    for (int i = 0; i < t; i++){
        for (int j = 0; j < t; j++)
            *(m + t*i + j) = rand() % 5;
    } //lleno la matriz de aleatoriamente con 0, 1, 2, 3 y 4


    cout << "Matriz original \n\n";
    for (int i = 0; i < t; i++){
        for (int j = 0; j < t; j++)
            cout << *(m + t*i + j) << "   ";
        cout << endl;
    }


    TransponeNN(m, t);

    cout << "\n\nMatriz traspuesta\n\n";
     for (int i = 0; i < t; i++){
        for (int j = 0; j < t; j++)
            cout << *(m + t*i + j) << "   ";
        cout << endl;
    }

    delete[] m;

    return 0;
}



void TransponeNN(double *matriz, int n){
    double aux;

    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            aux = *(matriz+ n*i + j);
            *(matriz+ n*i + j) = *(matriz+ n*j + i);
            *(matriz+ n*j + i) = aux;

            //esto es equivalente a lo de arriba (slide 11, clase 8)
//            aux = matriz[n*i + j];
//            matriz[i*n + j] = matriz[j*n + i];
//            matriz[j*n + i] = aux;
        }
    }
}
