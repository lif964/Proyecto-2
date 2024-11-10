#include "Curso.h"

Curso::Curso(string nom, string id, int h, int p, bool e, ListaG* g) 
	:nombre(nom), ID(id), horas(h), precio(p), estado(e), grupos(g){
}
Curso:: ~Curso() {
	delete grupos;
}

string Curso::getNombre() {return nombre;}
string Curso::getId() { return ID; }
int Curso::getHoras() { return horas; }
int Curso::getPrecio() { return precio; }
bool Curso::getEstado() { return estado; }

ListaG* Curso::getGruposXCurso() { //  retorna los grupos en la lista de grupos del curso
	return grupos;
}

string Curso::getGrupoXNum(int numGrupo) { //trae de la lista de grupos del curso un grupo en especifico con su numero y muestra su info completa
	Grupo* g = grupos->getGrupoXNum(numGrupo);
	if (grupos->buscarGrupoXNum(numGrupo)) {
		return g->toStringGCompleto();
	}
	return "Grupo no encontrado";
}

void Curso::setNombre(string nom) { nombre = nom; }
void Curso::setId(string id) { ID = id; }
void Curso::setHoras(int h) { horas = h; }
void Curso::setPrecio(int p) { precio = p; }
void Curso::setEstado(bool e) { estado = e; }

string Curso::toStringCursoCompleto() {
	stringstream s;

	s << "----------INFORMACION DEL CURSO----------" << endl;
	s << "Nombre: " << nombre << endl;
	s << "ID: " << ID << endl;
	s << "Hora: " << horas << endl;
	s << "Precio: " << precio << endl;
	s << "Estado (1:disponible | 0:no disponible): " << estado << endl;
	s << "Grupos de este curso: ";
	s << grupos->toStringLG() << endl;

	return s.str();
}

string Curso::getTostringGrupos() {//retorna el to string de la lista de grupos de el curso
	return grupos->toStringLG();
}

string Curso::toStringCurso() { 
	stringstream s;

	s << "----------INFORMACION DEL CURSO----------" << endl;
	s << "Nombre: " << nombre << endl;
	s << "ID: " << ID << endl;

	return s.str();
}