#include "icom_helpers.h"

int CompareStrings(const char*, const char*);

int main(){

    char* str1 = new char[20];
    char* str2 = new char[20];

    cout << (void*)str1 << '\t' << (void*)str2 << '\n';

    str1 = "hola";   //no funciona porque al char[] le asigno un string. se rompe todo
    str2 = "holistico";

    cout << (void*)str1 << '\t' << (void*)str2 << '\n';


    cout << str1 << '\n' << str2 << '\n';
    cout << CompareStrings(str1, str2);

    cout << "\nantes del delete\n";
    delete [] str1;
    cout << "\nentre deletes\n";
    delete [] str2;
    cout << "\ndespues del delete\n";
    return 0;
}

int CompareStrings(const char *str1, const char *str2){
    int i = 0;

    while (str1[i] && str1[i] == str2[i])
        i++;

    return str1[i] - str2[i];
}

