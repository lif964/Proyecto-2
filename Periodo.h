#ifndef PERIODO_H
#define PERIODO_H
#include <iostream>
#include <string>
#include <sstream>
#include "ListaC.h"
using namespace std;

class ListaC;

class Periodo {
private:
	string nombre;
	int mesInicio;
	int mesFinal;
	ListaC* cursos;
public:
	Periodo(string = "", int = 0, int = 0, ListaC* = nullptr);

	string getNombre();
	int getMesInicio();
	int getMesFinal();
	ListaC* getCursos();

	void setNombre(string);
	void setMesInicio(int);
	void setMesFinal(int);

	string getMes(int);
	string toStringPeriodo();
};
#endif