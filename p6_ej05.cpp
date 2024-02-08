#include "icom_helpers.h"

const int MX = 6, MY = 5; //defino el tamaño de la matriz como variables globales
                          //como el ejemplo de la clase 4 (diapositiva 11)

void FloodFill(int M[MX][MY], int X, int Y, int C1){

    M[X][Y] = C1;

    if(M[X+1][Y] != C1)
        FloodFill(M, X+1, Y, C1);
    if(M[X-1][Y] != C1)
        FloodFill(M, X-1, Y, C1);
    if(M[X][Y+1] != C1)
        FloodFill(M, X, Y+1, C1);
    if(M[X][Y-1] != C1)
        FloodFill(M, X, Y-1, C1);
}

int main(){
    int c = 5; //"color" de la curva

    int mat[MX][MY] = {{0,0,c,0,0},
                       {0,c,0,c,c},
                       {0,c,0,0,c},
                       {c,0,0,0,c},
                       {0,c,c,c,0},
                       {0,0,0,0,0}}; //defino una matriz 6x5 con una curva cerrada

    int x = 2, y = 3; // punto interior

    cout << "Matriz inicial\n\n";
    for (int i = 0; i < MX; i++){
        for (int j = 0; j < MY; j++){
            cout << mat[i][j] << "  ";
        }
        cout << endl;
    }

    FloodFill(mat, x, y, c);

    cout << "\n\nLuego de FloodFill\n\n";
    for (int i = 0; i < MX; i++){
        for (int j = 0; j < MY; j++){
            cout << mat[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}
