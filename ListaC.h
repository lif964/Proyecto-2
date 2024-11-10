#ifndef LISTAC_H
#define LISTAC_H
#include "Curso.h"
#include "Profesor.h"
#include "ListaG.h"
#include "Horario.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Curso;
class ListaG;
class Profesor;
class Horario;

class NodoCurso {
private:
	Curso* curso;
	NodoCurso* siguiente;
public:
	NodoCurso();
	NodoCurso(Curso*);
	virtual ~NodoCurso();
	NodoCurso* getSiguiente();
	Curso* getCurso();
	void setSiguiente(NodoCurso* sig);
	void setCurso(Curso* c);
};

class ListaC {
private:
	NodoCurso* primero;
public:
	ListaC();
	virtual ~ListaC();

	NodoCurso* getPrimero();

	int cantidadDeCursos();
	double getSubtotal()const;

	bool ingresarCurso(string nombre, string ID, int horas, int precio, bool estado, ListaG* grupos);
	bool ingresarGrupo(int, int, int, Horario*, Profesor*, string);
	bool buscarCursoXNom(string);

	Curso* getCursoXNom(string);
	ListaG* getListaGruposXCurso(string); //trae la lista de grupos de un curso en especifico por el nombre

	string toStringLC()const; // muestra la lista de cursos con su info completa
};
#endif