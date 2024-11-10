#ifndef EUREKASCHOOL_H
#define EUREKASCHOOL_H
#include <iostream>
#include "ListaPeriodos.h"
#include "ListaP.h"
#include "ListaEst.h"
using namespace std;

class EurekaSchool {
private:
	ListaPeriodos* periodos;
	ListaP* profesores;
	ListaEst* estudiantes;
public:
	EurekaSchool();
	virtual ~EurekaSchool();

	ListaPeriodos* getPeriodos();
	ListaP* getProfesores();
	ListaEst* getEstudiantes();
	
};
#endif