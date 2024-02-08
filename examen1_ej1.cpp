#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <ctime>


using namespace std;

enum Palo {
    PICAS, TREBOL, CORAZONES, DIAMANTES, NUM_PALOS
};

enum Color {
    ROJO, NEGRO
};

enum Valor {
    AS = 1, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, OCHO, NUEVE, DIEZ, J, Q, K
};


// Representación de una carta a través de un UDT "Carta"
struct Carta {
    // representacion
    Palo x;
    Valor z;

    // funcionalidad

    // imprime la carta (ej: "4 de PICAS") (TO DO)
    void imprimir(){
        switch(z){
            case 1:
                cout << "AS";
                break;
            case 11:
                cout << "J";
                break;
            case 12:
                cout << "Q";
                break;
            case 13:
                cout << "K";
                break;
            default:
                cout << z;
                break;
        }

        switch(x){
            case 0:
                cout << " de PICAS" << endl;
                break;
            case 1:
                cout << " de TREBOL" << endl;
                break;
            case 2:
                cout << " de CORAZONES" << endl;
                break;
            case 3:
                cout << " de DIAMANTE" << endl;
                break;
        }
    }

    // retorna el color de una carta   (TO DO)
    Color getColor(){
        if (x == PICAS || x == TREBOL)
            return NEGRO;
        else
            return ROJO;
    }

    // metodo para comparar cartas (usado en el ordenamiento)
    bool operator<(const Carta& otra) {
        return z < otra.z;
    }
};

// cantidad total de cartas
const unsigned int MAX_CARDS = K * NUM_PALOS;

// Representación de un mazo de cartas a través del UDT "Mazo"
struct Mazo {
    Carta vec[MAX_CARDS];          // vector nativo con todas las cartas
    unsigned int idxReparto = 0;   // indice de reparto, comienza en cero y se incrementa
                                   // de acuerdo a la repartida

    // construye un mazo: se completa vec y se resetea (se baraja y se inicializa idxReparto)
    Mazo() {
        fill();
        reset();
    }

    // coloca todas las cartas en vec (TO DO)
    void fill(){
        int pos_carta = 0;
        for (int i = 0; i < NUM_PALOS; i++){
            for (int j = 1; j <= K; j++){
                vec[pos_carta].x = Palo(i);
                vec[pos_carta].z = Valor(j);
                pos_carta++;
            }
        }






    }

    // función que pide barajar (mezclar las cartas) e inicializa el indice de reparto
    void reset() {
        barajar();
        idxReparto = 0;
    }

    // mezcla todas las cartas (TO DO)
    void barajar(){
        //probablemente podría hacerse más eficiente, pero es lo que se me ocurrió y funciona rápido
        int indices[MAX_CARDS] = {0};
        int nueva_pos;
        Carta copia[MAX_CARDS];
        for (int i = 0; i < MAX_CARDS; i++){
            do{
                nueva_pos = rand() % MAX_CARDS;
            }while(indices[nueva_pos] != 0);
            copia[i] = vec[nueva_pos];
        }

        for (int i = 0; i < MAX_CARDS; i++){
            vec[i] = copia[i];
        }



    }

    // saca n cartas del mazo, las pone en cartas
    // y ordena ese vector por número
    void giveMeCards(vector<Carta>& cartas, unsigned int n) {
        assert(idxReparto + n < MAX_CARDS);
        for (unsigned int i = 0; i < n; ++i)
            cartas.push_back(vec[idxReparto++]);
        sort(cartas.begin(), cartas.end());
    }

};


// Representación de un jugador a través del UDT "Jugador"
struct Jugador {
    Jugador(const string& nombre_) {
        nombre = nombre_;
    }

    string nombre;          // nombre del jugador
    vector<Carta> cartas;   // sus cartas

    // analiza que tipo de juego tiene
    // 2 cartas del mismo número y las otras 3 de distinto número
    bool esPar() {
        vector<int> reps = repeticiones();
        return reps[0] == 2 && reps[1] == 1;
    }

    // 2 x 2 cartas del mismo número y la otra distinta
    bool esDoblePar() {
        vector<int> reps = repeticiones();
        return reps[0] == 2 && reps[1] == 2;
    }

    // 3 cartas del mismo número y las otras 2 de distinto número (TO DO)
    bool esPierna(){
        vector<int> reps = repeticiones();
        return reps[0] == 3 && reps[1] == 1;
    }

    // 3 cartas de un mismo número y las otras  2 de otro número (TO DO)
    bool esFull(){
        vector<int> reps = repeticiones();
        return reps[0] == 3 && reps[1] == 2;
    }

    // 4 cartas iguales de distinto palo (TO DO)
    bool esPoker(){
        vector<int> reps = repeticiones();
        return reps[0] == 4;
    }

    // las 5 cartas del mismo palo(ojo!) (TO DO)
    bool esColor(){
        Palo p = cartas[0].x;
        for (int i = 1; i < 5; i++){

            if (cartas[i].x != p)
                return false; //si alguna carta tiene palo distinto a la primera, no es color
        }
        return true; // si no entra al if del for, es color
    }

    // valores consecutivos (el AS puede aparecer al comienzo y al final) (TO DO)
    bool esEscalera(){
        int n = cartas[0].z;

        for (int i = 1; i < 4; i++){ //la ultima carta la analizo aparte
            if (cartas[i].z != n + 1)
                return false;
        }

        if (n==10){
            if (cartas[4].z == 1)
                return true;
        }
        else
            if (cartas[4].z == n+4)
                return true;

        return false;
    }

    // valores consecutivos del mismo palo (el AS puede aparecer al comienzo y al final) (TO DO)
    bool esEscaleraReal(){
        if(esEscalera() && esColor())
            return true;

        return false;
    }

    // imprime el nombre del jugador y sus cartas
    void imprimir() {
        cout << nombre << endl;
        for (unsigned int i = 0; i < cartas.size(); i++)
            cartas[i].imprimir();
        cout << "===========" << endl;

    }

    // función auxiliar para ayudar a definir el tipo de juego
    // cuenta cuantas cartas hay de cada valor y ordena esas repeticiones de mayor a menor
    // ejemplo (5 5 6 6 6) retorna (3, 2, 0, 0, ...)
    // ejemplo (5 5 6 6 9) retorna (2, 2, 1, 0, ...)
    // ejemplo (2 8 8 8 8) retorna (4, 1, 0, 0, ...)
    vector<int> repeticiones() {
        vector<int> v(K);
        for (unsigned int i = 0; i < cartas.size(); i++)
            v[cartas[i].z-1]++;
        sort(v.rbegin(), v.rend());
        return v;
    }
};

// Representación de un Crupier a través del UDT "Crupier"
struct Crupier {
    // construye una instancia, recibe los participantes de la partida
    Crupier(vector<Jugador>& jugadores_) : jugadores(jugadores_)
    {
    }

    vector<Jugador>& jugadores;     // jugadores

    Mazo mazo;                      // mazo involucrado

    // resetea el mazo, baraja y reparte las cartas a los jugadores
    void inicioPartida() {
        mazo.reset();
        for (unsigned int i = 0; i < jugadores.size(); i++) {
            mazo.giveMeCards(jugadores[i].cartas, 5);
        }
    }
};

// main para probal un poco los métodos.
int main()
{
    vector<Jugador> gente = { Jugador("juan"), Jugador("pedro"), Jugador("maria"), Jugador("alicia") };
    Crupier cr(gente);
    srand(time(NULL));
    cr.inicioPartida();
    for (unsigned int i = 0; i < gente.size(); i++) {
        gente[i].imprimir();
        cout << " tiene poker: " << gente[i].esPoker() << endl;
        cout << " tiene full: " << gente[i].esFull() << endl;
        cout << " tiene par: " << gente[i].esPar() << endl;
        cout << " tiene doble par: " << gente[i].esDoblePar() << endl;
        cout << " tiene pierna: " << gente[i].esPierna() << endl;
        if (gente[i].esEscaleraReal()){
            cout << " tiene color: " << 0 << endl;
            cout << " tiene escalera: " << 0 << endl;
            cout << " tiene escaleraReal: " << 1 << endl;
        }
        else{
            cout << " tiene color: " << gente[i].esColor() << endl;
            cout << " tiene escalera: " << gente[i].esEscalera() << endl;
            cout << " tiene escaleraReal: " << 0 << endl;
        }

    }
}
