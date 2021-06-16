#include "cMozo.h"

cMozo::cMozo(string cuit): cEmpleado(cuit)
{
	SalarioxHora = 150;
}

void cMozo::CalcularHorasTrabajadas()// const
{
	int horaE = Entrada.getHora();
	int horaS = Salida.getHora();
	int total = horaS - horaE;
	setHoras(total);
}

void cMozo::CalcularSalario()// const
{
	int aux = 0;
	aux = (SalarioxHora * getHoras());
	setSalario(aux);
}

void cMozo::LimpiarMesa(int NumMesa)
{
	//si hay una lista de mesas que busque la mesa que esta sucia y llame al setter para limpiarla
	//que reciba una mesa no el numero y que la limpie
}
