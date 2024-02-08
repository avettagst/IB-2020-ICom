#include "icom_helpers.h"

void IngresaArreglo (double Vector[], int numElementos){ // el arreglo se pasa automaticamente por referencia
    int e;
    for (int i=0; i < numElementos; i++){
        cout << "Ingrese el elemento " << i << " del arreglo" << endl;
        cin >> e;
        Vector[i] = e;
    }
    cout << endl;
}

void ImprimeArreglo (double Vector[], int NumElementos){
    for (int i = 0; i < NumElementos; i++){
        cout << Vector[i] << endl;
    }
    cout << endl;
}

void IngresaVector (vector<int> &x, int N){ //debo pasarlo por referencia para llenar el vector
    int e;
    for (int i=0; i < N; i++){
        cout << "Ingrese el elemento " << i << " del vector" << endl;
        cin >> e;
        x[i] = e;
    }
    cout << endl;
}

void ImprimeVector (vector<int> x, int N){ //acá puedo pasar por argumento o no (más eficiente o más seguro)
    for (int i = 0; i < N; i++){
        cout << x[i] << endl;
    }
    cout << endl;
}

int main(){
    cout << "Tamaño del arreglo: " << endl;
    int N;
    cin >> N;

    vector<int> v(2);

    double nat[N] = {0};
    IngresaArreglo(nat, N);
    ImprimeArreglo(nat,N);

    IngresaVector(v, 2);
    ImprimeVector (v,2);
    return 0;
}
