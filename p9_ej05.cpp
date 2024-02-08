#include "icom_helpers.h"

class SimMatrix {
    public:
        SimMatrix(size_t dim_){ // define una matriz de dim x dim
            dim = dim_;
            values = new vector<double> [dim];
            for (size_t i = 0; i < dim; i++)
                values[i].resize(i+1);
        }

        SimMatrix(const SimMatrix &sm){ // copy-constructor
            dim = sm.getDim();
            values = new vector<double> [dim];
            for (size_t i = 0; i < dim; i++)
                values[i].resize(i+1);

            for (size_t i = 0; i < dim; i++){
                for (size_t j = 0; j <= i; j++)
                values[i].at(j) = sm.getElement(i, j);
            }
        }

        ~SimMatrix(){
            delete[] values;
        }

        void setElement(int i, int j, double val){
            if (i >= getDim() || j >= getDim())
                cout << "Indices incorrectos. Elemento no seteado\n";
            else{
                if (j>i)
                    values[j].at(i) = val;
                else
                    values[i].at(j) = val;
            }
        }

        double getElement(int i, int j) const{\
            return values[i].at(j);
        }

        size_t getDim() const{
            return dim;
        }

        void mostrar(){
            for (size_t i = 0; i < getDim(); i++){
                for (size_t j = 0; j < getDim(); j++){
                    if (j<=i)
                        cout << getElement(i, j) << " ";
                    else
                        cout << getElement(j, i) << " ";
                }
                cout << '\n';
            }
        }

    private:
        vector<double> *values;
        size_t dim;
};

SimMatrix *sumaSimMatrix(const SimMatrix &m1, const SimMatrix &m2){ //usar solo si m1 y m2 tienen la misma dimension
    size_t dim = m1.getDim();
    SimMatrix *mat_suma = new SimMatrix(dim);
    double suma;

    for (int i = 0; i < dim; i++){
        for (int j = 0; j <= i ; j++){
            suma = m1.getElement(i,j) + m2.getElement(i,j);
            mat_suma->setElement(i,j,suma);
        }
    }

    return mat_suma;
}

int main(){
    double val;
    size_t dim = 3;
    SimMatrix sm(dim);
    SimMatrix sm2(dim);

    for (int i = 0; i < sm.getDim(); i++){
        for (int j = 0; j <= i ; j++){
            cout << "cargue elemento (" << i << ", " << j << "): ";
            cin >> val;
            cout << '\n';
            sm.setElement(i, j, val);
        }
    }

    for (int i = 0; i < sm2.getDim(); i++){
        for (int j = 0; j <= i ; j++){
            cout << "cargue elemento (" << i << ", " << j << "): ";
            cin >> val;
            cout << '\n';
            sm2.setElement(i, j, val);
        }
    }

    SimMatrix *suma(sumaSimMatrix(sm, sm2));
    suma->mostrar();
    return 0;
}
