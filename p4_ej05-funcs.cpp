#include "icom_helpers.h"
#include "p4.h"

void ImprimeArreglo (int Vector[], int NumElementos){
    for (int i = 0; i < NumElementos; i++){
        cout << Vector[i] << endl;
    }
}

void IngresaArregloRndm (int Vector[], int numElementos){ // el arreglo se pasa automaticamente por referencia
    srand(time(0));

    for (int i=0; i < numElementos; i++)
        Vector[i] = rand();

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
