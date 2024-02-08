#include "icom_helpers.h"

void CapitalizeFirst(std::string &phrase){
    phrase[0] = toupper(phrase[0]);
    for (int i = 0; i < phrase.size(); i++){
        if (phrase[i] == ' ')
            phrase[i+1] = toupper(phrase[i+1]);
    }
}


int main(){
    cout << "Ingrese un string:" << endl;
    string s;
    getline(cin,s);

    CapitalizeFirst(s);

    cout << s << endl;

    return 0;
}
