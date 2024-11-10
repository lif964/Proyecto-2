#pragma once
#ifndef INTERFAZSCHOOL_H
#define INTERFAZSCHOOL_H
#include <iostream>
#include <string>
#include "EurekaSchool.h"
using namespace std;

class InterfazSchool {
private:
	EurekaSchool* school;
public:
	InterfazSchool();
	InterfazSchool(EurekaSchool*);
	void menuPrincipal();
	bool continuar();

	void opcion1();
	void opcion2();
	void opcion3();
	void opcion4();

	void Sub1op1();
	void Sub1op2();
	void Sub1op3();
	void Sub1op4();
	void Sub1op5();
	void Sub1op6();

	void Sub2op1();
	void Sub2op2();

	void Sub3op2();
	void Sub3op3();
	void Sub3op4();
	void Sub3op5();
	void Sub3op6();

};

#endif 
