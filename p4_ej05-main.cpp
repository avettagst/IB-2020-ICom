#include "icom_helpers.h"
#include "p4.h"

int main(){
//    cout << "Ingrese tama�o del arreglo: "
//    int n;
//    cin >> n;
    int n = 1000;

    int arreglo[n];

    IngresaArregloRndm(arreglo, n);
    ImprimeArreglo(arreglo, n);
    OrdenaArrayNativo(arreglo, n);
    cout << "\nDespu�s de ordenarlo\n";
    ImprimeArreglo(arreglo, n);

    return 0;
}
