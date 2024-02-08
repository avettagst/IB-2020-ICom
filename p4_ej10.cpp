#include "icom_helpers.h"

void IngresaRand (int Vector[], int numElementos){
    for (int i=0; i < numElementos; i++){
        Vector[i] = rand() % 365;
    }
}

void ImprimeTabla (double Vector[], int NumElementos){
    for (int i = 0; i < NumElementos; i++){
        cout << (i+1)*10 << " personas:    " << Vector[i] << endl;
    }

}

bool MismoDia (int Vector[], int numElementos){
    for (int i = 0; i < numElementos - 1; i++){
        for (int j = i+1; j < numElementos; j++){
                if (Vector[i] == Vector[j] && i != j)
                    return true;
        }
    }
    return false;
}



int main(){
    const int grupos = 6, pruebas = 1000;
    int fechas[70]; //uso solo los primeros 10, 20,...,60 elementos, según corresponda
    double tabla[grupos];

    int acum, cant;

    srand(time(0));

    for (int  i = 0; i < grupos; i++){
        acum = 0;
        cant = (i+1)*10;
        for (int j=0; j < pruebas; j++){
            IngresaRand(fechas, cant);
            if (MismoDia(fechas, cant))
                acum++;
        }
        tabla[i] = (double) acum / pruebas;
    }

    ImprimeTabla(tabla, grupos);

    return 0;
}
