#include "icom_helpers.h"

enum Direction {		// enumeración de las posibles direcciones (la última es auxiliar)
    UL, U, UR, L, N, R, DL, D, DR, NUM_DIRS
}; // U = up - D = down - L = left - R = right

struct Entity {		// Tipo definido por el usuario para representar a la entidad
    int x, y;             // representación: 2 enteros para representar la posicion

    void move(Direction d) {	// método para mover la entidad en una dirección determinada
        switch(d) {
            case UL:
                x--;
                y++;
                break;
            case U:
                y++;
                break;
            case UR:
                x++;
                y++;
                break;
            case L:
                x--;
                break;
            case N:
                break;
            case R:
                x++;
                break;
            case DL:
                x--;
                y--;
                break;
            case D:
                y--;
                break;
            case DR:
                x++;
                y--;
                break;
            default:
                break;  // si llega hasta aca debería disparar una excepcion
        }
    }

    void print() {
      cout << "X: " << x << " Y: " << y << " Dist.: " << sqrt(x*x+y*y) << '\n';
   }
};

double experimento (int n){
    Entity e = { 0, 0 };
    const int pasos_intermedios = 1000;

    for(int i = 1; i <= n; i++){
        e.move(Direction(rand() % NUM_DIRS));

        //ESTE ES EL PROCESO PARA MOSTRAR TODO CADA pasos_intermedios PASOS
//        if (i % pasos_intermedios == 0){
//            cout << "Pasos dados: " << i << endl;
//            e.print();
//            cout << endl;
//        }
    }

    return sqrt(e.x*e.x+e.y*e.y);
}

double experimentos (int n, int m){
    double acum = 0;

    for (int i = 0; i < m; i++){
        acum += experimento(n);
    }

    return acum/m;
}

int main() {
    cout << "Ingrese la cantidad de pasos del caminante: ";
    int n;
    cin >> n;

    cout << "¿Cuántas veces desea realizar el experimento? ";
    int m;
    cin >> m;

    srand(time(0));

    cout << "La distancia promedio del caminante al origen luego de realizar " << m;
    cout<< " veces el experimento con " << n << " pasos es " << experimentos (n,m) << endl;

    return 0;
}
