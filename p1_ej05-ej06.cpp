#include "icom_helpers.h"

int main()
{
    int n;
    cout << "Ingrese un numero entero: " << endl;
    cin >> n;
    if (n%2) cout << "El valor ingresado es " << n << " y es impar" << endl; //si la condición es 0 es false
    else cout << "El valor ingresado es " << n << " y es par" << endl;
    return 0;
}
