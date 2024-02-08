#include "icom_helpers.h"

int StrStr(char s1[], char s2[]){
    int i = 0, j = 1, aux;

    while (s1[i] != 0){ //recorro s1
        if (s1[i] == s2[0]){
            aux = i;
            //empiezo a recorrer s2
            while(s2[j] != 0){
                if (s1[aux + 1] != s2[j]){ //si alguna letra no coincide
                    j = 1;                 //reinicio j
                    break;                 //y salgo del while de s2
                }
                aux ++; j++;
                if (s2[j] == 0)
                    return i; //si llegue al final de s2 sin entrar al break, lo logré
            }
        }

        i++; //voy avanzando en s1
    }

    return -1;

}

int main(){
    char s1[] = "Hooooolaaaa", s2[] = "ola";
    cout << StrStr(s1, s2) << endl;
    return 0;
}
