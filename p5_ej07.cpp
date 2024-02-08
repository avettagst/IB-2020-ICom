#include "icom_helpers.h"

struct T {

    T() {
        cout << "Construyendo " << this << endl;
    }

    ~T(){
        cout << "Destruyendo " << this << endl;
    }
};

int main(){
    vector<T> v(10);

    cout << "\nResizeo a 3:" << endl;
    v.resize(3);

    cout << "\nAhora resizeo a 10:" << endl;
    v.resize(10);

    cout << "\nFinaliza el programa y se destruye todo:" << endl;




    return 0;
}
