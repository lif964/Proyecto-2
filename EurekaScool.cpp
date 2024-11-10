#include "EurekaSchool.h"

EurekaSchool::EurekaSchool() {
	periodos = new ListaPeriodos();
	profesores = new ListaP();

	periodos->ingresarPeriodo("Periodo 1", 1, 3, new ListaC());
	periodos->ingresarPeriodo("Periodo 2", 4, 6, new ListaC());
	periodos->ingresarPeriodo("Periodo 3", 7, 9, new ListaC());
	periodos->ingresarPeriodo("Periodo 4", 10, 12, new ListaC());

}
EurekaSchool::~EurekaSchool() {
	delete periodos;
	delete profesores;
}

ListaPeriodos* EurekaSchool::getPeriodos() {
	return periodos;
}
ListaP* EurekaSchool::getProfesores() {
	return profesores;
}

ListaEst* EurekaSchool::getEstudiantes() {
	return estudiantes;
}