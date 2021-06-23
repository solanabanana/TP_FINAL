#include "cEncargado.h"
using namespace std;




#define NMIN 3//nos creamos un nmin para la simulacion

cEncargado::cEncargado(string cuit): cEmpleado(cuit,300)// pasamos los valores necesarios para el contructor padre
{

}


void cEncargado::CalcularHorasTrabajadas()
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

void cEncargado::CalcularSalario()
{//nos cremos variables auxiliares
	int aux = 0;
	int auxM = 0;
	int auxT = 0;
	//realizamos el salairo por hora por el tiempo trabajado
	auxM = (SalarioxHora * (getMin() / 60));//la variable minutos la dividimos por 60 para que nos quede en "horas"
	aux = (SalarioxHora * getHoras());
	auxT = aux + auxM;//sumamos ambas variables y nos cremos un total
	setSalario(auxT);//llamamos al setter de salario
}

int cEncargado::CalcularCantBarriles(eCerveza tipo, cLocal* local)
{
	//for que recorra la lista de cervezas en local
	for (int i = 0; i < local->Cervezas.getCA();i++)
	{
		if (local->Cervezas[i]->getTipo()==tipo)//si coincide con el tipo de cerveza del cual queremos calular la can de barriles
		{

			if ((local->Cervezas[i]->getCantBarriles())<NMIN)//verificamos si es menor a nmin
			{
				return (local->Cervezas[i]->getCantBarriles() - NMIN);//devovemos la cant de barriles menos nmin para saber cuanto necesitamos para reponer stock
			}
			else {
				return local->Cervezas[i]->getCantBarriles();//si no hay que reponer strock deveulve la cant de barriles que hay
			}
			 
		}
	}
	
	


}

int cEncargado::CantCerveza(eCerveza tipo, cLocal* local)
{
	int aux = CalcularCantBarriles(tipo, local);//llamamos a la fucnion para saber cuanto hay que reponer
	if (aux < 0)//si es menor a 0
	{
		return (aux * -2);//devolvemos la nueva cantidad  a solicitar
	}
	else return aux;
}

void cEncargado::CalcularLitros(eCerveza tipo, cLocal* local)
{
	int aux = CalcularCantBarriles(tipo, local);//llamamos a calcular cant cerveza para saber la cant de barriles de 
	float litros = (float)aux * 50;//creamos un aux y fuardamos la cant de litros suponiendo que por barril hay 50 litros, para la simulacion.
	for (int i = 0; i < local->Cervezas.getCA(); i++)//for que recorra la lista de cervezas
	{
		if (local->Cervezas[i]->getTipo() == tipo)//si es del tipo que queremos culcular
		{

			local->Cervezas[i]->setLitros(litros);//llamamos al setter y actualizamos la cant de litos de esa cerveza

		}
	}

}

