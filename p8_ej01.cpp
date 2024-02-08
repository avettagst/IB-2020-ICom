#include "icom_helpers.h"

struct terna{
    int x, y, value;
};

struct complejo{
    double re, im;
};

int main(){
    char c[2], *pc = c, *pc1 = pc + 1;
    int i[2], *pi = i, *pi1 = i + 1;
    float f[2], *pf = f, *pf1 = f + 1;
    double d[2], *pd = d, * pd1 = d + 1;
    terna udt_t[2], *ptr_t = udt_t, *ptr_t1 = udt_t + 1;
    complejo udt_c[2], *ptr_c = udt_c, *ptr_c1 = udt_c + 1;


    cout << "CHAR" << endl;
    cout << "0: " << (void*)pc << "\t" << "1: " << (void*)pc1 << endl;
    cout << "size: " << sizeof(char) << endl;

    cout << "\n\nINT" << endl;
    cout << "0: " << (void*)pi << "\t" << "1: " << (void*)pi1 << endl;
    cout << "size: " << sizeof(int) << endl;

    cout << "\n\nFLOAT" << endl;
    cout << "0: " << (void*)pf << "\t" << "1: " << (void*)pf1 << endl;
    cout << "size: " << sizeof(float) << endl;

    cout << "\n\nDOUBLE" << endl;
    cout << "0: " << (void*)pd << "\t" << "1: " << (void*)pd1 << endl;
    cout << "size: " << sizeof(double) << endl;

    //size 12 y diferencia 8?
    cout << "\n\nTERNA" << endl;
    cout << "0: " << (void*)ptr_t << "\t" << "1: " << (void*)ptr_t1 << endl;
    cout << "size: " << sizeof(terna) << endl;

    //size 16 y diferencia 40?
    cout << "\n\nCOMPLEJO" << endl;
    cout << "0: " << (void*)ptr_c << "\t" << "1: " << (void*)ptr_c1 << endl;
    cout << "size: " << sizeof(complejo) << endl;

    return 0;
}
