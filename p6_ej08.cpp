#include "icom_helpers.h"

int StrStr(const string &s1, const string &s2){
    size_t pos = s1.find(s2);

    if (pos == string::npos)
        return -1;

    return pos;
}

int main(){
    string s1 = "hoo0ola", s2 = "ola";

    cout << s1.find(s2) << endl;    //mi funcion es igual al metodo find pero
    cout << StrStr(s1, s2) << endl; //en casos negativos devuelve -1 en vez de npos
    cout << string::npos << endl;

    return 0;
}
