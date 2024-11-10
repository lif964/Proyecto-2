#ifndef LISTAPERIODOS_H
#define LISTAPERIODOS_H
#include "Periodo.h"
#include "ListaC.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class ListaC;

class NodoPeriodo {
private:
	Periodo* periodos;
	NodoPeriodo* siguiente;
public:
	NodoPeriodo();
	NodoPeriodo(Periodo*);
	virtual ~NodoPeriodo();
	NodoPeriodo* getSiguiente();
	Periodo* getPeriodo();
	void setSiguiente(NodoPeriodo* sig);
	void setPeriodo(Periodo* p);
};

class ListaPeriodos {
private:
	NodoPeriodo* primero;
public:
	ListaPeriodos();
	virtual~ListaPeriodos();

	Periodo* getPeriodo();
	ListaC* getListaCursosXPeriodo(string);

	bool ingresarPeriodo(string, int, int, ListaC*);
	bool buscarPeriodoXNom(string);

	string informePeriodosHabilitados();
};
#endif