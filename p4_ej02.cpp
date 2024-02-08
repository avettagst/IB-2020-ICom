#include "icom_helpers.h"

void ImprimeVector (double Vector[], int NumElementos){
    for (int i = 0; i < NumElementos; i++){
        cout << Vector[i] << endl;
    }
}


int main(){
    cout << "Tamaño del vector: " << endl;
    int N;
    cin >> N;

    double vec[N] = {0};
    ImprimeVector(vec,N);


    return 0;
}
