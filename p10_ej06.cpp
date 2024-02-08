#include "icom_helpers.h"

class Stack {
  public:
    Stack() {};

    Stack (char c[]){
        for (int i = 0; c[i] != 0; i++)
            pila.push_back(c[i]);
    }

    void push(char c){ // coloca un nuevo carácter en la pila
        pila.push_back(c);
    }

    char pop(){ // retira el elemento al tope del stacks
        size_t s = pila.size();
        char r = pila[s-1];
        pila.resize(s-1);
        return r;
    }
    bool isEmpty(){ // retorna true/false indicando si el stack está vacío
        if (pila.size() == 0)
            return true;
        return false;
    }

  private:
    vector<char> pila;
};



int main(){
    //algunas pruebas para verificar el correcto funcionamiento
    Stack st("123456789z");
    Stack st2;

    if (st2.isEmpty())
        cout << "st2 esta vacio\n";

    st2.push('%');
    st2.push('9');
    cout << st2.pop() << '\n';
    cout << st2.pop() << "\n\n";

    cout << st.pop() << '\n';
    cout << st.pop() << '\n';
    st.push('f');
    cout << st.pop() << '\n';

    //st.pila.at(2);
    //Esta linea da error al compilar porque pila es un miembro privado de Stack, por lo que no se puede acceder (como se pide)

    if (!st.isEmpty())
        cout << "st no esta vacio\n";

    return 0;
}
