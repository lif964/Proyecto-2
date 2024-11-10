#ifndef LISTAEST_H
#define LISTAEST_H
#include "Estudiante.h"
#include "ListaG.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class ListaG;

class NodoEst {
private:
	Estudiante* est;
	NodoEst* siguiente;
public:
	NodoEst();
	NodoEst(Estudiante*);
	virtual ~NodoEst();
	NodoEst* getSiguiente();
	Estudiante* getEstudiante();
	void setSiguiente(NodoEst* sig);
	void setEstudiante(Estudiante* estu);
};

class ListaEst {
private:
	NodoEst* primero;
public:
	ListaEst();
	virtual ~ListaEst();
	
	int cantidadDeEstudiantes(); //cuenta cuantos estudiantes hay en la lista

	bool ingresarEstudiante(string, string, string, int, string, ListaG*);
	void ingresarEst(Estudiante*);
;
	Estudiante* buscarEstudianteXCed(string);

	string toStringLEst()const; //muestra la lista de estudiantes registrados
};
#endif