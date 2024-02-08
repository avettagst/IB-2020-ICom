#include "icom_helpers.h"


int MCD (int a, int b){

    if (a == 0 || a == b)     //soluciones triviales
        return b;
    if (b == 0)
        return a;

    if (a > b)
        return MCD (b, a%b);
    else
        return MCD (a, b%a);
}

int MCM (int a, int b){
    if (a > 0 && b > 0)
        return a*b / MCD(a,b);
    else
        return -1;
}


int main(){
    //probamos varios valores
    for (int i = 0; i < 15; i+=2)
        for (int j = 0; j < 50; j += 3){
        cout <<"MCD(" << i <<", " << j <<") " << MCD(i,j) << endl;
        cout <<"MCM(" << i <<", " << j <<") " << MCM(i,j) << endl;
        cout << "\n\n";
        }

    return 0;
}
