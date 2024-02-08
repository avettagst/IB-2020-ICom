#include "icom_helpers.h"

/*PREGUNTAR POR CONSTRUCTOR SIN PARAMETROS Y POR COUT SIN FOR

MyString(const char *);
MyString(const MyString &s);
MyString();

*/

struct MyString{
  private:
    size_t sz;
    char *str;

  public:
    MyString(){ //sin parametros, lo inicializo vacío

    }

    MyString(const char *str){

    }

    MyString (const MyString &){


    }

    MyString &operator=(const MyString &){


    }

    ~MyString(){

    }

    size_t sizestr() const{
        return sz;
    }

    char &operator[] (int id){ //se puede modificar
        return str[id];
    }

    char operator[] (int id) const{ //se puede usar en objetos const
        return str[id];
    }

    MyString operator+(const MyString &){

    }
};

int main(){
//    MyString s, s2("hola mundo");
//    MyString s3(s2);
//    MyString s4 = s2 + s3;
//
//    cout << s2.s << '\n' << s3.s << '\n' << s4.s << '\n';
//
//    s3.s[2] = '$';
//
//    char c = s3.s[0];
//
//    cout << c << '\n';
//
//    cout << s3.s;

    return 0;
}
