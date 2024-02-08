#include "icom_helpers.h"

class Noiserer {
    public:

        Noiserer (double minV_, double maxV_){
            minV = minV_;
            maxV = maxV_;
        }

        double operator()(double v){
            double ancho = maxV - minV;
            double r = rand()*ancho/RAND_MAX + minV; //primero reescaleo y despues desplazo
            return v + r;
        }

    private:
        double minV, maxV;
};

int main(){
    srand(time(0));
    double vmin;
    double vmax;

    do{
        cout << "Volumen minimo: ";
        cin >> vmin;

        cout << "Volumen maximo: ";
        cin >> vmax;
    } while (vmin > vmax);

    Noiserer ruido(vmin, vmax);

    vector<double> in = {5.08, 6.39, 7.9, 15.23, 12.4, 6.57};
    vector<double> out(in.size());

    cout << "Vector IN: ";
    for (auto c : in)
        cout << c << "  ";

    transform(in.begin(), in.end(), out.begin(), ruido);

    cout << "\nVector OUT: ";
    for (auto d : out)
        cout << d << "  ";

    return 0;
}
