#include <iostream>

using namespace std;

int suma (int n){
    int s = 0;

    for (int i=1; i<=n; i++)
        s+=i;

    return s;
}

int main(){
    int N;

    cout << "Ingrese N: ";
    cin >> N;

    cout << "\nLa suma de los primeros " << N << " enteros naturales es " << suma(N) <<endl;

    return 0;
}
