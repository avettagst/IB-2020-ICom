#include <iostream>

using namespace std;

int main(){
    double x=1.9;
    int y;
    y=x;
    x=y;
    cout << "x = " << x << endl;
    return 0;
}
/*al guardar el valor 1.9 en una variable de tipo entero (y), éste se trunca, es decir, solo se almacena
su valor entero y se desecha la parte decimal. Luego, al copiar este valor modificado de vuelta en x,
se copia éste (1) por sobre el valor original (1.9)*/
