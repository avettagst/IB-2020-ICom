#include "icom_helpers.h"

int cuantasFormas (int n){
    if (n == 0 || n == 1 || n == 2)
        return n;

    return cuantasFormas(n-1) + cuantasFormas(n-2);
}

int main(){
    for (int i = 0; i < 7; i++)
        cout << cuantasFormas(i) << endl;
    return 0;
}
