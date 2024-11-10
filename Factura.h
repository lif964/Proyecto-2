#ifndef FACTURA_H
#define FACTURA_H
#include <iostream>
#include <string>
#include "ListaC.h"
using namespace std;

const double IVA = 0.13;

class Factura {
private:
	ListaC* listaCurso;
	double subtotal;
	double total;
	double descuento;
	string tipoDescuento;
	void calcularDescuento();
public:
	Factura();
	virtual ~Factura();

	void calcularTotal();

	string factura();

};
#endif