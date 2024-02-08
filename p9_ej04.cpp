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

        double getElement(int i, int j) const{
            return values[i].at(j);
        }

        int getDim() const{
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

int main(){
    double val;
    size_t dim = 4;
    SimMatrix sm(dim);

    for (int i = 0; i < sm.getDim(); i++){
        for (int j = 0; j <= i ; j++){
            cout << "cargue elemento (" << i << ", " << j << "): ";
            cin >> val;
            cout << '\n';
            sm.setElement(i, j, val);
        }
    }

    sm.mostrar();
    return 0;
}
