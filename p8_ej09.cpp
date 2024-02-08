#include "icom_helpers.h"

struct Terna {
    int i;
    int j;
    int value;

    double dist(){
        return sqrt(i*i + j*j);
    }
};

//Esta es la función de comparación para ordenar según el campo value
int comp_val(const void* p1, const void* p2){
    Terna *a = (Terna*)p1;
    Terna *b = (Terna*)p2; //casteo los punteros void

    return (a->value - b->value);
}


//Esta es la función de comparación para ordenar según la distancia al origen
int comp_dist(const void* p1, const void* p2){
    Terna *a = (Terna*)p1;
    Terna *b = (Terna*)p2; //casteo los punteros void

    return a->dist() - b->dist();
}

int main(){
    const int tam = 10;
    Terna arreglo[tam] = {{4,5,6},
                        {7,8,9},
                        {25,26,27},
                        {10,11,145},
                        {345,21,89},
                        {13,62,15},
                        {19,20,-21},
                        {-10,78,-100},
                        {100,45,63},
                        {80,97,6}};

    cout << "Arreglo original:";
    cout << "\n---------------------------\n";
    cout << "i\tj\tvalue \n\n";

    for (int i = 0; i < tam; i++)
        cout << arreglo[i].i << "\t" << arreglo[i].j << "\t" << arreglo[i].value << endl;


    qsort(arreglo, tam, sizeof(Terna), comp_val);//ordeno por value

    cout << "\n\nArreglo ordenado por value:";
    cout << "\n---------------------------\n";
    cout << "i\tj\tvalue \n\n";

    for (int i = 0; i < tam; i++)
        cout << arreglo[i].i << "\t" << arreglo[i].j << "\t" << arreglo[i].value << endl;


    qsort(arreglo, tam, sizeof(Terna), comp_dist); //ordeno por distancia

    cout << "\n\nArreglo ordenado por distancia al origen:";
    cout << "\n---------------------------\n";
    cout << "i\tj\tvalue\tdistancia \n\n";

    for (int i = 0; i < tam; i++)
        cout << arreglo[i].i << "\t" << arreglo[i].j << "\t" << arreglo[i].value << "\t" << arreglo[i].dist() << endl;

    return 0;
}
