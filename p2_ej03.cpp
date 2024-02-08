#include <iomanip> //para usar setprecision()
#include "icom_helpers.h"


using namespace std;

int main(){
    unsigned int lim_sup;
    double pi_d4 = 0;

    cout << "Ingrese cantidad de términos de la serie: " << endl;
    cin >> lim_sup;

    for (int i = 0; i <= lim_sup; i++){
        pi_d4 += pow(-1,i) / (2*i + 1);
    }

    cout << "Pi es aproximadamente " << std::setprecision(10) <<pi_d4*4;
}
