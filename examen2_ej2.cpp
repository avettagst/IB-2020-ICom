#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cmath>

using namespace std;

class NNode {
    public:
        // inicializa un nuevo nodo con 'v' como valor del nodo
        NNode(int v) // ToDo
        : value(v){
            for (int i = 0; i < MAX_CHILD; i++)
                children[i] = nullptr;
        }

        // destruye el nodo
        ~NNode(){      // ToDo
            for (int i = 0; i < MAX_CHILD; i++)
                delete children[i];                     //FUERON ALOCADOS INDIVIDUALMENTE, NO COMO ARREGLO


//            delete[] children; //fueron alocados con addNode(int)
        }

        // agrega un nuevo nodo con valor 'v' cumpliendo los requerimientos dados
        void addNode(int v){  // ToDo
            if (peso() >= MAX_CHILD+1){
                if ((children[0]->peso() == children[1]->peso()) && (children[1]->peso()  == children[2]->peso()) &&
                    (children[2]->peso()== children[3]->peso())){
                                                                                    //si todos los hijos pesan lo mismo
                    //if (children[0]->peso() < 4)                                    //y es menos que 4
                        children[0]->addNode(v);
                    //else
                      //  children[0]->children[0]->addNode(v);                       //si todos pesan 4 o más, bajo al siguiente nivel
                }
                else{                                                               //si no pesan igual
                    int id = 0;
                    int p = children[0]->peso();                                    //me fijo cuál pesa menos
                    for (int i = 1; i < MAX_CHILD; i++){
//                        p = (children[i]->peso() < p) ? children[i]->peso() : p;      //SE LLAMA MUCHAS VECES A PESO(), FUNCIÓN RECURSIVA
//                        id = (children[i]->peso() < p) ? i : id;                      //ES UNA CAGADA
                        if ( p > children[i]->peso()){
                            children[i]->addNode(v);
                            return;
                        }
                    }
//                    children[id]->addNode(v);                                      //y agrego allí el nodo
                }

            }

            else {                                                                  //si pesa menos de 4
                NNode *nuevo = new NNode(v);                                        //aloco memoria
                children[peso()-1] = nuevo;                                         //y lo agrego en la posicion peso,
            }                                                                       //que puede ser 0, 1, 2 o 3
       }
        // cuenta y retorna la cantidad de nodos, incluyendose a si mismo
        int peso(){       // ToDo
            int p = 1;
            for (int i = 0; i < MAX_CHILD; i++){
                if (children[i]!= nullptr)
                    p+=children[i]->peso();
            }
            return p;
        }

        // retorna true/false indicando si 'v' esta contenido como 'value' en algun nodo
        bool esMiembro(int v){       // ToDo
            if (value == v)
                return true;

            bool res = false;
            for (int i = 0; i < MAX_CHILD; i++){
                if (children[i]!=nullptr)
                    res = children[i]->esMiembro(v);
                if (res)
                    return res;     //si lo encuentro en una rama, dejo de buscar
            }

            return res;             //si llego hasta acá, no lo encontré (res sigue siendo false
        }

        // retorna true si es un nodo terminal (sin hijos), falso en caso contrario
        bool esHoja(){  // ToDo
            if (children[0]==nullptr)
                return true;
            return false;
        }

        // retorna la altura (cantidad de niveles) que tiene el arbol.
        int altura(){     // ToDo
            int l = 1;
            int n_acum = 0;
            while(true){
                n_acum += pow(MAX_CHILD, l-1);
                if(peso() > n_acum)
                    l++;
                else
                    return l;
            }
        }

    private:
        int value;
        static const int MAX_CHILD = 4;
        NNode *children[MAX_CHILD];
};


int main()
{
    srand((unsigned int) time(NULL));
    NNode* arbol = new NNode(rand() % 1000);

    int hprev = 1;
    int pprev = 1;

    for (int i = 2; i <= 2500; i++) { //probar con 66 como mínimo
        arbol->addNode(rand() % 1000);
        int h = arbol->altura();
        if (h != hprev) {
            assert(i == arbol->peso());
            cout << "n: " << i - 1 << ", w: " << i - 1 << ", h: " << hprev << endl;
            cout << "n: " << i << ", w: " << arbol->peso() << ", h: " << h << ", n_lev: " << i - pprev << "\n...\n";
            hprev = h;
            pprev = i;
        }
    }

    cout << "Peso:        " << arbol->peso() << endl;
    cout << "Altura:      " << arbol->altura() << endl;
    cout << "esta el 10?: " << arbol->esMiembro(10) << endl;
    cout << "esta el 20?: " << arbol->esMiembro(20) << endl;
    cout << "esta el 30?: " << arbol->esMiembro(30) << endl;
    cout << "esta el 40?: " << arbol->esMiembro(40) << endl;
    cout << "esta el 50?: " << arbol->esMiembro(50) << endl;

    delete arbol;

    return 0;
}
