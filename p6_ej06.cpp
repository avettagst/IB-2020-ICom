#include "icom_helpers.h"

void Replace(char s[], char nuevo, char viejo){
    int i = 0;
    while(s[i] != 0){
        if (s[i] == viejo)
            s[i] = nuevo;
        i++; //no lo puedo hacer en el if (copia mal) ni en la asignacion (while infinito)
    }
}

int main(){
    char s[] = "hola maldita perraaa", vi = 'a', nu = '*';
    Replace(s, nu, vi);

    int i = 0;
    while(s[i] != 0)
        cout << s[i++];
    cout << endl;
    return 0;
}
