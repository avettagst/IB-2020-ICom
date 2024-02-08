#include "icom_helpers.h"


// caracteres en el mapa (el nombre de la variable indica su significado)
const char bunker = 'B';
const char bunkerVisitado='b';
const char salida='S';
const char pared='#';
const char espacio=' ';
const char espacioVisitado='o';
const char espacioResaltado='*';

// estructura para representar una celda del mapa {fila, columna}
struct Celda
{
    // fila f y columna c de la celda
    size_t f,c;

    Celda(size_t a, size_t b){
        f = a;
        c = b;
    }

    bool operator==(Celda ce){
        return (f == ce.f && c == ce.c);
    }
};

// UDT para representar la instalacion (su mapa y sus niveles de radiacion)
class LaberintoRadiactivo
{
public:
    // UDT que representa un camino de salida:
    struct Camino
    {
        // constructor default
        Camino():radTotal(0.0){}

        //destructor
        ~Camino() {}

        // agrega la celda cel al camino y suma la radiacion rad al total acumulado
        void agregarCelda(Celda cel, float rad){ // TODO
            path.push_back(cel);
            radTotal += rad;
        }

        // vector de celdas que componen el camino
        vector<Celda> path;

        // radiacion total acumulada a lo largo del camino
        float radTotal;
    };

    // construye el LaberintoRadiactivo usando el archivo mapa_file que contiene el mapa en representacion ASCII
    // y radlevel_file que contiene 3 valores por cada linea: fila, columna y radiacion
    LaberintoRadiactivo(string mapa_file,string radlevel_file) // TODO
    {
        ifstream mapafile(mapa_file);
        if(mapafile) { // si el archivo está abierto
            int i = 0;
            string fila;
            while (getline (mapafile, fila)){
                mapa[i] = fila;
                i++;
            }
        }

        ifstream radfile(radlevel_file);
        if (radfile){
            int j = 0;
            float e;
            while (radfile >> e){
                rad[j/3][j%3] = e;
                j++;
            }
        }

        nf = mapa.size();
        nc = mapa[0].size(); //asumo que todas las filas tienen el mismo largo

    }

    // imprime el mapa en su estado actual
    void print(){ // TODO
        for (string f : mapa){
            cout << f << '\n';
        }

        cout << '\n';
    }

    // encuentra el mejor camino y lo resalta en el mapa
    // imprime el mapa y la radiacionTotal
    void resolver(){ // TODO
        Celda b = localiza(bunker);
        Camino* solucion = buscarMejorCamino(b);

        print(); //imprimo mapa original

        for (size_t i = 0; i < solucion->path.size(); i++){
            mapa[solucion->path[i].f][solucion->path[i].c] = espacioResaltado;
        }

        print(); //imprimo mapa modificado
        cout << "Radiacion total: " << solucion->radTotal << '\n';



    }
private:
    // localiza la celda donde se encuentra el caracter c y la retorna
    Celda localiza(char c){ // TODO
            for (size_t i = 0; i < nf; i++){
                for (size_t j = 0; j < nc; j++){
                    if (mapa[i][j] == c)
                        return Celda(i,j);   //la funcion termina al encontrar el primer caracter que coincida con c
                }
            }

            return Celda(-1,-1); //representando que hubo un error

    }

    // recorre el laberinto recursivamente desde la Celda cel buscando la salida.
    // no se permite moverse en diagonal.
    // Si no encuentra la salida retorna nullptr.
    // Si la encuentra retorna un puntero al camino que conduce a la salida
    // minimizando la radiacion total. El camino se va armando en el mismo proceso recursivo.
    // Ayuda1: hay que buscar a partir de cada vecino, porque hay mas de un camino posible y nada garantiza que el primero que se encuentre sea el mejor
    // Ayuda2: hay que seleccionar y retornar el camino que tenga la minima radiacion total (y que va a hacer con los otros?)
    // Ayuda3: hay que desmarcar la casilla (ponerla como no visitada), antes de retornar, porque puede ser visitada nuevamente por otro camino.
    Camino * buscarMejorCamino(Celda cel){ //TODO

        Camino *cam = new Camino;

        cam->agregarCelda(cel, rad[cel.f][cel.c]); //agrego esta celda
        mapa[cel.f][cel.c] = espacioVisitado;      //la marco

        if (mapa[cel.f+1][cel.c] == espacio && cel.f+1 <= nf)
            buscarMejorCamino(Celda(cel.f+1, cel.c));

        if (mapa[cel.f][cel.c+1] == espacio && cel.c+1<= nc)
            buscarMejorCamino(Celda(cel.f, cel.c+1));

        if (mapa[cel.f-1][cel.c] == espacio && nf >= 0)
            buscarMejorCamino(Celda(cel.f-1, cel.c));

        if (mapa[cel.f][cel.c-1] == espacio && nc >=0)
            buscarMejorCamino(Celda(cel.f, cel.c-1));


        return cam;
    }

    // dimensiones del mapa nf=numero de filas, nc=numero de columnas
    size_t nf,nc;

    // mapa de la instalacion en representacion de caracteres, cada fila es un string y cada caracter dentro de ese string es una celda
    // se puede ver como una matriz
    vector<string>mapa;

    // valores de radiacion residual rad[i][j] para cada celda {i,j}
    vector<vector<float>> rad;
};

int main()
{
    try
    {
        LaberintoRadiactivo labrad("mapa.txt","niveles_radiacion.txt");
        labrad.print();
        labrad.resolver();
        return 0;
    }
    catch (string &s)
    {
        cerr<< "Error: " << s << endl;
        return -1;
    }
    catch(...)
    {
        cerr << "Error inesperado"<< endl;
        return -1;
    }
}
