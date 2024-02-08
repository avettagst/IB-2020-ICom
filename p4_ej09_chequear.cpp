#include "icom_helpers.h"

struct Punto2D {
    double x;
    double y;

    double modulo() { //en realidad es módulo cuadrado
        cout << "ENTRO A MODULO Y X="<<x << "E Y="<<y <<endl;
        return x*x+y*y;
    }

     Punto2D operator-(Punto2D a) {
        Punto2D result = { x - a.x, y - a.y};
        return result;
    }

    int operator*(Punto2D a) {
        int result = x*a.x + y*a.y;
        return result;
    }
};

//int pitagoras(Punto2D h, Punto2D c1, Punto2D c2){
//    if(h.modulo() < c1.modulo() + c2.modulo()){
//        return 0;
//    }
//    else{
//        if (h.modulo() == c1.modulo() + c2.modulo()){
//            cout << "pitagoras: rectangulo" << endl;
//            return 1;
//        }
//        else{
//            return 2;
//        }
//    }
//}

struct Triangulo {
    Punto2D vertices[3];
    Punto2D L1 = (vertices[1] - vertices[2]);
    Punto2D L2 = (vertices[1] - vertices[3]);
    Punto2D L3 = (vertices[2] - vertices[3]); //lados del triangulo dados como vectores
    enum ClaseLado { EQUILATERO, ISOCELES, ESCALENO };
    enum ClaseAngulo { ACUTANGULO, RECTANGULO, OBTUSANGULO };

    ClaseLado clasificaPorLado(){
        Punto2D L1 = (vertices[1] - vertices[2]);
        Punto2D L2 = (vertices[1] - vertices[3]);
        Punto2D L3 = (vertices[2] - vertices[3]);

        if (L1.modulo() == L2.modulo() && L1.modulo() == L3.modulo())
            return EQUILATERO;
        else{
            if(L1.modulo() != L2.modulo() && L1.modulo() != L3.modulo() && L2.modulo() != L3.modulo())
                return ESCALENO;
            else
                return ISOCELES;
        }
    }



    ClaseAngulo clasificaPorAngulo(){
        if (L1*L2 < 0 || L1*L3 < 0 || L2*L3 < 0)
            return OBTUSANGULO;
        else{
            if (L1*L2 == 0 || L1*L3 == 0 || L2*L3 == 0){
                cout << "pitagoras: rectangulo" << endl;
                return RECTANGULO;
            }
            else
                return ACUTANGULO;
        }




    }
//    ClaseAngulo clasificaPorAngulo(){
//        if (L1.modulo() >= L2.modulo() && L1.modulo() >= L3.modulo())
//            return ClaseAngulo(pitagoras(L1, L2, L3));
//        else
//            if (L2.modulo() >= L1.modulo() && L2.modulo() >= L3.modulo())
//                return ClaseAngulo(pitagoras (L2, L1, L3));
//            else
//                return ClaseAngulo(pitagoras (L3, L1, L2));
//    }
};

int main(){
    Triangulo t;

    cout << "Ingrese las coordenadas del primer vértice" << endl;
    cin >> t.vertices[0].x >> t.vertices[0].y;

    cout << "Ingrese las coordenadas del segundo vértice" << endl;
    cin >> t.vertices[1].x >> t.vertices[1].y;

    cout << "Ingrese las coordenadas del tercer vértice" << endl;
    cin >> t.vertices[2].x >> t.vertices[2].y;

    cout << "v1: " << t.vertices[0].x << "   " << t.vertices[0].y << endl;
    cout << "v2: " << t.vertices[1].x << "   " << t.vertices[1].y << endl;
    cout << "v3: " << t.vertices[2].x << "   " << t.vertices[2].y << endl;

    cout << "LADO 1: " << t.L1.x << "   " << t.L1.y << endl;
    cout << "LADO 2: " << t.L2.x << "   " << t.L2.y << endl;
    cout << "LADO 3: " << t.L3.x << "   " << t.L3.y << endl;
    cout << "MODULOS:   " << t.L1.modulo() << "  " << t.L2.modulo() << "    " << t.L3.modulo() << endl;

    cout << "Estos vértices corresponden a un triángulo ";

    switch (t.clasificaPorLado()){
        case 0:
            cout << "equilatero ";
            break;
        case 1:
            cout << "isoceles ";
            break;
        case 2:
            cout << "escaleno ";
            break;
    }

    switch (t.clasificaPorAngulo()){
        case 0:
            cout << "y acutángulo" << endl;;
            break;
        case 1:
            cout << "y rectángulo" << endl;
            break;
        case 2:
            cout << "y obtusángulo" << endl;
            break;
    }

    return 0;
}



//    ClaseAngulo clasificaPorAngulo() {
//        //el signo del producto escalar es el del coseno del ángulo entre 2 vectores
//        //por lo tanto, si obtengo un p.e. nulo, será rectángulo
//        //si obtengo alguno negativo, será obtusángulo
//        //sino, será acutángulo
//
//        cout << "clasificaPorAngulo // Productos escalares: ";
//        cout << lados[0]*lados[1] << "   " << lados[0]*lados[2] << "  " << lados[1]*lados[2] << endl;
//        if (lados[0]*lados[1] < 0 || lados[0]*lados[2] < 0 || lados[1]*lados[2] < 0)
//            return OBTUSANGULO;
//        else{
//            if (lados[0]*lados[1] == 0 || lados[0]*lados[2] == 0 || lados[1]*lados[2] == 0){
//                cout << "clasificaPorAngulo: rectangulo"<<endl;
//                return RECTANGULO;
//            }
//            else
//                return ACUTANGULO;
//        }
//    }
