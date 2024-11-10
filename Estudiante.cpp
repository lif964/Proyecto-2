#include "Estudiante.h"

Estudiante::Estudiante(string nom, string id, string esp, int tel, string e, ListaG* lG) {
	nombre = nom;
	ID = id;
	especialidad = esp;
	telefono = tel;
	email = e;
	listaGrupos = lG;
}
Estudiante::~Estudiante() {
}

string Estudiante::getNombre() { return nombre; }
string Estudiante::getID() { return ID; }
string Estudiante::getEspecialidad() { return especialidad; }
int Estudiante::getTelefono() { return telefono; }
string Estudiante::getEmail() { return email; }
ListaG* Estudiante::getListaGrupos() { return listaGrupos; }

void Estudiante::setNombre(string nom) {
	nombre = nom;
}
void Estudiante::setID(string id) {
	ID = id;
}
void Estudiante::setEspecialidad(string esp) {
	especialidad = esp;
}
void Estudiante::setTelefono(int tel) {
	telefono = tel;
}
void Estudiante::setEmail(string e) {
	email = e;
}
void Estudiante::setListaGrupos(ListaG* lG) {
	listaGrupos = lG;
}

string Estudiante::toStringEst() {
	stringstream s;

	s << "----- DATOS DEL ESTUDIANTE ------" << endl;
	s << "Nombre: " << nombre << endl;
	s << "ID: " << ID << endl;
	
	return s.str();
}

string Estudiante::toStringEstCompleto() {
	stringstream s;

	s << "----- DATOS DEL ESTUDIANTE ------" << endl;
	s << "Nombre: " << nombre << endl;
	s << "ID: " << ID << endl;
	s << "Especialidad: " << especialidad << endl;
	s << "Telefono: " << endl;
	s << "Email: " << endl;

	return s.str();
}