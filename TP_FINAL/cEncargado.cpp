#include "cEncargado.h"
using namespace std;
#include "cCerveza.h"
#include "cLocal.h"
#include "cPuntoDeVenta.h"
#include "cBar.h"

#define NMIN 3

cEncargado::cEncargado(string cuit): cEmpleado(cuit)
{
	SalarioxHora = 300;
}


void cEncargado::CalcularHorasTrabajadas()//const
{
	int horaE = Entrada.getHora();
	int horaS = Salida.getHora();
	int total = horaS - horaE;
	setHoras(total);
}

void cEncargado::CalcularSalario()// const
{
	int aux = 0;
	aux = (SalarioxHora * getHoras());
	setSalario(aux);
}

void cEncargado::CalcularCantBarriles(cCerveza cerveza, cLocal* local)
{

	cBar* bar = dynamic_cast<cBar*>(local);
	cPuntoDeVenta* venta = dynamic_cast<cPuntoDeVenta*>(local);
	if (cerveza.getCant() < NMIN)
	{
		if (bar != NULL)
		{
			bar->SolicitarCerveza();
		}
		if (venta != NULL)
		{
			venta->SolicitarCerveza();
		}

	}
}
