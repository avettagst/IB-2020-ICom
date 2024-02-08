#include "icom_helpers.h"

/*Considero a x la posición del extremo inferior de la aguja, siendo x=0 la posición de una línea
y x=L la de la línea superior consecutiva. Ese esquema de dos líneas en 0 y L se repite para cada par de ellas
trazadas en la hoja.
Si x=0, el extremo del aguja está sobre la línea inferior.
Siendo alfa el ángulo que forma la aguja con las líneas, partiendo desde su extremo inferior,
entonces x + sin(alfa) * L es la posición del extremo superior respecto a la línea inferior. Si ésta es mayor
o igual a L, la aguja cruza la línea superior.
alfa puede tomar cualquier valor, ya que el seno es una función periódica (con período 2pi). Dado que el seno de alfa varía
entre -1 y 1, considero su valor absoluto.
*/

int main(){
    const int L = 1000;
    int x, alfa, a = 0;

    srand(time(0));

    cout << "¿Con cuántos intentos desea aproximar pi?" << endl;
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
