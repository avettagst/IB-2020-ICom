#include "icom_helpers.h"

void IngresaArreglo (int Vector[], int numElementos){
    int e;
    for (int i=0; i < numElementos; i++){
        cout << "Ingrese el elemento " << i << " del arreglo" << endl;
        cin >> e;
        Vector[i] = e;
    }
    cout << endl;
}

void ImprimeArreglo (int Vector[], int NumElementos){
    for (int i = 0; i < NumElementos; i++){
        cout << Vector[i] << endl;
    }
    cout << endl;
}

void OrdenaArrayNativo(int V[], int N){
    int aux;
    for (int i = 0; i < N-1; i++){
        for (int j = i+1; j < N; j++){
            if (V[i] > V[j]){
                aux = V[i];
                V[i] = V[j];
                V[j] = aux;
            }
        }
    }
}


int main(){
    cout << "Cantidad de elementos: ";
    int N;
    cin >> N;

    int enteros[N];
    IngresaArreglo(enteros, N);
    ImprimeArreglo(enteros,N);

    OrdenaArrayNativo(enteros, N);
    cout << "Después del ordenamiento: " << endl;
    ImprimeArreglo(enteros, N);

    return 0;
}
