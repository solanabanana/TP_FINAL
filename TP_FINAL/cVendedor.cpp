#include "cVendedor.h"
#include "cFecha.h"

cVendedor::cVendedor(string cuit): cEmpleado(cuit,200)
{
	
}

void cVendedor::CalcularHorasTrabajadas()// const
{
	int horaE = 0;
	int horaS = 0;
	for (int i = 0; i < Entrada.getCA(); i++)
	{
		horaE = Entrada[i]->getHoras();
		
	}
	for (int i = 0; i < Salida.getCA(); i++)
	{
		horaS = Salida[i]->getHoras();
	}
	int MinutoE = 0;
	int MinutoS = 0;

	for (int i = 0; i < Entrada.getCA(); i++)
	{
		MinutoE = Entrada[i]->getMinutos();
	}
	for (int i = 0; i < Salida.getCA(); i++)
	{
		MinutoS = Salida[i]->getMinutos();
	}
	int totalM = MinutoS - MinutoE;
	int total = horaS - horaE;
	setHoras(total, totalM);
}

void cVendedor::CalcularSalario()// const
{
	int aux = 0;
	aux = (SalarioxHora * getHoras());
	setSalario(aux);
}
