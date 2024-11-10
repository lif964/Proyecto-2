#include "Matricula.h"

Matricula::Matricula(ListaPeriodos* p, ListaC* c) {
	periodos = p;
	cursos = c;
}
Matricula::~Matricula() {

}

bool Matricula::matricularEstudiante(string idEst, string nombrePeriodo, string nombreCurso, int numeroGrupo) {
	

	if (!) {
		cout << "Periodo no encontrado" << endl;
		return false;
	}
	
	Curso* c = cursos->getCursoXNom(nombreCurso);
	if (!c) {
		cout << "Curso no encontrado" << endl;
		return false;
	}

	Grupo* g = c->getGruposXCurso()->getGrupoXNum(numeroGrupo);
	if (!g) {
		cout << "Grupo no encontrado" << endl;
		return false;
	}

	if (g->getCapAlum() <= 0) {
		cout << "No hay cupo en el grupo" << endl;
		return false;
	}

	if (g->getListaEsts()->buscarEstudianteXCed(idEst)) {
		cout << "El estudiante ya esta matriculado en este grupo" << endl;
		return false;
	}

	//g->getListaEsts()->ingresarEst();
}
bool Matricula::desmatricularEstudiante(string idEst, string nomPeriodo, string nombreCurso, int numGrupo) {

}

string Matricula::mostrarFactura() {

}