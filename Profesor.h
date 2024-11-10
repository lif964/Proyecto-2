#ifndef PROFESOR_H
#define PROFESOR_H
#include <iostream>
#include <string>
#include <sstream>
#include "ListaC.h"
using namespace std;

class Profesor {
private:
	string nombre;
	string id;
	int telefono;
	string email;
	string gradoAcademico;
	ListaC* cursos;
public:
	Profesor(string = "", string = "", int = 0, string = "", string = "", ListaC* = nullptr);
	virtual ~Profesor();

	string getNombre();
	string getID();
	string getEmail();
	int getTelefono();
	string getGradoAcademico();
	ListaC* getListaCursos();

	void setNombre(string);
	void setID(string);
	void setEmail(string);
	void setTelefono(int);
	void setGradoAcademico(string);


	string toStringP();
	string toStringPCompleto();
};
#endif