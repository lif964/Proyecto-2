#ifndef CURSO_H
#define CURSO_H
#include <iostream>
#include <string>
#include <sstream>
#include "ListaG.h"
using namespace std;

class ListaG;

class Curso {
private:
	string nombre;
	string ID;
	int horas;
	int precio;
	bool estado; //disponible == true  no disponible == false
	ListaG* grupos;
public:
	Curso(string = "", string = "", int = 0, int = 0, bool = false,ListaG* = nullptr);
	virtual ~Curso();

	string getNombre();
	string getId();
	int getHoras();
	int getPrecio();
	bool getEstado();
	ListaG* getGruposXCurso();
	string getGrupoXNum(int); //busca un grupo con ese numero de grupo en especifico
	string getTostringGrupos(); //retorna el to string de la lista de grupos de el curso

	void setNombre(string);
	void setId(string);
	void setHoras(int);
	void setPrecio(int);
	void setEstado(bool);

	string toStringCursoCompleto(); //muestra toda la info del curso
	string toStringCurso(); //muestra solamente nombre y id
};

#endif