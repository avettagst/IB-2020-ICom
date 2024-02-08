#include "icom_helpers.h"

struct data{
    void metodo(){
        cout << "funcion miembro" << endl;
    }

    void otro_metodo(){
        cout << "otra funcion miembro" << endl;
    }

    int metodonum(int x){
        return 3;
    }

};

int main(){
    data x;
    cout << "lugar de memoria: " << &x << endl;
    cout << "size: " << sizeof(data) << endl;
    return 0;
}
