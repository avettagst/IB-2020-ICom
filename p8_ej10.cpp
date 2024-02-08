#include "icom_helpers.h"

typedef void(*fun)();

void f1(){
    cout << "\nsale f111\n";
}

void f2(){
    cout << "\nsale f222\n";
}

void f3(){
    cout << "\nsale f333\n";
}

void f4(){
    cout << "\nsale f444\n";
}

void f5(){
    cout << "\nsale f555\n";
}

int main(){

    fun f_1 = f1;
    fun f_2 = f2;
    fun f_3 = f3;
    fun f_4 = f4;
    fun f_5 = f5;

    fun arr[5] = {f_1, f_2, f_3, f_4, f_5};

    srand(time(0));

    for (int i = 0; i<20; i++){
        int X = rand() % 5;
        arr[X]();
    }

    return 0;
}
