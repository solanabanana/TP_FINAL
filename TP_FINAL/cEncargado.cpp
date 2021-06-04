#include "cEncargado.h"

cEncargado::cEncargado(string cuit): cEmpleado(cuit)
{
	SalarioxHora = 300;
}

int cEncargado::CalcularHorasTrabajadas() const
{
	return 0;
}

int cEncargado::CalcularSalario() const
{
	return 0;
}

int cEncargado::CalcularCantBarriles()
{
	return 0;
}
