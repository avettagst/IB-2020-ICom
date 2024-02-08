#include "icom_helpers.h"


char digito (int dig){
    static const char *digitos = "0123456789ABCDEF";
    assert(dig>=0 && dig<16);
    return digitos[dig];
}

string dar_vuelta (string s){
    int inicio = 0, fin = s.size() - 1;
    while (inicio < fin){
        char aux = s[inicio];
        s[inicio] = s[fin];
        s [fin] = aux;

        ++inicio;
        --fin;
    }
    return s;

}

string cambio_base (int valor, int base){
    string resultado;
    while (valor >= base) {
        resultado += digito(valor % base);
        valor /= base;
    }
    resultado += digito(valor);


    return dar_vuelta(resultado);
}

int main(){
    int valor, base;
    cout << "Ingrese valor: " << endl;
    cin >> valor;
    cout << "Ingrese base (hasta 16): " << endl;
    cin >> base;
    assert (base >= 0 && base <=16);
    cout << "El valor " << valor << " en base " << base << " se representa " << cambio_base(valor, base);

    return 0;
}
