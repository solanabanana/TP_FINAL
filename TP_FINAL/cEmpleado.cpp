#include "cEmpleado.h"
#include "cFecha.h"

using namespace std;

cEmpleado::cEmpleado(string cuit, int salario):CUIT(cuit)
{
	this->SalarioxHora = salario;
	Horas_trabajadas = 0;
}

