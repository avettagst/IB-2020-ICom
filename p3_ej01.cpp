#include "icom_helpers.h"

int main(){
    double x,y;
    int n = 0;
    const int cant_puntos = 100000;
    srand(time(0));

    for (int i = 0; i < cant_puntos; i++){
        x = (double) rand() / RAND_MAX; //si no convierto a double devuelve siempre 0 (eventualmente 1 para rand() = RAND_MAX)
        y = (double) rand() / RAND_MAX;

        if (x*x+y*y <= 1)
            n++;
    }

    cout << "Pi es aproximadamente " << (double)4*n / cant_puntos;

    return 0;
}
