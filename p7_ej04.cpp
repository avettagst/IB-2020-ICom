#include "icom_helpers.h"

struct data{
    private: //sin esta linea, funciona
        data(){
        }
};

class data2{
    //public: //si agrego esta linea, funciona
        data2(){
        }

};
int main(){
    data x;
    data2 y;
    return 0;
}
