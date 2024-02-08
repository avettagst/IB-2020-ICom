#include "icom_helpers.h"

int main(){
    int m,n;

    cout << "Ingrese dos numeros enteros: " << endl;
    cin >> m >> n;

    for (int i = 0; i <= m; i++){
        for (int j=0; j <= n; j++){
            cout << i << j << " ";
        }
        cout << endl;
    }
    return 0;
}
