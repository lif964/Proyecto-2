#ifndef LISTAG_H
#define LISTAG_H
#include "Grupo.h"
#include "Profesor.h"
#include "ListaEst.h"
using namespace std;

class ListaEst;
class Profesor;

class NodoGrupo {
private:
	Grupo* grupos;
	NodoGrupo* siguiente;
public:
	NodoGrupo();
	NodoGrupo(Grupo*);
	virtual ~NodoGrupo();
	NodoGrupo* getSiguiente();
	Grupo* getGrupo();
	void setSiguiente(NodoGrupo* sig);
	void setGrupo(Grupo* g);
};

class ListaG {
private:
	NodoGrupo* primero;
public:
	ListaG();
	virtual ~ListaG();

	bool ingresarGrupo(Grupo*); 

	Grupo* getGrupoXNum(int);

	Grupo* getGrupo();
	ListaEst* getListaEsts();

	bool buscarGrupoXNum(int);

	bool asignarProfeNuevo(Profesor*, int);

	string toStringLG()const;
};
#endif