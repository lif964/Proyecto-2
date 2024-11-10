#include "ListaG.h"

//metodos de la clase Nodo Grupo
NodoGrupo::NodoGrupo() {
	grupos = NULL;
	siguiente = NULL;
}
NodoGrupo::NodoGrupo(Grupo* g) {
	grupos = g;
}
NodoGrupo:: ~NodoGrupo() {
	if (grupos != NULL) {
		delete grupos;
	}
}
NodoGrupo* NodoGrupo::getSiguiente() {
	return siguiente;
}
Grupo* NodoGrupo::getGrupo() {
	return grupos;
}
void NodoGrupo::setSiguiente(NodoGrupo* sig) {
	siguiente = sig;
}
void NodoGrupo::setGrupo(Grupo* g) {
	if (grupos != NULL) {
		delete grupos;
	}
	grupos = g;
}

//metodos de la clase Lista de Grupos
ListaG::ListaG() {
	primero = NULL;
}
ListaG::~ListaG() {
	if (primero != NULL) {
		NodoGrupo* actual = primero;
		NodoGrupo* aux;

		while (actual != NULL) {
			aux = actual;
			actual = actual->getSiguiente();
			delete aux;
		}
	}
}

bool ListaG::ingresarGrupo(Grupo* g) { //ingresa un puntero de un grupo ya creado anteriormente a la lista
	NodoGrupo* nuevo = new NodoGrupo(g);

	int numG = nuevo->getGrupo()->getNumGrupo();

	if (!buscarGrupoXNum(numG)) {
		return false;
	}

	if (primero == NULL) {
		primero = nuevo;
	}
	else {
		NodoGrupo* actual = primero;

		while (actual->getSiguiente() != NULL) {
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(nuevo);
	}

	return true;
}

ListaEst* ListaG::getListaEsts() { 
	if (primero == NULL) {
		return NULL;
	}
	Grupo* grupo = primero->getGrupo();
	if (grupo == NULL) {
		return NULL;
	}

	return grupo->getListaEsts();
}

Grupo* ListaG::getGrupo() {
	return getGrupo();
}

Grupo* ListaG::getGrupoXNum(int numGrupo) {
	NodoGrupo* pExt = primero;

	while (pExt != NULL) {
		if (pExt->getGrupo()->getNumGrupo() == numGrupo) {
			return pExt->getGrupo();
		}
		pExt = pExt->getSiguiente();
	}

	return NULL;
}

bool ListaG::buscarGrupoXNum(int numG) {
	NodoGrupo* pExt = primero;

	while (pExt != NULL) {
		if (pExt->getGrupo()->getNumGrupo() == numG)
			return true;
		pExt = pExt->getSiguiente();
	}

	return false;
}

bool ListaG::asignarProfeNuevo(Profesor* p, int numGrupo) {
	NodoGrupo* pExt = primero;


	while (pExt != NULL) {
		if (getGrupo()->getNumGrupo() == numGrupo) {
			Profesor* profeAnterior = pExt->getGrupo()->getProfesor();
			if (profeAnterior != NULL) {
				delete profeAnterior;
			}
			pExt -> getGrupo()->setProfesor(p);
			return true;
		}
		pExt = pExt->getSiguiente();
	}
	return false;
}

string ListaG::toStringLG()const {
	stringstream s;

	NodoGrupo* pExt = primero;
	while (pExt != NULL) {
		s << pExt->getGrupo()->toStringGrupo();
		pExt = pExt->getSiguiente();
	}

	return s.str();
}