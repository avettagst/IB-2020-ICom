#include "icom_helpers.h"

const int pesos1[7] = {7, 1, 3, 9, 7, 1, 3};
const int pesos2[13] = {3, 9, 7, 1, 3, 9, 7, 1, 3, 9, 7, 1, 3};

int cbu_check(const char cbu[]){
    int acum1 = 0, acum2 = 0;

    for (int i = 0; i < 7; i++){
        acum1 += pesos1[i]*(cbu[i] - '0');
    }

    int dif1 = 10 - acum1 % 10;

    if (dif1 != cbu[7] - '0')
        return -1;

    for (int j = 0; j < 13; j++){
        acum2 += pesos2[j]*(cbu[j+8] - '0');
    }

    int dif2 = 10 - acum2 % 10;

    if (dif2 != cbu[21] - '0')
        return -2;

    return 1;
}

//hacer entrada estandar y verificar

int main(){
    char cbu[] = "2850590940090418135201";
    cout << cbu_check (cbu);
    return 0;
}
