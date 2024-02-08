#include "icom_helpers.h"

class Monedero {
  private:

    struct Denominacion {
        int valor; // valor de la denominación en centavos
        int cantidad; // cantidad de billetes/moneda necesarios

        bool operator<(const Denominacion &d) const {
            return valor < d.valor;
        }
    };

    vector<Denominacion> monedas; // denominaciones a utilizar
  public:
    Monedero () {} //para crear uno vacío y probar la asignacion copia

    // construye un monedero con las distintas denominaciones
    // a manejar expresadas en centavos. Por ejemplo si se van a manejar
    // las siguientes denominaciones: $0.50, $1, $2, $10, $50, $100 y $500
    // podría construirse con el vector
    // {50, 100, 200, 2000, 5000, 10000, 50000
    Monedero(const vector<int> &valorMonedas){
        monedas.resize(valorMonedas.size());
        for (int i = 0; i < (int)valorMonedas.size(); i++){
            monedas[i].valor = valorMonedas[i]; //valor en centavos
            monedas[i].cantidad = 0;
        }
        sort(monedas.rbegin(), monedas.rend()); //ordeno de mayor a menor
    }


    // Agrega un sueldo a ser distribuido en las distintas
    // denominaciones, se debe minimizar la cantidad de
    // billetes/monedas a entregar
    void agregaSueldo(int montoSueldo){ //monto en centavos
        for (int i = 0; i < (int)monedas.size(); i++){
            monedas[i].cantidad += montoSueldo / monedas[i].valor;
            montoSueldo = montoSueldo % monedas[i].valor;
        }
    }


    // Retorna la cantidad de billetes/monedas necesarios de la
    // denominacion de valor 'denominacion'
    int cantidadValor(int denominacion){
        for (int i = 0; i < (int)monedas.size(); i++){
            if (monedas[i].valor == denominacion)
                return monedas[i].cantidad;
        }

        return -1; //si se ingresa una denominacion invalida
    }
};

int main(){
    vector<int> billetes = {50, 100, 200, 2000, 5000, 10000, 50000, 100000};

    Monedero m(billetes);
    Monedero m2(m);
    Monedero m3;
    m3 = m2;            //el programa funciona con m, m2 y m3, por lo que no hace falta
                        //constructor copia ni operador =
                        //esto se debe a que no se trabaja con punteros y las copias término a término sirven

    int sueldo;
    cout << "Cuando termine, ingrese -1\n";
    do{
        cout << "Ingrese un sueldo en pesos: ";
        cin >> sueldo;
        if(sueldo >= 0)
            m3.agregaSueldo(sueldo*100); //lo paso en centavos

    }while(sueldo != -1);

    for (int d : billetes){
        cout << "Denominacion: " << d/100.0 << '\n';
        cout << "Cantidad: " << m3.cantidadValor(d) << "\n\n";
    }

    return 0;
}
