#include "icom_helpers.h"
#include "p4.h"

int main(){
//    cout << "Ingrese tamaño del arreglo: "
//    int n;
//    cin >> n;
    int n = 1000;

    int arreglo[n];

    IngresaArregloRndm(arreglo, n);
    ImprimeArreglo(arreglo, n);
    OrdenaArrayNativo(arreglo, n);
    cout << "\nDespués de ordenarlo\n";
    ImprimeArreglo(arreglo, n);

    return 0;
}
