#include "cMozo.h"
#include "cBar.h"
#include "cFecha.h"

cMozo::cMozo(string cuit): cEmpleado(cuit)
{
	SalarioxHora = 150;
}

void cMozo::CalcularHorasTrabajadas()// const
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

void cMozo::CalcularSalario()// const
{
	int aux = 0;
	aux = (SalarioxHora * getHoras());
	setSalario(aux);
}

void cMozo::LimpiarMesa(int NumMesa, cBar* bar)
{
	for (int i = 0; i < bar->Mesas.getCA(); i++)
	{
		if (bar->Mesas[i].getNum() == NumMesa)
		{
			bar->Mesas[i]->setEstado(true);
		}
	}
}

