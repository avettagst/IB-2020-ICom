#include "icom_helpers.h"

void IngresaArregloRndm (double Vector[], int numElementos){ // el arreglo se pasa automaticamente por referencia
    srand(time(0));

    for (int i=0; i < numElementos; i++){
        Vector[i] = rand();
    }
}

void ImprimeArreglo (double Vector[], int NumElementos){
    for (int i = 0; i < NumElementos; i++){
        cout << Vector[i] << endl;
    }
    cout << endl;
}

double promedio(double v[], int n){
    double suma = 0;
    for (int i = 0; i < n; i++){
        suma += v[i];
    }
    return suma/n;
}

double dstandard(double v[], int n){
    double acum = 0;
    double u = promedio(v, n);
    for (int i = 0; i < n; i++){
        acum += (v[i] - u) * (v[i] - u);
    }

    return sqrt(acum / (n-1));
}

int main(){
    cout << "Cantidad de elementos: ";
    int n;
    cin >> n;

    double arreglo[n];

    IngresaArregloRndm(arreglo, n);
    ImprimeArreglo(arreglo, n);

    cout << "El promedio de estos datos es: " << promedio(arreglo,n) << " y su desviacios estandar: " << dstandard(arreglo,n);







    return 0;
}
