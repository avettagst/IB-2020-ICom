#include "icom_helpers.h"

void IngresaArreglo (int Vector[], int numElementos){ // el arreglo se pasa automaticamente por referencia
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

void InvierteArrayNativo(int V[], int n){
    int aux;
    for (int i=0; i < n / 2; i++){
        if (V[i] == V[n - i - 1])
            break; //me ahorro las operaciones
        aux = V[i];
        V[i] = V[n-1-i];
        V[n-1-i] = aux;
    }
}

int main(){
    cout << "Ingrese tamaño del arreglo: ";
    int n;
    cin >> n;
    cout << endl;

    int arreglo[n];

    IngresaArreglo(arreglo, n);
    ImprimeArreglo(arreglo, n);

    InvierteArrayNativo(arreglo, n);
    cout << "\nDespués de invertirlo: " << endl;
    ImprimeArreglo(arreglo,n);

    return 0;
}
