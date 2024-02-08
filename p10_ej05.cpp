#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;


// representa la base de una jerarquía de expresiones
class Exp {
    public:
        virtual ~Exp() {}

        // imprime la expresión en formato algebraico
        virtual void print() = 0;

        // evalua la expresion especializada con var = X
        virtual double evaluate(double X) = 0;

        // calcula y retorna la expresión derivada
        virtual Exp *derivate() = 0;

        // clona la expresion
        virtual Exp *clone() = 0;

};

// representa expresiones constantes
class ConstExp : public Exp {    // constant
    public:
        ConstExp(double value_)
            : value(value_) { }

        void print()              { /* ToDo */
            cout << value;
        }
        double evaluate(double X) { /* ToDo */
            return value;
        }
        Exp *derivate()    { /* ToDo */
            ConstExp *der = new ConstExp(0);
            return der;
        }
        Exp *clone()       { /* ToDo */
            ConstExp *copia = new ConstExp(value);
            return copia;
        }

    private:
        double value;
};

// representa expresiones binarias (+, -, *, /)
class BinaryExp : public Exp {    // PLUS, MINUS, MULT, DIV
    public:
        BinaryExp(Exp *e1_, Exp *e2_)
            : e1(e1_), e2(e2_) { }
        ~BinaryExp() {
            delete e1;
            delete e2;
        }

    protected:
        Exp *e1;
        Exp *e2;
};

// representa expresiones unarias (sin, cos, tan)
class UnaryExp : public Exp {    // SIN, COS, TAN
    public:
        UnaryExp(Exp *e1_)
            : e1(e1_) { }
        ~UnaryExp() {
            delete e1;
        }

    protected:
        Exp *e1;
};

// representa expresiones variables ( X )
class VariableExp : public Exp {    // VARIABLE
    public:
        void print()              { /* ToDo */
            cout << "X";
        }
        double evaluate(double X) { /* ToDo */
            return X;
        }
        Exp *derivate()    { /* ToDo */
            ConstExp *der = new ConstExp(1);
            return der;
        }
        Exp *clone()       { /* ToDo */
            VariableExp *copia = new VariableExp();
            return copia;
        }
};

class PlusExp : public BinaryExp {
    public:
        PlusExp(Exp *e1, Exp *e2) : BinaryExp(e1, e2){}
        void print()              { /* ToDo */
            cout << "(";
            e1->print();
            cout << " + ";
            e2->print();
            cout << ")";
        };
        double evaluate(double X) { /* ToDo */
            double res = e1->evaluate(X) + e2->evaluate(X);
            return res;
        }
        Exp *derivate()    { /* ToDo */
            PlusExp *der = new PlusExp(e1->derivate(), e2->derivate());
            return der;
        }
        Exp *clone()       { /* ToDo */
            PlusExp *copia = new PlusExp(e1->clone(), e2->clone()); //si no los clono, *copia apuntará a las mismas expresiones
            return copia;                                          //e1 y e2 que el original (SE PISAN)
        }
};

class MinusExp : public BinaryExp {
    public:
        MinusExp(Exp *e1, Exp *e2) : BinaryExp(e1, e2){}
        void print()              { /* ToDo */
            cout << "(";
            e1->print();
            cout << " - ";
            e2->print();
            cout << ")";
        };
        double evaluate(double X) { /* ToDo */
            double res = e1->evaluate(X) - e2->evaluate(X);
            return res;
        }
        Exp *derivate()    { /* ToDo */
            MinusExp *der = new MinusExp(e1->derivate(), e2->derivate());
            return der;
        }
        Exp *clone()       { /* ToDo */
            MinusExp *copia = new MinusExp(e1->clone(), e2->clone());
            return copia;
        }
};

class MultExp : public BinaryExp {
    public:
        MultExp(Exp *e1, Exp *e2) : BinaryExp(e1, e2){}
        void print()              { /* ToDo */
            //cout << "(";
            e1->print();
            cout << " * ";
            e2->print();
            //cout << ")";
        }
        double evaluate(double X) { /* ToDo */
            double res = e1->evaluate(X) * e2->evaluate(X);
            return res;
        }
        Exp *derivate()    { /* ToDo */
            PlusExp *der = new PlusExp(new MultExp(e1->derivate(), e2->clone()), new MultExp(e1->clone(), e2->derivate()));
            return der;
        }
        Exp *clone()       { /* ToDo */
            MultExp *copia = new MultExp(e1->clone(), e2->clone());
            return copia;
        }
};

class DivExp : public BinaryExp {
    public:
        DivExp(Exp *e1, Exp *e2) : BinaryExp(e1, e2){}
        void print()              { /* ToDo */
            //cout << "(";
            e1->print();
            cout << " / ";
            e2->print();
            //cout << ")";
        };
        double evaluate(double X) { /* ToDo */
            double res = e1->evaluate(X) / e2->evaluate(X);
            return res;
        }
        Exp *derivate()    { /* ToDo */
            MinusExp *num = new MinusExp(new MultExp(e1->derivate(), e2->clone()), new MultExp(e1->clone(), e2->derivate()));
            MultExp *denom = new MultExp (e2->clone(), e2->clone());
            DivExp *der = new DivExp (num, denom);
            return der;
        }
        Exp *clone()       { /* ToDo */
            DivExp *copia = new DivExp(e1->clone(), e2->clone());
            return copia;
        }
};

class SinExp : public UnaryExp {
    public:
        SinExp(Exp *e1) : UnaryExp(e1){}
        void print()              { /* ToDo */
            cout << "sin (";
            e1->print();
            cout << ")";
        };
        double evaluate(double X) { /* ToDo */
            double res = sin(e1->evaluate(X));
            return res;
        }

        Exp *derivate(); //el cuerpo después de la definición de la clase coseno

        Exp *clone()       { /* ToDo */
            SinExp *copia = new SinExp(e1->clone());
            return copia;
        }
};

class CosExp : public UnaryExp {
    public:
        CosExp(Exp *e1) : UnaryExp(e1){}
        void print()              { /* ToDo */
            cout << "cos (";
            e1->print();
            cout << ")";
        };
        double evaluate(double X) { /* ToDo */
            double res = cos(e1->evaluate(X));
            return res; }
        Exp *derivate()    { /* ToDo */
            MultExp *aux = new MultExp(new ConstExp(-1), new SinExp(e1->clone()));
            MultExp *der = new MultExp(aux, e1->derivate());
            return der;
        }
        Exp *clone()       { /* ToDo */
            CosExp *copia = new CosExp(e1->clone());
            return copia;
        }
};

Exp* SinExp::derivate(){
    MultExp *der = new MultExp(new CosExp(e1->clone()), e1->derivate());
    return der;
}


class TanExp : public UnaryExp {
    public:
        TanExp(Exp *e1) : UnaryExp(e1){}
        void print()              { /* ToDo */
            cout << "tg(";
            e1->print();
            cout << ")";
        };
        double evaluate(double X) { /* ToDo */
            double res = sin(e1->evaluate(X))/cos(e1->evaluate(X));
            return res;
        }
        Exp *derivate()    { /* ToDo */
            DivExp *der = new DivExp (e1->derivate(), new MultExp(new CosExp(e1->clone()), new CosExp(e1->clone())));
            return der;
        }
        Exp *clone()       { /* ToDo */
            TanExp *copia = new TanExp(e1->clone());
            return copia;
        }
};


int main(){
    Exp *expr = new DivExp(
                    new SinExp(                        // numerador
                        new PlusExp(
                            new MultExp(
                                new ConstExp(3),
                                new VariableExp()),
                            new ConstExp(4))),
                    new PlusExp(                       // denominador
                        new ConstExp(2),
                        new MultExp(
                            new ConstExp(3),
                            new CosExp(
                                new DivExp(
                                    new VariableExp(),
                                    new PlusExp(
                                        new ConstExp(2),
                                        new VariableExp()))))));


    cout << "Expresion:\n";
    expr->print();

    double val = expr->evaluate(3.14);
    cout << "\n\nla expresion evaluada en 3.14 vale: " << val << endl;

    Exp *deriv = expr->derivate();
    cout << "\n\nla expresion derivada es:\n";
    deriv->print();

    delete deriv;
    delete expr;

    return 0;
}
