#include "cEmpleado.h"
#include "cFecha.h"

using namespace std;

cEmpleado::cEmpleado(string cuit, int salario): CUIT(cuit)
{//contructor 
	this->SalarioxHora = salario;
	this->Horas_trabajadas = 0;
	this->Horas_trabajadas_Minutos = 0;
	this->ocupado = false;
}
