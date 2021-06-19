#include "cEncargado.h"
using namespace std;
//#include "cCerveza.h"
#include "cLocal.h"
#include "cPuntoDeVenta.h"
#include "cBar.h"
#include "cFecha.h"


#define NMIN 3

cEncargado::cEncargado(string cuit): cEmpleado(cuit)
{
	SalarioxHora = 300;
}


void cEncargado::CalcularHorasTrabajadas()//const
{//hacer con hora y min / hacer for que recorra la lista entrada[i].gethora
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

void cEncargado::CalcularSalario()// const
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



	for (int i = 0; i < local->cervzas[i].getCA(); i++)
	{
		if (local->cervzas[i].getTipo() == tipo)
		{

			if ((local->cervzas[i].getCant() - NMIN)<0)
			{
				return (local->cervzas[i].getCant() - NMIN);
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

