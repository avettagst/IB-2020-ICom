#include "icom_helpers.h"

int main(){
    string s;

    cout << "Ingrese una palabra en minúsculas: ";
    cin >> s;

    int nv = 0, i = 1; //nv es el acumulador, i determina la posición

    for (char c: s){
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            nv += int(c)*4*i;
        else
            nv += int(c)*2*i;
        i++;
    }

    cout << "El número verificador de \"" << s << "\" es " << nv;

    return 0;
}
