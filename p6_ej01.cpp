#include "icom_helpers.h"

bool esDivisiblePor7 (int nro){
    int unidad = (nro % 10)*2;
    int rest = nro / 10;
    if (abs(rest - unidad) < 10)
        if (abs(rest-unidad)==7 || rest == unidad)
            return true;
        else
            return false;
    else
        return esDivisiblePor7(rest-unidad);
}

int main(){
    for (int i = 0; i < 100; i++)
        if (esDivisiblePor7(i))
            cout << i << endl;

    return 0;
}
