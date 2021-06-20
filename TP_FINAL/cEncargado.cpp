#include "cEncargado.h"
using namespace std;

#include "cLocal.h"
#include "cPuntoDeVenta.h"
#include "cBar.h"
#include "cFecha.h"


#define NMIN 3

cEncargado::cEncargado(string cuit): cEmpleado(cuit,300)
{

}


void cEncargado::CalcularHorasTrabajadas()
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

void cEncargado::CalcularSalario()
{
	int aux = 0;
	int auxM = 0;
	int auxT = 0;
	auxM = (SalarioxHora * (getMin() / 60));
	aux = (SalarioxHora * getHoras());
	auxT = aux + auxM;
	setSalario(auxT);
}

int cEncargado::CalcularCantBarriles(eCerveza tipo, cLocal* local)
{/*
	cBar* bar = dynamic_cast<cBar*>(local);
	cPuntoDeVenta* venta = dynamic_cast<cPuntoDeVenta*>(local);
	if (cerveza.getCant() < NMIN)
	{
		if (bar != NULL)
		{
			bar->SolicitarCerveza();
			return true;
		}
		if (venta != NULL)
		{
			venta->SolicitarCerveza();
			return true;

		}

	}
	return false;*/



	for (int i = 0; i < local->Cervezas.getCA();i++)
	{
		if (local->Cervezas[i]->getTipo()==tipo)
		{

			if ((local->Cervezas[i]->getCantBarriles()-NMIN)<0)
			{
				return (local->Cervezas[i]->getCantBarriles() - NMIN);
			}
			else {
				return 0;//si no hay que reponer strock deveulve 0
			}
			 
		}
	}
	
	


}

int cEncargado::CantCerveza(eCerveza tipo, cLocal* local)
{
	int aux = CalcularCantBarriles(tipo, local);
	if (aux < 0)
	{
		return (aux * -2);
	}
}

void cEncargado::CalcularLitros(eCerveza tipo, cLocal* local)
{
	int aux = CantCerveza(tipo, local);
	float litros = (float)aux * 50;
	for (int i = 0; i < local->Cervezas.getCA(); i++)
	{
		if (local->Cervezas[i]->getTipo() == tipo)
		{

			local->Cervezas[i]->setLitros(litros);

		}
	}

}

