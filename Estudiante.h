#pragma once
#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <iostream>
#include <string>
#include <sstream>
#include "ListaG.h"
using namespace std;

class ListaG;

class Estudiante {
private:
	string nombre;
	string ID;
	string especialidad;
	int telefono;
	string email;
	ListaG* listaGrupos;
public:
	Estudiante(string = "", string = "", string = "", int = 0, string = "",ListaG* = nullptr);
	 virtual ~Estudiante();

	string getNombre();
	string getID();
	string getEspecialidad();
	int getTelefono();
	string getEmail();
	ListaG* getListaGrupos();

	void setNombre(string);
	void setID(string);
	void setEspecialidad(string);
	void setTelefono(int);
	void setEmail(string);
	void setListaGrupos(ListaG*);

	string toStringEst(); //to string solamente con nombre y id
	string toStringEstCompleto(); // to String con toda la info del estudiante
};

#endif;