#include "icom_helpers.h"

/*
Cantidad de movimientos: 2^n - 1
Para n = 99 y 10^6 operaciones por segundo, tardaría más de 20 x 10^15 milenios
*/

int i = 0;

void hanoi(int n, int from, int to, int aux) {
    if(n == 1){
        cout << "Mover de " << from << " a " << to << endl;
        i++; //por cada movimiento
        return;
    }

    hanoi( n-1, from, aux, to);
    hanoi( 1, from, to, aux);
    hanoi( n-1, aux, to, from);
}
int main() {
    hanoi(8, 1, 3, 2);
    cout <<"\n\nTotal de movimientos: " << i << endl;

    return 0;
}
