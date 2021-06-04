#include "cVendedor.h"

cVendedor::cVendedor(int cuit): cEmpleado(cuit)
{
	SalarioxHora = 200;
}

int cVendedor::CalcularHorasTrabajadas() const
{
	return 0;
}

int cVendedor::CalcularSalario() const
{
	return 0;
}
