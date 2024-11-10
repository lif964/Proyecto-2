#include "Profesor.h"

Profesor::Profesor(string nom, string Id, int tel, string e, string gradoA, ListaC* c) {
	nombre = nom;
	id = Id;
	telefono = tel;
	email = e;
	gradoAcademico = gradoA;
	cursos = c;
}
Profesor:: ~Profesor() {
	delete cursos;
}

string Profesor::getNombre() {
	return nombre;
}
string Profesor::getID() {
	return id;
}
string Profesor::getEmail() {
	return email;
}
int Profesor::getTelefono() {
	return telefono;
}
string Profesor::getGradoAcademico() {
	return gradoAcademico;
}
ListaC* Profesor::getListaCursos() {
	return cursos;
}

void Profesor::setNombre(string nom) {
	nombre = nom;
}
void Profesor::setID(string Id) {
	id = Id;
}
void Profesor::setEmail(string e) {
	email = e;
}
void Profesor::setTelefono(int tel) {
	telefono = tel;
}
void Profesor::setGradoAcademico(string gradoA) {
	gradoAcademico = gradoA;
}

string Profesor::toStringP() {
	stringstream s;

	s << "Nombre: " << nombre <<endl;
	s << "Numero de Identificacion: "<< id <<endl;

	return s.str();
}

string Profesor::toStringPCompleto() {
	stringstream s;

	s << "Nombre: " << nombre << endl;
	s << "Numero de Identificacion: " << id << endl;
	s << "Grado Academico: " << gradoAcademico << endl;
	s << "Email: " << email << endl;
	s << "Telefono: " << telefono << endl;
	s << "Cursos asignados: ";
	s << cursos->toStringLC() << endl;

	return s.str();
}