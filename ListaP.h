#ifndef LISTAP_H
#define LISTAP_H
#include <iostream>
#include <sstream>
#include <string>
#include "Profesor.h"
using namespace std;

class NodoProfe {
private:
	Profesor* profes;
	NodoProfe* siguiente;
public:
	NodoProfe();
	NodoProfe(Profesor*);
	virtual ~NodoProfe();
	NodoProfe* getSiguiente();
	Profesor* getProfe();
	void setSiguiente(NodoProfe* sig);
	void setProfe(Profesor* p);
};

class ListaP {
private:
	NodoProfe* primero;
public:
	ListaP();
	virtual ~ListaP();

	bool agregarProfesor(string, string, int, string, string);
	bool buscarProfeXNom(string nombre);

	Profesor* getProfesor();
	Profesor* getProfesorXNom(string);

	string informeProfeXNom(string);

	string toStringLP()const;
};
#endif