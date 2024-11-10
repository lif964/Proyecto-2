#include "ListaC.h"


//Metodo de la Clase Nodo Cursos
NodoCurso::NodoCurso() {
	curso = NULL;
	siguiente = NULL;
}
NodoCurso::NodoCurso(Curso* c) {
	curso = c;
}
NodoCurso:: ~NodoCurso() {
	if (curso != NULL)
		delete curso;
}
NodoCurso* NodoCurso::getSiguiente() { 
	return siguiente; 
}
Curso* NodoCurso::getCurso() { 
	return curso; 
}
void NodoCurso::setSiguiente(NodoCurso* sig) { 
	siguiente = sig; 
}
void NodoCurso::setCurso(Curso* c){ 
	if (curso != NULL) {
		delete curso;
	}
	curso = c;
}

//Metodos de la Clase Lista Cursos
ListaC::ListaC() {
	primero = NULL;
}
ListaC::~ListaC() {
	if (primero != NULL) {
		NodoCurso* actual = primero;
		NodoCurso* aux;

		while (actual != NULL) {
			aux = actual;
			actual = actual->getSiguiente();
			delete aux;
		}
	}
}

NodoCurso* ListaC::getPrimero() {
	return primero;
}

int ListaC::cantidadDeCursos() {
	NodoCurso* pExt = primero;
	int cont = 0;
	while (pExt != NULL) {
		cont++;
		pExt = pExt->getSiguiente();
	}
	return cont;
}

double ListaC::getSubtotal()const {
	double subtotal = 0;

	NodoCurso* pExt = primero;

	while (pExt) {
		subtotal += pExt->getCurso()->getPrecio();
		pExt = pExt->getSiguiente();
	}

	return subtotal;
}

bool ListaC::ingresarCurso(string nombre, string ID, int horas, int precio, bool estado, ListaG* grupos) {
	Curso* c = new Curso(nombre, ID, horas, precio, estado, grupos);
	NodoCurso* nuevo = new NodoCurso(c);

	if (!buscarCursoXNom(nombre)) {
		return false;
	}

	if (primero == NULL) {
		primero = nuevo;
	}
	else {
		NodoCurso* actual = primero;

		while (actual->getSiguiente() != NULL) {
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(nuevo);
	}

	return true;
}

bool ListaC::ingresarGrupo(int numGrupo, int cantA, int capA, Horario* h, Profesor* p, string nombreCurso) {
	Curso* cursoSeleccionado = getCursoXNom(nombreCurso);

	Grupo* nuevoGrupo = new Grupo(numGrupo, cantA, capA, h, p);
	
	if (cursoSeleccionado->getGruposXCurso()->ingresarGrupo(nuevoGrupo)) {
		return true;
	}

	return false;
}

Curso* ListaC::getCursoXNom(string nom) { //busca un curso en especifico por el nombre y retorna el curso si lo encontro
	NodoCurso* pExt = primero;

	while (pExt != NULL) {
		if (pExt->getCurso()->getNombre() == nom) {
			return pExt->getCurso();
		}
		pExt = pExt->getSiguiente();
	}

	return NULL;
}

ListaG* ListaC::getListaGruposXCurso(string nombreCurso) { //trae la lista de grupos de un curso en especifico por el nombre
	if (buscarCursoXNom(nombreCurso)) {
		return getCursoXNom(nombreCurso)->getGruposXCurso();
	}

	return NULL;
}

bool ListaC::buscarCursoXNom(string nom) { //busca un curso en especifico por el nombre y determina si esta o no esta en la lista
	NodoCurso* pExt = primero;

	while (pExt != NULL) {
		if (pExt->getCurso()->getNombre() == nom)
			return true;
		pExt = pExt->getSiguiente();
	}

	return false;
}

string ListaC::toStringLC()const {
	stringstream s;

	NodoCurso* pExt = primero;
	while (pExt != NULL) {
		s << pExt->getCurso()->toStringCursoCompleto();
		pExt = pExt->getSiguiente();
	}

	return s.str();
}