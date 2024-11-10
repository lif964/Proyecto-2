#include "Periodo.h"

Periodo::Periodo(string nom, int mesI, int mesF, ListaC* c) {
	nombre = nom;
	mesInicio = mesI;
	mesFinal = mesF;
	cursos = c;
}

string Periodo::getNombre() {
	return nombre;
}
int Periodo::getMesInicio() {
	return mesInicio;
}
int Periodo::getMesFinal() {
	return mesFinal;
}
ListaC* Periodo::getCursos() {
	return cursos;
}

void Periodo::setNombre(string nom) {
	nombre = nom;
}
void Periodo::setMesInicio(int mesI) {
	mesInicio = mesI;
}
void Periodo::setMesFinal(int mesF) {
	mesFinal = mesF;
}

string Periodo::getMes(int mes) {
	switch (mes) {
		case 1: return "Enero";
		case 2: return "Febrero";
		case 3: return "Marzo";
		case 4: return "Abril";
		case 5: return "Mayo";
		case 6: return "Junio";
		case 7: return "Julio";
		case 8: return "Agosto";
		case 9: return "Septiembre";
		case 10: return "Octubre";
		case 11: return "Noviembre";
		case 12: return "Diciembre";
	}
}
string Periodo::toStringPeriodo() {
	stringstream s;

	s << nombre + ": " + getMes(mesInicio) + " a " + getMes(mesFinal) << endl;
	s << "Cursos disponibles en este periodo: ";
	s << cursos->toStringLC() << endl;

	return s.str();
}