#include "icom_helpers.h"

/*
Primero se crea la instancia en A, luego la instancia en B. Al "throwear", se destruyen las instancias creadas en
A y B (al salir del ámbito de ambas funciones), se ejecuta el catch de tipo X (mi UDT), tomando una copia de la
variable lanzada desde B (esto lo verifiqué con el constructor de copia comentado en el struct).
Por último, se destruye esta copia y termina el programa

Veo que, al throwear una variable, no se ejecuta ninguna de las líneas siguientes, sino que salta directamente al
catch correspondiente

Se prueban secuencias throw/catch para tres tipos de variables distintas (X, int y char)
En caso de lanzar una variable a la cual no corresponde ningun catch (por ejemplo, char c), la consola devuelve
"terminate called after throwing an instance of 'char'"

Al lanzar un valor de número flotante (línea 47, comentada) y no haber un catch específico para este tipo de datos,
se ejecuta el bloque catch(...), el cual recibe cualquier cosa que no tenga un tratamiento específico en las líneas
"superiores"
*/

struct X{
    X(){
        cout << "Construyendo un X en " << this << endl;
    }

    ~X(){
        cout << "Destruyendo el X de " << this << endl;
    }

//    X (const X &a){
//        cout << "Copiando el X de " << &a << " en " << this << endl;
//    }
};

void funB(){
    X enB;
    int n;

    throw enB;

    cout << "esto no se imprime\n";
}

void funA(){
    X enA;
    int n = 10;
    char c = 'a';

    //throw 0.8; con este throw pruebo el catch(...)
    throw enA; //en caso de que se ejecute esta linea, nunca se llamara a los otros throw ni a la funB
    throw n; //si se quieren probar estos throw, se debe comentar o borrar el throw en A
    throw c;

    funB();
}

int main(){
    try{
        funA();
    } catch(X &exc){
        cout << "Excepcion tipo X ~ " << &exc << endl;
    }
    catch (int a){
        cout << "Excepcion entera, valor: " << a << endl;
    }
    catch (...){
        cout << "Catch ALL." << endl;
    }
//    catch (char c){
//        cout << "Excepcion. Caracter: " << c << endl;
//    }
    //dejo el catch (char) comentado, así fue como probé lo del 'terminate' para variables no "catcheadas"

    return 0;
}

