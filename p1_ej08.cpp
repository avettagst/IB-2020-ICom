#include <iostream>

using namespace std;

int main()
{
    cout << "\nHello world!" << endl;   //salto de l�nea
    cout << "\tHello world!" << endl;   //tabulado
    cout << "Hello wo\brld!\b" << endl; //es un backspace: vuelve un lugar atr�s para imprimir. por eso queda wrld pero
                                        //no se elimina el '!', porque no se imprime nada encima
    cout << "Hello wo\rrld!" << endl; // es un retorno de carro: lo que est� a su derecha se escribe en el primer espacio
                                        // de la linea, sobreescribiendose sobre los ya existentes
    return 0;
}
