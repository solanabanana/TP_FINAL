#include "cVendedor.h"


cVendedor::cVendedor(string cuit): cEmpleado(cuit,200)// pasamos los valores necesarios para el contructor padre
{
	
}

void cVendedor::CalcularHorasTrabajadas()// const
{//inicializamos variables auxiliares
	int horaE = 0;
	int horaS = 0;
	//for que recorra toda la lista y nos guarde en el auxiliar la hora de  entrada y salida del empleado
	for (int i = 0; i < Entrada.getCA(); i++)
	{
		horaE = Entrada[i]->getHoras();
	}
	for (int i = 0; i < Salida.getCA(); i++)
	{
		horaS = Salida[i]->getHoras();
	}
	//inicializamos variables auxiliares
	int MinutoE = 0;
	int MinutoS = 0;
	//for que recorra toda la lista y nos guarde en el auxiliar los minutos de entrada y salida del empleado
	for (int i = 0; i < Entrada.getCA(); i++)
	{
		MinutoE = Entrada[i]->getMinutos();
	}
	for (int i = 0; i < Salida.getCA(); i++)
	{
		MinutoS = Salida[i]->getMinutos();
	}
	//restamos la salida a la entrada para obtener el total de tiempo trabajado
	int totalM = MinutoS - MinutoE;
	int total = horaS - horaE;
	setHoras(total, totalM);//llamamos al setter de horas trabajadas
}

void cVendedor::CalcularSalario()
{
	//nos cremos variables auxiliares
	int aux = 0;
	int auxM = 0;
	int auxT = 0;
	//realizamos el salairo por hora por el tiempo trabajado
	auxM = (SalarioxHora * (getMin() / 60));//la variable minutos la dividimos por 60 para que nos quede en "horas"
	aux = (SalarioxHora * getHoras());
	auxT = aux + auxM;//sumamos ambas variables y nos cremos un total
	setSalario(auxT);//llamamos al setter de salarioint aux = 0;
	aux = (SalarioxHora * getHoras());
	setSalario(aux);
}
