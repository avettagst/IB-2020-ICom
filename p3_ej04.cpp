#include "icom_helpers.h"

using namespace std;

int main(){
    int c = 0, p = 0, l = 0;
    char a;

    while ((a = cin.get()) != EOF){
        c++; //cuento todo: tabulaciones, letras, espacios y enters
        switch (a){
            case ' ':
                p++;
                break;
            case '\n':
                p++;
                l++;
                break;
            case '\t':
                p++;
                break;
            default:
                break;
        }
    }

    cout << "Caracteres: " << c << endl;
    cout << "Palabras: " << p << endl;
    cout << "Líneas: " << l << endl;

    return 0;
}

