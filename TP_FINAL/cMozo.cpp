#include "cMozo.h"

cMozo::cMozo(int cuit): cEmpleado(cuit)
{
	SalarioxHora = 150;
}

int cMozo::CalcularHorasTrabajadas() const
{
	return 0;
}

int cMozo::CalcularSalario() const
{
	return 0;
}

void cMozo::LimpiarMesa(int NumMesa)
{
}
