#include "ListaPeriodos.h"

//Metodos de la clase Nodo Periodos
NodoPeriodo::NodoPeriodo() {
	periodos = NULL;
	siguiente = NULL;
}
NodoPeriodo::NodoPeriodo(Periodo* p) {
	periodos = p;
}
NodoPeriodo:: ~NodoPeriodo() {
	if (periodos != NULL) {
		delete periodos;
	}
}
NodoPeriodo* NodoPeriodo::getSiguiente() {
	return siguiente;
}
Periodo* NodoPeriodo::getPeriodo() {
	return periodos;
}
void NodoPeriodo::setSiguiente(NodoPeriodo* sig) {
	siguiente = sig;
}
void NodoPeriodo::setPeriodo(Periodo* p) {
	if (periodos != NULL) {
		delete periodos;
	}
	periodos = p;
}

//Metodos de la clase Lista de Periodos
ListaPeriodos::ListaPeriodos() {
	primero = NULL;
}
ListaPeriodos::~ListaPeriodos() {
	if (primero != NULL) {
		NodoPeriodo* actual = primero;
		NodoPeriodo* aux;

		while (actual != NULL) {
			aux = actual;
			actual = actual->getSiguiente();
			delete aux;
		}
	}
}

Periodo* ListaPeriodos::getPeriodo() {
	return getPeriodo();
}

ListaC* ListaPeriodos::getListaCursosXPeriodo(string nombrePeriodo) {
	NodoPeriodo* pExt = primero;

	while (pExt != NULL) {
		if (pExt->getPeriodo()->getNombre() == nombrePeriodo)
			return pExt->getPeriodo()->getCursos();
		pExt = pExt->getSiguiente();
	}

	return NULL;
}

bool ListaPeriodos::ingresarPeriodo(string nombre, int mesI, int mesF, ListaC* cursos) {
	Periodo* p = new Periodo(nombre, mesI, mesF, cursos);
	NodoPeriodo* nuevo = new NodoPeriodo(p);

	if (!buscarPeriodoXNom(nombre)) {
		return false;
	}

	if (primero == NULL) {
		primero = nuevo;
	}
	else {
		NodoPeriodo* actual = primero;

		while (actual->getSiguiente() != NULL) {
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(nuevo);
	}

	return false;
}

bool ListaPeriodos::buscarPeriodoXNom(string nombre) {
	NodoPeriodo* pExt = primero;

	while (pExt != NULL) {
		if (pExt->getPeriodo()->getNombre() == nombre)
			return true;
		pExt = pExt->getSiguiente();
	}

	return false;
}

string ListaPeriodos::informePeriodosHabilitados() {
	stringstream s;
	NodoPeriodo* pExt = primero;

	s << "Periodos habilitados para el año: " << endl;
	while (pExt != NULL) {
		s << pExt->getPeriodo()->toStringPeriodo() << endl;
		pExt = pExt->getSiguiente();
	}

	return s.str();
}