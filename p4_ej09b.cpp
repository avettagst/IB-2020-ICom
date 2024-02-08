#include "icom_helpers.h"

struct Punto2D {
    double x, y;

    Punto2D operator-(Punto2D a) {
        Punto2D result = {x - a.x, y - a.y};
        return result;
    }

    double mod2(){ //módulo cuadrado
        return x*x+y*y;
    }
};

int pitagoras(double hip, double c1, double c2){ //los parametros son los módulos cuadrados
    if (hip > c1 + c2)
        return 2; //obtusangulo
    else{
        if (hip == c1 + c2)
            return 1; //rectangulo
        else
            return 0; //acutangulo
    }
}

struct Triangulo {
    Punto2D vertices[3], lados[3]; //representación de los lados como vectores

    enum ClaseLado { EQUILATERO, ISOSCELES, ESCALENO, errorLado };
    enum ClaseAngulo { ACUTANGULO, RECTANGULO, OBTUSANGULO };

    ClaseLado clasificaPorLado(){
        int igualdades = 0;
        igualdades += (abs(lados[0].mod2() - lados[1].mod2()) < 0.01)? 1:0; //para evitar errores de precisión
        igualdades += (abs(lados[0].mod2() - lados[2].mod2()) < 0.01)? 1:0; // a partir del 3er decimal
        igualdades += (abs(lados[1].mod2() - lados[2].mod2()) < 0.01)? 1:0;

        switch (igualdades){
            case 0:
                return ESCALENO;
            case 1:
                return ISOSCELES;
            case 3:
                return EQUILATERO;
            default:
                return errorLado;
        }
    }

    ClaseAngulo clasificaPorAngulo(){
        //chequeo cuál es el lado más largo para pasar los parámetros correctamente a pitágoras

        if (lados[0].mod2() >= lados[1].mod2() && lados[0].mod2() >= lados[2].mod2())
            return ClaseAngulo(pitagoras(lados[0].mod2(), lados[1].mod2(), lados[2].mod2()));
        else{
            if ((lados[1].mod2() > lados[0].mod2() && lados[1].mod2() >= lados[2].mod2()))
                return ClaseAngulo(pitagoras(lados[1].mod2(), lados[0].mod2(), lados[2].mod2()));
            else
                return ClaseAngulo(pitagoras(lados[2].mod2(), lados[0].mod2(), lados[1].mod2()));
        }
    }
};


int main(){
    Triangulo t;

    //ingreso vértices
    cout << "Ingrese las coordenadas del primer vertice" << endl;
    cin >> t.vertices[0].x >> t.vertices[0].y;
    cout << "Ingrese las coordenadas del segundo vertice" << endl;
    cin >> t.vertices[1].x >> t.vertices[1].y;
    cout << "Ingrese las coordenadas del tercer vertice" << endl;
    cin >> t.vertices[2].x >> t.vertices[2].y;
    cout << endl;

    //defino lados
    t.lados[0] = t.vertices[1] - t.vertices[0];
    t.lados[1] = t.vertices[2] - t.vertices[1];
    t.lados[2] = t.vertices[0] - t.vertices[2];

    for (int j = 0; j < 3; j++){
        if (t.lados[j].mod2() == 0){
            cout << "No es un triangulo";
            return 0;
        }
    }

    switch (t.clasificaPorLado()){
        case 0:
            cout << "Lados: equilatero" << endl;
            break;
        case 1:
            cout << "Lados: isosceles" << endl;
            break;
        case 2:
            cout << "Lados: escaleno" << endl;
            break;
        default:
            cout << "Hubo un error" << endl;
    }

    switch (t.clasificaPorAngulo()){
        case 0:
            cout << "Angulo: acutangulo" << endl;
            break;
        case 1:
            cout << "Angulo: rectangulo" << endl;
            break;
        case 2:
            cout << "Angulo: obtusangulo" << endl;
            break;
    }

    return 0;
}
