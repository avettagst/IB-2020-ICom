#include "icom_helpers.h"

int main(){
    char c;
    int ban = 0;

    while ((c = cin.get()) != EOF){
            switch(c){
                case '(':
                    ban++;
                    break;
                case ')':
                    ban--;
                    continue; //para no mostrar el ')' con el if
                default:
                    break;
            }

            //cuando se "igualan" la cantidad de '(' y ')' vuelvo a mostrar los caracteres ingresados
            if (ban == 0){
                cout.put(c);
            }
    }

    return 0;
}
