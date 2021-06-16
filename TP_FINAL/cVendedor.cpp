#include "cVendedor.h"

cVendedor::cVendedor(string cuit): cEmpleado(cuit)
{
	SalarioxHora = 200;
}

void cVendedor::CalcularHorasTrabajadas()// const
{
	int horaE = Entrada.getHora();
	int horaS = Salida.getHora();
	int total = horaS - horaE;
	setHoras(total);
}

void cVendedor::CalcularSalario()// const
{
	int aux = 0;
	aux = (SalarioxHora * getHoras());
	setSalario(aux);
}
