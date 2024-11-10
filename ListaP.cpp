#include "ListaP.h"

//Metodos de la clase Nodo Profesores
NodoProfe::NodoProfe() {
	profes = NULL;
	siguiente = NULL;
}
NodoProfe::NodoProfe(Profesor* p) {
	profes = p;
}
NodoProfe:: ~NodoProfe() {
	if (profes != NULL) {
		delete profes;
	}
}
NodoProfe* NodoProfe::getSiguiente() {
	return siguiente;
}
Profesor* NodoProfe::getProfe() {
	return profes;
}
void NodoProfe::setSiguiente(NodoProfe* sig) {
	siguiente = sig;
}
void NodoProfe::setProfe(Profesor* p) {
	if (profes != NULL) {
		delete profes;
	}
	profes = p;
}

//Metodos de la clase Lista de Profesores
ListaP::ListaP() {
	primero = NULL;
}
ListaP:: ~ListaP() {
	if (primero != NULL) {
		NodoProfe* actual = primero;
		NodoProfe* aux;

		while (actual != NULL) {
			aux = actual;
			actual = actual->getSiguiente();
			delete aux;
		}
	}
}

bool ListaP::agregarProfesor(string nombre, string id, int tel, string email, string gradoAcademico) {
	Profesor* p = new Profesor(nombre, id, tel, email, gradoAcademico);
	NodoProfe* nuevo = new NodoProfe(p);

	if (!buscarProfeXNom(nombre)) {
		return false;
	}

	if (primero == NULL) {
		primero = nuevo;
	}
	else {
		NodoProfe* actual = primero;

		while (actual->getSiguiente() != NULL) {
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(nuevo);
	}

	return false;
}

bool ListaP::buscarProfeXNom(string nombre) {
	NodoProfe* pExt = primero;

	while (pExt != NULL) {
		if (pExt->getProfe()->getNombre() == nombre)
			return true;
		pExt = pExt->getSiguiente();
	}

	return false;
}

Profesor* ListaP::getProfesor() {
	return primero->getProfe();
}

Profesor* ListaP::getProfesorXNom(string nom) {
	NodoProfe* pExt = primero;

	while (pExt != NULL) {
		if (pExt->getProfe()->getNombre() == nom)
			return pExt->getProfe();
		pExt = pExt->getSiguiente();
	}

	return NULL;
}

string ListaP::informeProfeXNom(string nom) {

	Profesor* profeSeleccionado = getProfesorXNom(nom);

	return profeSeleccionado->toStringPCompleto();
}

string ListaP::toStringLP()const {
	stringstream s;

	NodoProfe* pExt = primero;
	while (pExt != NULL) {
		s << pExt->getProfe()->toStringP();
		pExt = pExt->getSiguiente();
	}

	return s.str();
}
