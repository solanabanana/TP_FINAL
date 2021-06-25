#include "cEmpleado.h"
#include "cFecha.h"

using namespace std;

cEmpleado::cEmpleado(string cuit, int salario): CUIT(cuit)
{//contructor 
	this->SalarioxHora = salario;
	this->Horas_trabajadas = 0;
	this->Horas_trabajadas_Minutos = 0;
	this->ocupado = false;
	Salida = new cListaT<cFecha>();
	Entrada = new cListaT<cFecha>();
}

void cEmpleado::setEntrada()
{
	cFecha* hoy = new cFecha(0, 0, 0, 0, 0);
	hoy->setHoy();
	Entrada->AgregarObjeto(hoy);
}

string cEmpleado::to_stringEmpleado()
{
	stringstream ss;

	ss << "CUIT: " << CUIT << endl;
	ss << "Salario por hora: " << to_string(SalarioxHora) << endl;
	ss << "Horas trabajadas: " << to_string(Horas_trabajadas) << endl;
	return ss.str();

}

void cEmpleado::ImprimirEmpleado()
{
	string i = to_stringEmpleado();
	cout << i;
}
