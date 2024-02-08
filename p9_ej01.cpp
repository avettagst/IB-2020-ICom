#include "icom_helpers.h"

struct Terna {
    int i;
    int j;
    int value;

    bool operator<(const Terna &a){
        return value<a.value; //ordena según value
    }

    double dist(){
        return sqrt(i*i + j*j);
    }
};

bool comp_dist(const Terna &a, const Terna &b){
    return a.i * a.i + a.j * a.j < b.i * b.i + b.j * b.j;
}

int main(){
    const int tam = 10;
    array<Terna, 10> vec {Terna{4,5,6},
                        Terna{7,8,9},
                        Terna{25,26,27},
                        Terna{10,11,145},
                        Terna{345,21,89},
                        Terna{13,62,89},
                        Terna{19,20,-21},
                        Terna{-10,78,-100},
                        Terna{100,45,63},
                        Terna{1,2,56}};


    cout << "Vector original:";
    cout << "\n---------------------------\n";
    cout << "i\tj\tvalue \n\n";

    for (int i = 0; i < tam; i++)
        cout << vec[i].i << "\t" << vec[i].j << "\t" << vec[i].value << endl;

    cout << "\n\nORDENO DE MENOR A MAYOR\n";
    sort(vec.begin(),vec.end()); //de menor a mayor, por value
                                 //utilizando el operador <, por eso no le paso
                                 //funcion como parametro

    cout << "\nVector ordenado por value:";
    cout << "\n---------------------------\n";
    cout << "i\tj\tvalue \n\n";

    for (int i = 0; i < tam; i++)
        cout << vec[i].i << "\t" << vec[i].j << "\t" << vec[i].value << endl;


    sort(vec.begin(),vec.end(), comp_dist); //de menor a mayor, por distancia al origen
                                            //usando la funcion comp_dist para comparar

    cout << "\n\nVector ordenado por distancia al origen:";
    cout << "\n---------------------------\n";
    cout << "i\tj\tvalue\tdistancia \n\n";

    for (int i = 0; i < tam; i++)
        cout << vec[i].i << "\t" << vec[i].j << "\t" << vec[i].value << "\t" << vec[i].dist() << endl;

    cout << "\n\nORDENO DE MAYOR A MENOR\n";
    sort(vec.rbegin(),vec.rend()); //de mayor a menor, por value

    cout << "\nVector ordenado por value:";
    cout << "\n---------------------------\n";
    cout << "i\tj\tvalue \n\n";

    for (int i = 0; i < tam; i++)
        cout << vec[i].i << "\t" << vec[i].j << "\t" << vec[i].value << endl;


    sort(vec.rbegin(),vec.rend(), comp_dist); //de mayor a menor, por distancia al origen

    cout << "\n\nVector ordenado por distancia al origen:";
    cout << "\n---------------------------\n";
    cout << "i\tj\tvalue\tdistancia \n\n";

    for (int i = 0; i < tam; i++)
        cout << vec[i].i << "\t" << vec[i].j << "\t" << vec[i].value << "\t" << vec[i].dist() << endl;
    return 0;
}
