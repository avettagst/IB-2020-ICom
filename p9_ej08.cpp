#include "icom_helpers.h"

class Polinomio {

    public:
    // construye un polinomio con los coeficientes y grado dados que
    // representa al polinomio:
    // coefs[0] + coefs[1]*x + coefs[2]*x^2 + ... + coefs[n]*x^n
        Polinomio(const double *c, int n){
            grado = n;
            coefs = new double [grado+1];


            for (int i = 0; i <= grado; i++)
                coefs[i] = c[i];
        }

        Polinomio(const Polinomio &p){
            grado = p.grado;
            coefs = new double [grado+1];

            for (int i = 0; i <= grado; i++)
                coefs[i] = p.coefs[i];
        }

        ~Polinomio(){
            delete [] coefs;
        }

        Polinomio &operator=(const Polinomio &p){
            grado = p.grado;

            for (int i = 0; i <= grado; i++)
                coefs[i] = p.coefs[i];

            return *this;
        }

        Polinomio operator+(const Polinomio &p){
            int g = max(grado, p.grado);
            double c[g+1] = {0};

            for (int i = 0; i <= grado; i++)
                c[i] += coefs[i];

            for (int i = 0; i <= p.grado; i++)
                c[i] += p.coefs[i];

            return Polinomio(c, g);
        }

        Polinomio operator*(const Polinomio &p){
            int g = grado + p.grado;
            double c[g+1] = {0};

            for (int i = 0; i <= grado; i++){
                for (int j = 0; j <= p.grado; j++)
                    c[i+j] += coefs[i] * p.coefs[j];
            }

            return Polinomio(c, g);
        }

        double evaluate(double x){
            double p = 0;
            for (int i = 0; i <= grado; i++)
                p += pow(x,i)*coefs[i];

            return p;
        }

        Polinomio derivate(){ // crea y retorna el polinomio derivado
            int g = grado - 1;
            double c[g] = {0};

            for (int i = 1; i <= grado; i++)
                c[i-1] = i * coefs[i];

            return Polinomio(c, g);
        }

        Polinomio integrate(double c){
            int g = grado + 1;
            double cs[g] = {c};

            for (int i = 0; i <= grado; i++)
                cs[i+1] = coefs[i] / (i+1);

            return Polinomio(cs, g);
        }

    void mostrar(){
        for (int i = grado; i > 0; i--){
            if (coefs[i] != 0){
                if (coefs[i] != 1)
                    cout << coefs[i] << " * x^" << i << "  +  ";
                else
                    cout << "x^" << i << " + ";
            }
        }
        cout << coefs[0] << '\n';
    }

    private:
        double *coefs;
        int grado;
};

int main(){
//  double c1[3] = {1,1,1}, c2[2] = {5,1}; //distintos ejemplos para probar
    double c1[6] = {10,8,5,-2,11,0.5}, c2[2] = {0,1};
    Polinomio p1 (c1, 5);   //funciona el primer constructor
    Polinomio p2 (c2, 1);
    Polinomio p3(p1);       //funciona el segundo constructor
    Polinomio p4 (p1*p2);

    //p3 = p1 + p2;           //funciona el operador =
    p2 = p1;

    cout << "p1 = "; p1.mostrar();
    cout << "\np2 = "; p2.mostrar();
    cout << "\np1 + p2 = "; p3.mostrar();
    cout << "\np1 * p2 = ";  p4.mostrar();
    cout << "\nderivada de p1: "; (p1.derivate()).mostrar();
    cout << "\nintegral de p1 (c=5): "; (p1.integrate(5)).mostrar();
    cout << "\np1(x = 5) = " << p1.evaluate(5);

    return 0;
}
