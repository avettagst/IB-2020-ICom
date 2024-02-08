#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum carrera { fisica, mecanica, nuclear, telecomunicaciones };

enum cursada { Mate2, Electro, Exp2, Termo };

ostream & operator << (ostream &out, const cursada &c);

class Persona
{
    private:
    	string nombre;
    	string ciudad;
    	unsigned short edad;
    	unsigned int dni;

	public:

    	Persona(string nombre_, string ciudad_, unsigned short edad_,unsigned int dni_) //TO DO
        : nombre(nombre_), ciudad(ciudad_), edad(edad_), dni(dni_) {}



    	const string &get_nombre() const {//TO DO
            return nombre;
    	}

    	const string &get_ciudad() const {//TO DO
    	    return ciudad;
    	}

    	unsigned short get_edad() const {//TO DO
            return edad;
    	}

    	unsigned int get_dni() const {//TO DO
            return dni;
    	}

    	//Las implementaciones de este metodo deben imprimir en la pantalla toda la informacion relativa a cada Persona
    	virtual	void print_info(){//TO DO donde corresponda
            cout << "NOMBRE:\t" << nombre;
            cout << "\nDNI:\t" << dni;
            cout << "\nEDAD:\t" << edad;
            cout << "\nCIUDAD:\t"<< ciudad;
            cout << '\n';
    	}
};

class Alumno : public Persona
{
    	carrera especialidad;
    	float calificacion;

	public:

    	Alumno (string nombre_, string ciudad_, unsigned short edad_,unsigned int dni_,carrera especialidad_) //TO DO
       : Persona(nombre_, ciudad_, edad_, dni_), especialidad(especialidad_) {}


    	void set_calificacion(float cal)
    	{
    		calificacion=cal;
    	}

    	float get_calificacion() const
    	{
    		return calificacion;    //no s� qu� problema hay con esta funci�n. Prob� de todo
    	}

    	carrera get_especialidad() const {//TO DO
    	    return especialidad;
    	}

    	void print_carrera(){
            switch(especialidad){
                case 0:
                    cout << "Lic. en Fisica";
                    break;
                case 1:
                    cout << "Ing. Mecanica";
                    break;
                case 2:
                    cout << "Ing. Nuclear";
                    break;
                case 3:
                    cout << "Ing. en Telecomunicaciones";
                    break;
            }

    	}

    	void print_info() override{//TO DO
            cout << "NOMBRE:\t" << get_nombre();
            cout << "\nDNI:\t" << get_dni();
            cout << "\nCARRERA: "; print_carrera();
            cout << "\nEDAD:\t" << get_edad();
            cout << "\nCIUDAD:\t"<< get_ciudad();
            cout << "\nCalificacion: " << calificacion;
            cout << "\n\n";
    	}

};

class Docente : public Persona
{
	public:
    	Docente (string nombre_, string ciudad_, unsigned short edad_,unsigned int dni_) //TO DO
    	: Persona(nombre_, ciudad_, edad_, dni_) {}
};

class Catedra
{
    	cursada curso;
    	vector<Docente> docentes;
    	vector<Alumno> alumnos;

	public:

    	Catedra(cursada curso_,const vector<Docente> &docentes_, const vector<Alumno> &alumnos_) //TO DO
    	: curso(curso_), docentes(docentes_), alumnos(alumnos_){}

    	//busca al alumno por dni y le asigna la calificacion cal.
    	void set_calificacion(unsigned int dni_alumno, float cal){ //TO DO
    	    for (size_t i = 0; i < alumnos.size(); i++){
                if (alumnos[i].get_dni() == dni_alumno){
                    alumnos[i].set_calificacion(cal);
                    return; //para terminar con la funcion
                }
    	    }
    	    cout << "Alumno no encontrado\n"; //si no se encuentra al alumno, no se llama al return
                                              //la funci�n sigue hasta el final
    	}

    	void print_all_info() const
    	{
    		float promedio=0;
    		cout << endl << "Materia: " << curso << endl << endl;
    		cout << "***********PLANTEL DOCENTE************ "<< endl << endl;

    		for (auto d:docentes)
    		{
    			d.print_info();
    			cout << endl;
    		}
    		cout << "***************ALUMNOS**************** "<< endl << endl;

    		for (auto a:alumnos)
    		{
    			promedio += a.get_calificacion();
    			a.print_info();
    		}
    		promedio/=alumnos.size();
    		cout << "PROMEDIO GLOBAL: " << promedio << endl;
    		cout << "====================================== "<< endl << endl;
    	}
};




int main()
{
    vector<Docente> profes = {
        {"Pedro Picapiedras","Piedra del Aguila",50,20000000},
        {"Pancho Villa","Villa la Angostura",35,30000000}
    };
    vector<Alumno> chicos =	{
        {"Maria del Carmen","Mar del Plata",23,40000000,fisica},
        {"Juan Carlos","Carlos Paz",25,42000000,mecanica},
        {"Paul Atreides","Arrakis",22,39000000,nuclear},
        {"Bernardo Santos","Bariloche",27,35000000,telecomunicaciones}
    };

    Catedra catedra1(Mate2,profes,chicos);
    Catedra catedra2(Electro,profes,chicos);

    catedra1.set_calificacion(40000000,7.5);
    catedra1.set_calificacion(42000000,5.0);
    catedra1.set_calificacion(39000000,10.);
    catedra1.set_calificacion(35000000,8.5);

    catedra2.set_calificacion(40000000,7.0);
    catedra2.set_calificacion(42000000,7.0);
    catedra2.set_calificacion(39000000,10.);
    catedra2.set_calificacion(35000000,6.5);

    catedra1.print_all_info();
    catedra2.print_all_info();

    return 0;
}


ostream & operator << (ostream &out, const cursada &c)
{
	string s;

	switch (c)
	{
		case Mate2:
			s="MATEMATICAS II";
			break;
		case Electro:
			s="ELECTROMAGNETISMO";
			break;
		case Exp2:
			s="FISICA EXPERIMENTAL II";
			break;
		case Termo:
			s="TERMODINAMICA Y FISICOQUIMICA";
			break;
		default:
			s="ERROR EN LA CURSADA!";
	};

    out << s;
    return out;
}
