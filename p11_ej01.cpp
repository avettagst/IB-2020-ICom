#include "icom_helpers.h"
/*
La copia default me sirve, ya que se copiarán los vectores de ambos Polígonos
Además, la copia miembro a miembro de Punto2D tambien es conveniente para este problema
*/
struct Punto2D {
    double X;
    double Y;

    Punto2D operator-(Punto2D p){
        Punto2D resultado = {X - p.X, Y - p.Y};
        return resultado;
    }

    double modulo(){
        return X*X + Y*Y;
    }
};
struct Poligono {
    public:
        // construye un poligono cerrado con los vertices dados
        Poligono(const vector<Punto2D> &vertices_){
            vertices.resize(vertices_.size());
            for (int i = 0; i < (int)vertices_.size(); i++)
                vertices.at(i) = vertices_.at(i);
        }

        // retorna el perimetro del poligono
        double perimetro(){
            Punto2D lado;
            double p = 0;
            for (int i = 0; i < (int)vertices.size(); i++){
                lado = vertices[i+1] - vertices[i];
                p += lado.modulo();
            }

            lado = vertices[0] - vertices[vertices.size()];
            p += lado.modulo();

            return p;
        }
        // retorna el area del poligono
        double area();
    private:
        vector<Punto2D> vertices;
};



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
