#include "Horario.h"

Horario::Horario(string horaI, string horaF, string diaS) {
	horaInicio = horaI;
	horaFin = horaF;
	diasSemana = diaS;
}

Horario::~Horario() {

}

string Horario::mostrarHorarios()const {
	stringstream s;

	s << "Dia: " << diasSemana << endl;
	s << "Hora Inicio: " << horaInicio << endl;
	s << "Hora de Finalizacion: " << endl;

	return s.str();
}