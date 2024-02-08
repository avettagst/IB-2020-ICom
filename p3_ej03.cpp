#include "icom_helpers.h"

/*Considero a x la posici�n del extremo inferior de la aguja, siendo x=0 la posici�n de una l�nea
y x=L la de la l�nea superior consecutiva. Ese esquema de dos l�neas en 0 y L se repite para cada par de ellas
trazadas en la hoja.
Si x=0, el extremo del aguja est� sobre la l�nea inferior.
Siendo alfa el �ngulo que forma la aguja con las l�neas, partiendo desde su extremo inferior,
entonces x + sin(alfa) * L es la posici�n del extremo superior respecto a la l�nea inferior. Si �sta es mayor
o igual a L, la aguja cruza la l�nea superior.
alfa puede tomar cualquier valor, ya que el seno es una funci�n peri�dica (con per�odo 2pi). Dado que el seno de alfa var�a
entre -1 y 1, considero su valor absoluto.
*/

int main(){
    const int L = 1000;
    int x, alfa, a = 0;

    srand(time(0));

    cout << "�Con cu�ntos intentos desea aproximar pi?" << endl;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        x = double((rand() % L) / L);
        if (x==0){
                cout << "if";
            a++;
            continue;
        }

        alfa = rand();
        if (x + sin(alfa) <= 0 || x + sin(alfa) >= 1)
            cout << x << "     " << sin(alfa)<< endl;
            a++;
    }

    cout << "Pi es aproximadamente " << 2.0*n / a;

    return 0;
}
