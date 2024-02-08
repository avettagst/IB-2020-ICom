#include "icom_helpers.h"

struct C{
    int a,b;
    C(int x, int y){
        a=x;
        b=y;
        cout << "Construyendo con T(int, int) " << endl;
    }
};

int main(){

    C v; //con esta declaración de v, no funciona

    /*
    Con cualquiera de las siguientes declaraciones, funciona:

    C v();

    C v(2,3);
    */

    return 0;
}
