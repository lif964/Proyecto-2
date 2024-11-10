#include <iostream>
#include <string>
#include <sstream>
#include "InterfazSchool.h"
using namespace std;

InterfazSchool::InterfazSchool() {
	school = NULL;
}

InterfazSchool::InterfazSchool(EurekaSchool* s) {
	school = new EurekaSchool();
}

void InterfazSchool::menuPrincipal() {
	int opcion = -1;

	while (opcion != 0) {

		cout << "---------- EUREKA SCHOOL ----------" << endl;
		cout << endl;
		cout << "------------MENU----------------" << endl;
		cout << "1- Submenu Administracion" << endl;
		cout << "2- Submenu Matricula" << endl;
		cout << "3- Submenu Busquedas e Informes" << endl;
		cout << "4- Guardar los Datos en Archivos " << endl;
		cout << "0- Salir" << endl;
		cout << "Seleccione una opcion: " << endl;
		cout << "----------------------------------" << endl;
		cin >> opcion;


		switch (opcion) {
		case 1: {
			system("cls");
			opcion1();
		}break;
		case 2:
			system("cls");
			opcion2();
			break;
		case 3:
			system("cls");
			opcion3();
			break;
		case 4:
			system("cls");
			opcion4();
			break;
		case 0:
			cout << "Saliendo del programa" << endl;
			break;
		default:
			cout << "Opcion incorrecta  ";
			break;
		}

		system("cls");
	}
	exit(0);
	system("cls");
}

bool InterfazSchool::continuar() {
		char opcion;
		cout << "Desea continuar? s:si | n:no:" << endl;
		cin >> opcion;
		return opcion == 's';
}

void InterfazSchool::opcion1() {
	int op = 1;

	while (op != 0) {
		cout << "---------- Submenu Administracion ----------" << endl;
		cout << "1- Ingresar Profesor" << endl;
		cout << "2- Ingresar Estudiante" << endl;
		cout << "3- Ingresar Bloque o Periodo" << endl;
		cout << "4- Ingresar Curso" << endl;
		cout << "5- Ingresar Grupo" << endl;
		cout << "6- Asignar Profesor a Grupo" << endl;
		cout << "0- Regresar al Menu Principal" << endl;

		switch (op) {
		case 1: {
			system("cls");
			Sub1op1();
		}break;
		case 2: {
			system("cls");
			Sub1op2();
		}break;
		case 3: {
			system("cls");
			Sub1op3();
		}break;
		case 4: {
			system("cls");
			Sub1op4();
		}break;
		case 5: {
			system("cls");
			Sub1op5();
		}break;
		case 6: {
			system("cls");
			Sub1op6();
		}break;
		case 0: {
			cout << "Saliendo del programa" << endl;
		}break;
		default:
			cout << "Opcion incorrecta  ";
			break;
		}
	}
	
	
}

void InterfazSchool::Sub1op1() {
	string nombreProfe, ID, email, gradoAcademico;
	int tel;

	cout << "----DATOS PARA INGRESAR UN PROFESOR----" << endl;

	cout << "Ingrese el nombre del profesor: " << endl;
	cin >> nombreProfe;

	cout << "Ingrese el numero de identificacion del profesor: " << endl;
	cin >> ID;

	cout << "Ingrese el numero de telefono de el profesor: " << endl;
	cin >> tel;

	cout << "Ingrese el grado academico: " << endl;
	cin >> gradoAcademico;

	cout << "Ingrese el email: " << endl;
	cin >> email;

	if(school->getProfesores()->agregarProfesor(nombreProfe, ID, tel, email, gradoAcademico)){
		cout<<"Profesor registrado exitosamente"<<endl;
	}else{
		cout<<"Ocurrio un error, no se logro ingresar el profesor"<<endl;
	}
}

void InterfazSchool::Sub1op2() {
	string nombreEst, id, especialidad, email;
	int tel;

	cout << "----DATOS PARA INGRESAR UN ESTUDIANTE----" << endl;

	cout << "Ingrese el nombre del Estudiante:" << endl;
	cin >> nombreEst;

	cout << "Ingrese el numero de indentificacion:" << endl;
	cin >> id;

	cout << "Ingrese la especialidad del estudiante:" << endl;
	cin >> especialidad;

	cout << "Ingrese el email:" << endl;
	cin >> email;

	cout << "Ingrese el numero del telefono:" << endl;
	cin >> tel;

	ListaG* grupos = new ListaG();

	
	if(school->getEstudiantes()->ingresarEstudiante(nombreEst, id, especialidad, tel, email, grupos)){
		cout<<"Estudiante ingresado correctamente"<<endl;
	}else{
		cout<<"Ocurrio un error, no se logro ingresar el Estudiante"<<endl;
	}
	delete grupos;
}

void InterfazSchool::Sub1op3() {
	int mesInicio, mesFinal;
	string nombre;
	ListaC* cursos = new ListaC();

	cout << "----DATOS PARA CREAR UN PERIODO----" << endl;

	cout << "Ingrese le nombre del periodo (Ej: Periodo 1): " << endl;
	cin >> nombre;

	cout << "Ingrese el mes de Inicio (1: Enero - 12: Dic) para el bloque/periodo el cual desea ingresar: " << endl;
	cin >> mesInicio;

	cout << "Ingrese el mes de Finalizacion (1: Enero - 12: Dic)para el bloque/periodo el cual desea ingresar: " << endl;
	cin >> mesFinal;

	if (school->getPeriodos()->ingresarPeriodo(nombre, mesInicio, mesFinal, cursos)){
		cout << "Se creo el periodo correctamente" << endl;
	}
	else {
		cout << "Ocurrio un error, no se logro crear el periodo" << endl;
	}
	delete cursos;
}

void InterfazSchool::Sub1op4() {
	string nombre, id, nombrePeriodo;
	int hora, precio;
	bool estado;

	cout << "----DATOS PARA INGRESAR UN CURSO----" << endl;

	cout << school->getPeriodos()->informePeriodosHabilitados() << endl;

	cout << "Ingrese el nombre del Periodo en el cual desea ingresar el curso: " << endl;
	cin >> nombrePeriodo;

	cout << "Ingrese el nombre del curso: " << endl;
	cin >> nombre;

	cout << "Ingrese el ID del curso: " << endl;
	cin >> id;

	cout << "Ingrese la duracion en horas del curso: " << endl;
	cin >> hora;
	if (hora <= 0) {
		cout << "Ocurrio un error se ingreso un numero de horas incorrecto" << endl;
		return;
	}

	cout << "Ingrese el precio del curso: " << endl;
	cin >> precio;

	cout << "Ingrese el estado del curso (1: disponible || 0: no disponible): " << endl;
	cin >> estado;

	ListaG* grupos = new ListaG();

	ListaC* listaCursos = school->getPeriodos()->getListaCursosXPeriodo(nombrePeriodo);
	if (school->getPeriodos()->buscarPeriodoXNom(nombrePeriodo)) {
		if (listaCursos->ingresarCurso(nombre, id, hora, precio, estado, grupos)) {
			cout << "Curso ingresado correctamente" << endl;
		}
		else {
			cout << "Ocurrio un error no se logro ingresar el Curso" << endl;
		}
		delete grupos;
		delete listaCursos;
	}
}

void InterfazSchool::Sub1op5() {
	int numGrupo, capacidad, opProfe, tel; 
	string diaSemana,horaInicio, horaFinal, nomProfe, ID, email, gradoAcademico, nombreCurso, nombrePeriodo;

	cout << "----DATOS PARA INGRESAR UN GRUPO----" << endl;

	cout << school->getPeriodos()->informePeriodosHabilitados() << endl;

	cout << "Ingrese el nombre del Periodo en el cual desea ingresar el curso: " << endl;
	cin >> nombrePeriodo;

	if (!school->getPeriodos()->buscarPeriodoXNom(nombrePeriodo)) {
		cout << "No se encontro un periodo con ese nombre" << endl;
		return;
	}

	ListaC* listaCursos = school->getPeriodos()->getListaCursosXPeriodo(nombrePeriodo);

	cout << listaCursos->toStringLC() << endl;

	cout << "Ingrese el nombre del curso para el cual desea crear un grupo: " << endl;
	cin >> nombreCurso;

	Curso* cursoElegido = listaCursos->getCursoXNom(nombreCurso);

	if (listaCursos->buscarCursoXNom(nombreCurso)) {

		cout << "Curso elegido: ";
		cout << cursoElegido->toStringCursoCompleto() << endl;

		cout << "Ingrese el numero del grupo a crear: " << endl;
		cin >> numGrupo;

		cout << "Ingrese la capacidad de estudiantes para el grupo: " << endl;
		cin >> capacidad;

		cout << "Ingrese la hora de Inicio de el grupo: " << endl;
		cin >> horaInicio;

		cout << "Ingrese la hora de Finalizacion de el grupo: " << endl;
		cin >> horaFinal;

		cout << "Ingrese los dias de la semana (separados por coma: Lunes, Martes): " << endl;
		cin.ignore();
		getline(cin, diaSemana);

		cout << "Ingrese 1: si desea asignar un profesor existente a su grupo por ingresar o 0: para ingresar un profesor nuevo: " << endl;
		cin >> opProfe;

		if (opProfe == 1) {
			cout << "Lista de profesores registrados: " << endl;
			cout << school->getProfesores()->toStringLP();
			cout << "Ingrese el nombre del profesor que desea asignar a su grupo: " << endl;
			cin >> nomProfe;

			Profesor* p = school->getProfesores()->getProfesorXNom(nomProfe);
			Horario* h = new Horario(horaInicio, horaFinal, diaSemana);

			if (listaCursos->ingresarGrupo(numGrupo, capacidad, 0, h, p, nombreCurso)) {
				cout << "Grupo ingresado satisfactoriamente" << endl;
			}
			else {
				cout << "Ocurrio un error. No se logro ingresar el grupo" << endl;
			}
		}
		else {
			cout << "Ingrese los datos del profesor que desea registrar para el nuevo grupo: " << endl;

			cout << "Ingrese el nombre del profesor: " << endl;
			cin >> nomProfe;

			cout << "Ingrese el numero de identificacion del profesor: " << endl;
			cin >> ID;

			cout << "Ingrese el numero de telefono de el profesor: " << endl;
			cin >> tel;

			cout << "Ingrese el grado academico: " << endl;
			cin >> gradoAcademico;

			cout << "Ingrese el email: " << endl;
			cin >> email;

			Profesor* p = new Profesor(nomProfe, ID, tel, email, gradoAcademico);
			Horario* h = new Horario(horaInicio, horaFinal, diaSemana);

			if (listaCursos->ingresarGrupo(numGrupo, capacidad, 0, h, p, nombreCurso)) {
				cout << "Grupo ingresado satisfactoriamente" << endl;
			}
			else {
				cout << "Ocurrio un error. No se logro ingresar el grupo" << endl;
				delete p;
				delete h;
			}
		}
	}
	else {
		cout << "No se encontro un Curso con ese nombre" << endl;
	}
	delete listaCursos;
	delete cursoElegido;
}

void InterfazSchool::Sub1op6() {
	int numGrupo;
	string nombreProfe, nombreCurso, nombrePeriodo;

	cout << "----DATOS PARA ASIGNAR UN PROFESOR A UN GRUPO----" << endl;

	cout << school->getPeriodos()->informePeriodosHabilitados() << endl;

	cout << "Ingrese el nombre del periodo: " << endl;

	cout << school->getPeriodos()->getListaCursosXPeriodo(nombrePeriodo)<<endl;

	cout << "Ingrese el nombre del curso al cual pertenece el grupo que se le va a asignar el nuevo profesor: " << endl;
	cin >> nombreCurso;

	ListaG* listaGrupos = school->getPeriodos()->getListaCursosXPeriodo(nombrePeriodo)->getListaGruposXCurso(nombreCurso);

	cout << listaGrupos->toStringLG() << endl;

	cout << "Ingrese el numero del grupo al cual desea asignar el profesor: " << endl;
	cin >> numGrupo;


	if(listaGrupos->buscarGrupoXNum(numGrupo)){

		cout << "El grupo seleccionado es: ";
		Grupo* grupoSeleccionado = listaGrupos->getGrupoXNum(numGrupo);
		cout << grupoSeleccionado->toStringGCompleto();
		cout << endl;

		cout << school->getProfesores()->toStringLP() << endl;

		cout << "Ahora ingrese el nombre del profesor al que desea asignar a este grupo: " << endl;
		cin >> nombreProfe;
		
		Profesor* p = school->getProfesores()->getProfesorXNom(nombreProfe);
		if (p != NULL) {
			if (listaGrupos->asignarProfeNuevo(p, numGrupo)) {
				cout << "Se asigno el nuevo profesor con exito" << endl;
				cout << "Grupo actualizado: ";
				cout << listaGrupos->getGrupoXNum(numGrupo) << endl;

			}
			else {
				cout << "Ocurrio un error no se logro asignar el profesor" << endl;
				delete listaGrupos;
				delete p;
				delete grupoSeleccionado;
			}
		}
		else {
			cout << "No se encontro un profesor con ese nombre" << endl;
			delete p;
		}
	}else{
		cout<<"No se logro encontrar un grupo con ese numero"<<endl;
	}
	delete listaGrupos;
}

void  InterfazSchool::opcion2() {
	int op = 1;

	while (op != 0) {
		cout << "---------- Submenu Matricula ----------" << endl;
		cout << "1- Matricular Estudiante" << endl;
		cout << "2- Desmatricular Estudiante" << endl;
		cout << "0- Regresar al Menu Principal" << endl;

		switch (op) {
		case 1:{
			system("cls");
			Sub2op1();
		}break;
		case 2: {
			system("cls");
			Sub2op2();
		}break;
		case 0: {
			cout << "Saliendo del programa" << endl;
		}break;
		default:
			cout << "Opcion incorrecta  ";
			break;
		}
	}
}

void InterfazSchool::Sub2op1() {
	string idEst, nomPeriodo, nomCurso;
	int numGrupo;

	cout << "MATRICULA DE ESTUDIANTE" << endl;

	cout << "Ingrese el numero de identificacion del estudiante que desea matricular: " << endl;
	cin >> idEst;

	cout << "Ingrese el nombre del periodo en el cual desea matricular: " << endl;
	cin >> nomPeriodo;

	cout << "Ingrese el nombre del curso en el que desea matricular: " << endl;
	cin >> nomCurso;

	cout << "Ingrese el numero del grupo en el que desea matricular: " << endl;
	cin >> numGrupo;
}

void InterfazSchool::Sub2op2() {
	cout << "DESMATRICULA DE ESTUDIANTE" << endl;
}

void  InterfazSchool::opcion3() {
	int op = 1;


	while (op != 0) {
		cout << "---------- Busqueda e Informes ----------" << endl;
		cout << "1- Informe Profesores Registrados" << endl;
		cout << "2- Informe Estudiantes Registrados" << endl;
		cout << "3- Informe Curso Matriculado por un Estudiante" << endl;
		cout << "4- Informe Profesor Especifico" << endl;
		cout << "5- Informe Periodos Habilitados para el año" << endl;
		cout << "6- Informe Grupo Especifico" << endl;
		cout << "0- Regresar al Menu Principal" << endl;

		switch (op) {
		case 1: {
			system("cls");
			school->getProfesores()->toStringLP();
		}break;
		case 2: {
			system("cls");
			Sub3op2();
		}break;
		case 3: {
			system("cls");
			Sub3op3();
		}break;
		case 4: {
			system("cls");
			Sub3op4();
		}break;
		case 5: {
			system("cls");
			Sub3op5();
		}break;
		case 6: {
			system("cls");
			Sub3op6();
		}break;
		case 0: {
			cout << "Saliendo del programa" << endl;
		}break;
		default:
			cout << "Opcion incorrecta  ";
			break;
		}
	}
}

void InterfazSchool::Sub3op2() {

}

void InterfazSchool::Sub3op3() {
	string IDEst;

	cout << "INFORME DE CURSO MATRICULADO POR ESTUDIANTE" << endl;

	cout << "Ingrese el numero de identificacion del estudiante: " << endl;
	cin >> IDEst;


}

void InterfazSchool::Sub3op4() {
	string nombreProfe;

	cout << "INFORME DE UN PROFESOR ESPECIFICO" << endl;

	cout << school->getProfesores()->toStringLP() << endl;

	cout << "Ingrese el nombre del profesor el cual desea ver el informe: " << endl;
	cin >> nombreProfe;

	if (school->getProfesores()->buscarProfeXNom(nombreProfe)) {
		cout<<school->getProfesores()->informeProfeXNom(nombreProfe)<<endl;
	}
	else {
		cout << "No se encontro ningun profesor con ese nombre" << endl;
	}
}

void InterfazSchool::Sub3op5() {
	cout << school->getPeriodos()->informePeriodosHabilitados() << endl;
}

void InterfazSchool::Sub3op6() {
	string nombreCurso, nomPeriodo, nomCurso;
	int numGrupo;

	cout << "INFORME POR GRUPO ESPECIFICO" << endl;

	cout << school->getPeriodos()->informePeriodosHabilitados() << endl;

	cout << "Ingrese el nombre del periodo: " << endl;
	cin >> nomPeriodo;

	if (school->getPeriodos()->buscarPeriodoXNom(nomPeriodo)) {
		ListaC* listaCursos = school->getPeriodos()->getListaCursosXPeriodo(nomPeriodo);
		cout << listaCursos->toStringLC() << endl;

		cout << "Ingrese el nombre del curso del cual desea ver el grupo: " << endl;
		cin >> nombreCurso;

		Curso* cursoSeleccionado = listaCursos->getCursoXNom(nombreCurso);

		if (cursoSeleccionado != NULL) {
			cout << cursoSeleccionado->getTostringGrupos() << endl;

			cout << "Ingrese el numero del grupo del cual desea el informe: " << endl;
			cin >> numGrupo;

			Grupo* grupoSeleccionado = cursoSeleccionado->getGruposXCurso()->getGrupoXNum(numGrupo);
			if (grupoSeleccionado != NULL) {
				cout << grupoSeleccionado->toStringGCompleto() << endl;
			}
			else {
				cout << "No se encontro un grupo con ese numero" << endl;
				delete cursoSeleccionado;
			}
		}
	}
}


void  InterfazSchool::opcion4() {
	cout << "---------- Guardar Archivos ----------" << endl;
}