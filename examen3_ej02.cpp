#include "icom_helpers.h"

// estos son los caracteres que se pueden encontrar en el laberinto
const char pared = '#';
const char espacio = ' ';
const char espacio_visitado = 'o';
const char entrada = 'E';
const char entrada_visitada = 'e';
const char salida = 'S';
const char salida_visitada='s';

struct Celda
{
    int f, c;
};

class Laberinto
{
public:
	// constructor del laberinto que implementa el algoritmo descripto en el enunciado
    Laberinto(size_t nf_, size_t nc_)//TODO
    {
        if (nf_ < 3 || nc_ < 3 || nf_*nc_ < 15 || nf_ % 2 == 0 || nc_ % 2 == 0)
            throw string("Condiciones requeridas de filas/columnas no cumplidas");

        nf = nf_;
        nc = nc_;

        txtrep.resize(nf);
        for (string &f : txtrep)
            f.resize(nc);

        inicializa();
        creaentrada();
        creasalida();
        recursion(localiza(entrada), QUIETO);   //no salió :(
        limpieza();
    }

	// imprime el laberinto (es idéntica a la del parcial)
    void print()
    {
        for(size_t i=0; i<nf; ++i )
            cout << txtrep[i] << endl;
    }
private:
    enum opciones{  //DE DÓNDE VENGO
        ARRIBA, ABAJO, IZQUIERDA, DERECHA, QUIETO
    };

    void inicializa()
    {
        for (size_t i = 0; i < nf; i++)
        {
            for (size_t j = 0; j < nc; j++)
            {
                if (i % 2 == 0 || j % 2 == 0)
                    txtrep[i][j] = pared;
                else
                    txtrep[i][j] = espacio;
            }
        }

    }

    void creaentrada()
    {
        size_t i = rand() % nf;
        size_t j = rand() % nc;

        if (txtrep[i][j] == espacio)
            txtrep[i][j] = entrada;
        else
            creaentrada(); //llamo a la funcion de nuevo
    }

    void creasalida()
    {
        size_t i = rand() % nf;
        size_t j = rand() % nc;

        if (txtrep[i][j] == espacio)
            txtrep[i][j] = salida;
        else
            creasalida(); //llamo a la funcion de nuevo
    }

    Celda localiza(char ent)    //busco la entrada para empezar la recursión
    {
        for (size_t i = 0; i < nf; i++)
        {
            for (size_t j = 0; j < nc; j++)
            {
                if(txtrep[i][j] == ent)
                    return Celda{(int)i,(int)j};
            }
        }
        throw string ("El laberinto no tiene Entrada");
    }

    void recursion (Celda c, opciones d)    //d representa de dónde vengo (arriba, abajo, izquierda o derecha)
    {
        //Fuera del mapa
        if (c.f < 0 || c.f >= (int)nf || c.c < 0 || c.c >= (int)nc)
            return;

        //Lugares no válidos
        if (txtrep[c.f][c.c] == espacio_visitado || txtrep[c.f][c.c] == salida_visitada || txtrep[c.f][c.c] == entrada_visitada || txtrep[c.f][c.c] == pared)
            return;

        //print();

        switch(d)   //si estoy en una celda válida, marco la celda intermedia (entre la anterior y esta)
        {
            case ARRIBA:
                txtrep[c.f-1][c.c] = espacio_visitado;
                break;
            case ABAJO:
                txtrep[c.f+1][c.c] = espacio_visitado;
                break;
            case IZQUIERDA:
                txtrep[c.f][c.c-1] = espacio_visitado;
                break;
            case DERECHA:
                txtrep[c.f][c.c+1] = espacio_visitado;
                break;
            case 4:     //es el primer llamado a la función, estoy en la entrada
                break;
            default:
                throw string("Falla inesperada");
        }

        //Lugares validos. Marco
        if (txtrep[c.f][c.c] == espacio)
            txtrep[c.f][c.c] = espacio_visitado;

        if (txtrep[c.f][c.c] == entrada)
            txtrep[c.f][c.c] = entrada_visitada;

        if (txtrep[c.f][c.c] == salida)
        {
            txtrep[c.f][c.c] = salida_visitada;
            return; //no sigo desde acá
        }

        const size_t nvecinos = 4;

        bool vecinos[nvecinos] = {false};

        do
        {
          int v = rand() % nvecinos;
          switch(v)
          {
            case 0:
                if(!vecinos[0]) //si todavia no probé con este vecino, pruebo
                {
                    vecinos[0] = true;
                    recursion(Celda{c.f+2,c.c},ARRIBA);
                }
                else
                    return;
                break;

            case 1:
                if(!vecinos[1])
                {
                    vecinos[1] = true;
                    recursion(Celda{c.f-2,c.c},ABAJO);
                }
                else
                    return;
                break;

            case 2:
                if (!vecinos[2])
                {
                    vecinos[2] = true;
                    recursion(Celda{c.f,c.c+2},IZQUIERDA);
                }
                else
                    return;
                break;

            case 3:
                if(!vecinos[3])
                {
                    vecinos[3] = true;
                    recursion(Celda{c.f,c.c-2},DERECHA);
                }
                else return;
                break;

            default:
                throw string ("Falla inesperada");
          }
        }while(!(vecinos[0] && vecinos[1] && vecinos[2] && vecinos[3]));    //mientras quede algún vecino sin visitar
    }

    void limpieza()
    {
        for (size_t i = 0; i < nf; i++)
        {
            for (size_t j = 0; j < nc; j++)
            {
                if (txtrep[i][j] == espacio_visitado)
                    txtrep[i][j] = espacio;
                if (txtrep[i][j] == salida_visitada)
                    txtrep[i][j] = salida;
                if (txtrep[i][j] == entrada_visitada)
                    txtrep[i][j] = entrada;
            }
        }
    }

    // numero de filas y columnas, deben ser impar y nf * nc >=15
    size_t nf, nc;

	// representacion textual del laberinto como matriz de caracteres.
    vector<string> txtrep;

};

int main() // TODO
{
    srand(time(0));
    try{
        cout << "El laberinto debe tener cantidad impar de filas y columnas, éstas deben ser 3 o mas y su producto no debe ser menor a 15\n";

        cout << "Ingrese nro de filas: ";
        size_t f;
        cin >> f;

        cout << "\nIngrese nro de columnas: ";
        size_t c;
        cin >> c;

        Laberinto lab(f, c);

        lab.print();
    }

    catch (string &s)
    {
        cout << "Error: " << s << endl;
    }
    catch (...)
    {
        cout << "Error sorpresa\n";
    }

    return 0;
}
