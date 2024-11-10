#include "Grupo.h"

Grupo::Grupo(int numG, int cantA, int capA, Horario* h, Profesor* p, ListaEst* ests) {
	numGrupo = numG;
	cantAlum = cantA;
	capacidadAlum = cantA;
	horario = h;
	profe = p;
	estudiantes = ests;
}
Grupo::~Grupo() {
	delete horario;
	delete profe;
	delete estudiantes;
}

int Grupo::getNumGrupo() {
	return numGrupo;
}
int Grupo::getCantAlum() {
	return cantAlum;
}
int Grupo::getCapAlum() {
	return capacidadAlum;
}
Horario* Grupo::getHorario() {
	return horario;
}
Profesor* Grupo::getProfesor() {
	return profe;
}
ListaEst* Grupo::getListaEsts() { //trae la lista de estudiantes que pertenece al grupo
	return estudiantes;
}

void Grupo::setNumGrupo(int nG) {
	numGrupo = nG;
}
void Grupo::setCantAlum(int cantA) {
	cantAlum = cantA;
}
void Grupo::setCapAlum(int capA) {
	capacidadAlum = capA;
}
void Grupo::setProfesor(Profesor* p) {
	profe = p;
}

string  Grupo::toStringGrupo() { //muestra solo info basica de cada grupo
	stringstream s;

	s << "---------INFORMACION DE EL GRUPO---------" << endl;
	s << "Numero del Grupo: " << numGrupo << endl;
	s << "Cantidad de alumnos: " << cantAlum << endl;
	s << "Capacidad de alumnos: " << capacidadAlum << endl;
	
	return s.str();
}

string Grupo::toStringGCompleto() { //muestra info completa de cada grupo 
	stringstream s;

	s << "---------INFORMACION DE EL GRUPO---------" << endl;
	s << "Numero del Grupo: " << numGrupo << endl;
	s << "Profesor: " << profe->getNombre() << endl;
	s << "Cantidad de alumnos: " << cantAlum << endl;
	s << "Capacidad de alumnos: " << capacidadAlum << endl;
	s << "Horario: ";
	s << horario->mostrarHorarios() << endl;
	s << "Lista de Estudiantes: ";
	s << estudiantes->toStringLEst() << endl;

	return s.str();
}