#pragma once
#ifndef HORARIO_H
#define HORARIO_H
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Horario {
private:
	string horaInicio;
	string horaFin;
	string diasSemana;
public:
	Horario(string = "", string = "", string = "");
	virtual ~Horario();
	
	string mostrarHorarios() const;
};
#endif