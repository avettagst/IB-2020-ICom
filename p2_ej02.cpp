#include <iostream>

using namespace std;

int main(){
    int sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;

    for (int i=1; i<=1000; i++){
        if (i%2==0)
            sum2+=i;
        if (i%3==0)
            sum3+=i;
        if (i%4==0)
            sum4+=i;
        if (i%5==0)
            sum5+=i;
    }

    cout << "La suma de todos los múltiplos de 2 entre 1 y 1000 es: " << sum2 << endl;
    cout << "La suma de todos los múltiplos de 3 entre 1 y 1000 es: " << sum3 << endl;
    cout << "La suma de todos los múltiplos de 4 entre 1 y 1000 es: " << sum4 << endl;
    cout << "La suma de todos los múltiplos de 5 entre 1 y 1000 es: " << sum5 << endl;
}
