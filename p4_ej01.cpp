#include "icom_helpers.h"

int main(){
    cout << "Ingrese cantidad de intervalos" << endl;
    int N;
    cin >> N;

    cout << "Ingrese cantidad de elementos" << endl;
    int M;
    cin >> M;

    int hist[N] = {0};

    //PARA TRABAJAR CON vector, REEMPLAZAR hist por vhist
//    vector<int> vhist {0};
//    vhist.resize(N);

    srand(time(0));

    for (int i = 0; i < M; i++){
        int m = rand();
        for (int j = 0; j < N; j++){
            if (m >= j*RAND_MAX/N && m < (j+1)*RAND_MAX/N)
                hist[j]++;
        }
    }

    for (int j = 0; j < N; j++){
        cout << "Intervalo " << j+1 << ": " << hist[j] << endl;
    }



return 0;
}
