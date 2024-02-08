#include "icom_helpers.h"

double cte5(double x){
    return 5;
}

double suma(double x){
    return x+1;
}

double cuad(double x){
    return pow(x,2);
}

double recta(double x){
    return 2*x;
}

using fun_ptr_t = double (*)(double);

double integra(double a, double b, fun_ptr_t fun){
    const double error = 0.0001; // para determinar la convergencia
    double res = 0, res_ant = res + 2*error; // para entrar por primera vez al while
    int n = 1; // cantidad de intervalos
    double h; // ancho de los intervalos

    while (abs(res - res_ant) > error){
        n*=2; //aumento la cantidad de intervalos
        res_ant = res; //registro el resultado de la iteración anterior
        h = (b-a)/n; //defino el nuevo ancho de intervalo

        res = (fun(a) + fun(b)) / 2; //vuelvo a inicializar res

        for (double x = a + h; x < b; x += h){ //evaluo en cada extremo de intervalo (salvo a y b) y sumo en el resultado
            res += fun(x);
        }

        res *= h; // multiplico por el ancho de cada intervalo
    }
    return res;
}


int main(){

    //defino varias funciones para probar
    cout << "x^2 entre 0 y 3: " << integra(0,3,cuad) << endl;
    cout << "2x entre 0 y 2: " << integra(0,2,recta) << endl;
    cout << "x+1 entre 0 y 100: " << integra(0, 100, suma) << endl;
    cout << "seno entre 0 y pi/2: " << integra(0, 0.5*M_PI, sin) << endl;
    cout << "coseno entre 0 y pi: " << integra(0, M_PI, cos) << endl;
    cout << "seno entre 0 y pi: " << integra(0, M_PI, sin) << endl;
    cout << "seno entre 0 y 2pi: " << integra(0, 2*M_PI, sin) << endl;

    return 0;
}
