#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;


// total de alumnos en el juego
const int num_alumnos=1000;

// el campo es un cuadrado de 100 x 100
const float LadoCampo=100.0;

// UDT para representar la posición de un Alumno. Si, los alumnos son puntuales
struct Punto2D
{
    // posicion en coordenadas cartesianas
    float x,y;

    // inicializa x con un valor al azar entre xmin y xmax (idem con y entre ymin e ymax)
    void set_random(float xmin,float xmax, float ymin, float ymax)
    {
        //cout << "set random posicion\n";
        x =  (xmax-xmin) * rand() / RAND_MAX + xmin;
        y =  (ymax-ymin) * rand() / RAND_MAX + ymin;
    }

    // calcula la distancia a otro Punto2D
    float distancia(Punto2D otro)
    {
        return sqrt((x-otro.x)*(x-otro.x)+(y-otro.y)*(y-otro.y));
    }

    // mueve el punto una dada distancia, en una dada dirección (angulo) generando un nuevo punto2D
    Punto2D mover(float angulo, float dist)
    {
        Punto2D nuevo = { x + dist * cos(angulo),y + dist * sin(angulo) };
        return nuevo;
    }
};

// UDT para representar un Alumno
struct Alumno
{
    // posicion desde donde inicia el juego
    Punto2D posicion_inicial;

    // posicion actual del alumno
    Punto2D posicion_actual;

    // dice si fue manchado
    bool manchado;

    // dice si ya es inmune ( que no puede volver a ser manchado )
    bool inmune;

    // cuenta el tiempo que transcurrió desde que fuera manchado
    int tiempo_desde_mancha;

    // construye un alumno con posición inicial=actual al azar, sin mancha ni inmunidad (TO DO)
    Alumno(){
        //cout << "constructor alumno\n";
        posicion_inicial.set_random(0, LadoCampo, 0, LadoCampo);
        posicion_actual = posicion_inicial;
        manchado = false;
        inmune = false;
        tiempo_desde_mancha = -1; // lo uso para saber a partir de cuándo contar
    }

    // elige una direccion al azar y se mueve, dentro de la distancia máxima a su posicion inicial (TO DO)
    void moverse(float max_distancia){
        float alfa;
        do{
            alfa = rand();
            posicion_actual = posicion_actual.mover(alfa, 1);
        }while (posicion_actual.distancia(posicion_inicial) <= max_distancia && posicion_actual.x >= 0 &&
                posicion_actual.x <= LadoCampo && posicion_actual.y >= 0 && posicion_actual.y <= LadoCampo);
    }

    // distancia a otro alumno (TO DO)
    float distancia(Alumno otro){
        return posicion_actual.distancia(otro.posicion_actual);
    }
};

// UDT para representar un juego de Reglas
struct Reglas
{
    // probabilidad de que un par de alumnos se toquen
    float p_contagio;

    // rango de contagio en m
    float rango_contagio;

    // distancia máxima desde posición inicial en m
    float max_distancia;

    // tiempo desde que es manchado hasta que puede manchar a otros
    int tiempo_incubacion;

    // tiempo que tarda en desmancharse un alumno manchado y volverse inmune
    int tiempo_cura;
};

// UDT para representar el Juego
struct ManchitaCiega
{
    // el juego de reglas con que se va a jugar
    Reglas reglas;

    // contenedor de todos los Alumnos
    Alumno jugadores[num_alumnos]; //al declarar el arreglo ya se inicializan sus elementos con el constructor

    //el número de manchados que hay actualmente
    int numero_manchados;

    // el numero de inmunes actual
    int numero_inmunes;

    // construye el juego, posicionando a todos los jugadores al azar en el campo, y manchando a 1 alumno (TO DO)
    ManchitaCiega(Reglas reg){
        reglas = reg;
        int primero = rand() % num_alumnos;
        jugadores[primero].manchado = true; //contagio al primero
        jugadores[primero].tiempo_desde_mancha = 0;
        numero_manchados = 1;
        numero_inmunes = 0;
    }

    // realiza todas las tareas para avanzar un turno la simulación (TO DO)
    void avanzar_un_turno(){
        mover_alumnos();
        manchar_vecinos();
        actualizar_estado();
    }

    // mueve a cada alumno 1m en una dirección al azar (TO DO)
    void mover_alumnos(){
        for (int i = 0; i < num_alumnos; i++){
            jugadores[i].moverse(reglas.max_distancia);
        }
    }

    // hace que cada alumno contagioso, manche a los vecinos (TO DO)
    void manchar_vecinos(){
        for (int i = 0; i < num_alumnos-1; i++){
            for (int j = i+1; j < num_alumnos; j++){
                if (jugadores[i].distancia(jugadores[j]) <= reglas.rango_contagio){

                    if (jugadores[i].manchado &&  jugadores[i].tiempo_desde_mancha >= reglas.tiempo_incubacion &&
                        !jugadores[j].inmune && !jugadores[j].manchado){

                            if (rand() % int(reglas.p_contagio*100) != 0){
                                jugadores[j].manchado = true;
                                jugadores[j].tiempo_desde_mancha = 0;
                                continue;
                            }
                    }

                    //cuando pongo la condicion de reglas.tiempo_incubacion en el segundo if
                    //deja de tener sentido, y nunca se contagia nadie. No logro encontrar el error. La dejo comentada

                    if (jugadores[j].manchado && jugadores[j].tiempo_desde_mancha > reglas.tiempo_incubacion &&
                        !jugadores[i].inmune && !jugadores[i].manchado){
                            if (rand() % int(reglas.p_contagio*100) != 0){ //para ASPO y DiSPO, se cumple 1 de cada 10 veces
                                jugadores[i].manchado = true;              //para VivaLaPepa, se cumple 94 de cada 95 veces
                                jugadores[i].tiempo_desde_mancha = 0;      //no sé cómo hacerlo con 0.95, no se me ocurre
                            }
                    }
                }
            }
        }
    }

    // actualiza el estado de cada alumno y de la simulación en general (TO DO)
    void actualizar_estado(){
        numero_manchados = 0;
        for (int i = 0; i < num_alumnos; i++){
            if(jugadores[i].tiempo_desde_mancha != -1)
                jugadores[i].tiempo_desde_mancha++;
            if(jugadores[i].manchado && jugadores[i].tiempo_desde_mancha == reglas.tiempo_cura){
                jugadores[i].manchado = false;
                jugadores[i].inmune = true;
                numero_inmunes++;
            }
            if(jugadores[i].manchado){
                numero_manchados++;
            }
        }
    }
};

int main()
{
    srand(time(0));
    // disponemos de 3 sets de reglas diferentes VIVALAPEPA, DSPO y ASPO
    Reglas vivalapepa= { .95, // como ambos intentan tocarse, la probabilidad es alta, aunque estén vendados
                                        4,  // el alcance es doble porque ambos intentan tocarse
                                        sqrt(2)*LadoCampo,  //todo el campo está accesible
                                        4*24,  // 4 días desde contagio para contagiar
                                        14*24 // 14 días desde contagio para curarse e inmunizarse
                                    };
    Reglas dispo = { 0.1, // la probabilidad es baja porque el alumno no manchado puede ver y esquivar al manchado
                                2,  // el alcance máximo es sólo el de 1 alumno
                                sqrt(2)*LadoCampo,  // todo el campo está accesible
                                4*24, // 4 días desde contagio para contagiar
                                14*24 // 14 días desde contagio para curarse e inmunizarse
                            };
    Reglas aspo = { 0.1, // la probabilidad es baja porque el alumno no manchado puede ver y esquivar al manchado
                                2,  // el alcance máximo es sólo el de 1 alumno
                                3, // solo 3 metros alrededor de la posición inicial están disponibles.
                                4*24, // 4 días desde contagio para contagiar
                                14*24 // 14 días desde contagio para curarse e inmunizarse
                            };

    // para cada juego de reglas, realizamos la simulación
    ManchitaCiega mcv(vivalapepa);
    ManchitaCiega mcd(dispo);
    ManchitaCiega mca(aspo);

    cout << "VivaLaPepa\tDiSPO\tASPO\n";
    cout << "1\t1\t1\n";

    while(true) //no entiendo por qué el numero de manchados nunca llega a 0
    {
        // cuando no quedan mas manchados se acaba todas simulación
        if (mcv.numero_manchados==0 && mcd.numero_manchados==0 && mca.numero_manchados == 0)
            break;
        if(mcv.numero_manchados)
        {
            mcv.avanzar_un_turno();
            cout << mcv.numero_manchados<<'\t';
        }
        else
        {
            cout << 0<<'\t';
        }
        if(mcd.numero_manchados)
        {
            mcd.avanzar_un_turno();
            cout << mcd.numero_manchados<<'\t';
        }
        else
        {
            cout << 0<<'\t';
        }
        if(mca.numero_manchados)
        {
            mca.avanzar_un_turno();
            cout << mca.numero_manchados<<'\n';
        }
        else
        {
            cout << 0<<'\n';
        }
    }

return 0;
}
