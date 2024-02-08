#include "icom_helpers.h"

int main(){
    char c;

    while ((c = cin.get()) != EOF){
        if (c>=97 && c<=122)
            cout.put(c-32);
        else
            cout.put(c);
    }

    return 0;
}
