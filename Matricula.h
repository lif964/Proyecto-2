#ifndef MATRICULA_H
#define MATRICULA_H
#include <iostream>
#include <string>
#include "ListaC.h"
#include "ListaPeriodos.h"
#include "Factura.h"
using namespace std;

class Matricula {
private:
	ListaPeriodos* periodos;
	ListaC* cursos;
	Factura factura;
public:
	Matricula(ListaPeriodos* p, ListaC* c);
	virtual ~Matricula();

	bool matricularEstudiante(string, string, string, int);
	bool desmatricularEstudiante(string, string, string, int);

	string mostrarFactura();
};
#endif