#include "cCerveceria.h"
#include "cBar.h"
#include"cPuntoDeVenta.h"
//constructor y destructor
cCerveceria::cCerveceria(cListaT<cLocal> locales)
{
	GananciaDiaria = 0;
	GananciaTotal = 0;
}

cCerveceria::~cCerveceria()
{
}

float cCerveceria::CalcularGananciaTotal(){


	for (unsigned int i = 0; i < Locales.getCA(); i++)//recorremos la lista de locales
	{
		cBar* aux = dynamic_cast<cBar*>(Locales[i]);//hacemos dynamic cast para ver si es bar o no
		if (aux != NULL)
		{
			GananciaDiaria += aux->getGananciaDiaria();//si es un bar llamamos a su getter y actualizamos el atributo
			GananciaTotal += GananciaDiaria;
		}
		else//si no es bar es punto de venta
		{
			cPuntoDeVenta *aux = dynamic_cast<cPuntoDeVenta*>(Locales[i]);//hacemos dynamic cast

			GananciaDiaria += aux->getGananciaDiaria();// llamamos a su getter y actualizamos el atributo
			GananciaTotal += GananciaDiaria;
		}
	}

	
	return GananciaTotal;
}

void cCerveceria::Historial()
{//imrimirmos la lista de locales
	for (int i = 0; i < Locales.getCA(); i++)
	{
		cout << Locales[i]<<endl;
	}
}

void cCerveceria::TICK()
{
	for (int i = 0; i < Locales.getCA(); i++)//recorremos la lista de locales
	{
		cBar* aux = dynamic_cast<cBar*>(Locales[i]);//hacemos dynamic cast
		if (aux != NULL)
		{
			try {
				aux->SimularCliente();//llamamos a simular cliente
			}
			catch (exception* ex)
			{
				cout << ex->what() << endl;
				delete ex;
			}
		}
		else
		{
			cPuntoDeVenta* aux = dynamic_cast<cPuntoDeVenta*>(Locales[i]);//hacemos dynamic cast
			try {
				aux->SimularCliente();//llamamos a simular cliente
			}
			catch(exception*ex){

				cout << ex->what() << endl;
				delete ex;
			}
		}
	}
}

void cCerveceria::FinalizarJornada() {

	for (int i = 0; i < Locales.getCA(); i++)//recorremos la lista de locales
	{
		cBar* aux = dynamic_cast<cBar*>(Locales[i]);//hacemos sya=namic cast
		if (aux != NULL)
		{
			aux->FinDeJornada();//llamamos a finalizar jornada
			GananciaTotal = 0;//setteamos el atributo
			Historial();//imprimimos
		}
		else
		{
			cPuntoDeVenta* aux = dynamic_cast<cPuntoDeVenta*>(Locales[i]);//hacemos synamic cast
			aux->FinDeJornada();//llamamos a finalizar jornada
			GananciaTotal = 0;
			Historial();//imrimimos 
		}
	}
}