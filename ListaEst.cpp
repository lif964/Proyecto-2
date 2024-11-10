#include "ListaEst.h"


//Metodos de clase Nodo Estudiante
NodoEst::NodoEst() {
	est = NULL;
	siguiente = NULL;
}
NodoEst::NodoEst(Estudiante* e) {
	est = e;
}
NodoEst::~NodoEst() {
	if (est != NULL) {
		delete est;
	}
}
NodoEst* NodoEst::getSiguiente() {
	return siguiente;
}
Estudiante* NodoEst::getEstudiante() {
	return est;
}
void NodoEst::setSiguiente(NodoEst* sig) {
	siguiente = sig;
}
void NodoEst::setEstudiante(Estudiante* estu) {
	if (est != NULL) {
		delete est;
	}
	est = estu;
}


// Metodos de la Clase Lista Estudiantes
ListaEst::ListaEst() {
	primero = NULL;
}

ListaEst::~ListaEst() {
	NodoEst* actual = primero;
	NodoEst* aux;

	while (actual != NULL) {
		aux = actual;
		actual = actual->getSiguiente();
		delete aux;
	}
}

int ListaEst::cantidadDeEstudiantes() { 
	NodoEst* pExt = primero;
	int cont = 0;
	while (pExt != NULL) {
		cont++;
		pExt = pExt->getSiguiente();
	}
	return cont;
}

bool ListaEst::ingresarEstudiante(string nom, string id, string esp, int tel, string email, ListaG* listaG) {
	Estudiante* e = new Estudiante(nom, id, esp, tel, email, listaG);
	NodoEst* nuevo = new NodoEst(e);

	if (buscarEstudianteXCed(id) != NULL) {
		cout << "El estudiante ya esta registrado" << endl;
		delete nuevo;
		return false;
	}

	if (primero == NULL) {
		primero = nuevo;
	}
	else {
		NodoEst* actual = primero;

		while (actual->getSiguiente() != NULL) {
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(nuevo);
	}

	return true;
}

void ListaEst::ingresarEst(Estudiante* e) {
	NodoEst* nuevo = new NodoEst(e);

	if (primero == NULL) {
		primero = nuevo;
	}
	else {
		NodoEst* actual = primero;

		while (actual->getSiguiente() != NULL) {
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(nuevo);
	}
}

Estudiante* ListaEst::buscarEstudianteXCed(string ced) {
	NodoEst* pExt = primero;

	while (pExt != NULL) {
		if (pExt->getEstudiante()->getID() == ced)
			return pExt->getEstudiante();
		pExt = pExt->getSiguiente();
	}

	return NULL;
}

string ListaEst::toStringLEst() const {
	stringstream s;

	NodoEst* pExt = primero; 
	while (pExt != NULL) {
		s << pExt->getEstudiante()->toStringEst();
		pExt = pExt->getSiguiente();
	}

	return s.str();
}