#ifndef GRUPO_H
#define GRUPO_H
#include <iostream>
#include <sstream>
#include <string>
#include "Horario.h"
#include "Profesor.h"
#include "ListaEst.h"
using namespace std;

class Grupo {
private:
	int numGrupo;
	int cantAlum;
	int capacidadAlum;
	Horario* horario;
	Profesor* profe;
	ListaEst* estudiantes;
public:
	Grupo(int = 0, int = 0, int = 0, Horario* = nullptr, Profesor* = nullptr, ListaEst* = nullptr);
	virtual ~Grupo();

	int getNumGrupo();
	int getCantAlum();
	int getCapAlum();
	Horario* getHorario();
	Profesor* getProfesor();
	ListaEst* getListaEsts(); 

	void setNumGrupo(int);
	void setCantAlum(int);
	void setCapAlum(int);
	void setProfesor(Profesor*);

	string toStringGrupo();
	string toStringGCompleto();
};

#endif 
