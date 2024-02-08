#include <iostream>

using namespace std;

int main(){
    float x, p;
    cout << "Ingrese un valor de x: " << endl;
    cin >> x;
    p = 3*x*x*x-5*x*x+6;
    cout << "3 x^3 - 5 x^2 + 6 = " << p << endl;
    return 0;
}
