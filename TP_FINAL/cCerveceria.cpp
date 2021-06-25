#include "cCerveceria.h"
#include "cBar.h"
#include"cPuntoDeVenta.h"
//constructor y destructor
cCerveceria::cCerveceria(cListaT<cLocal>& locales)
{
	Locales = new cListaT<cLocal>(locales);
	GananciaDiaria = 0;
	GananciaTotal = 0;
}

cCerveceria::~cCerveceria()
{
}

float cCerveceria::CalcularGananciaTotal(){


	for (unsigned int i = 0; i < Locales->getCA(); i++)//recorremos la lista de locales
	{
		cBar* auxb = dynamic_cast<cBar*>(Locales[0][i]);//hacemos dynamic cast para ver si es bar o no
		if (auxb != NULL)
		{
			GananciaDiaria += auxb->getGananciaDiaria();//si es un bar llamamos a su getter y actualizamos el atributo
			GananciaTotal += auxb->getGananciaDiaria();
			auxb->setGananciaDiaria(0);
			auxb->setLitrosVendidosDiarios(0);
		}
		else//si no es bar es punto de venta
		{
			cPuntoDeVenta *aux = dynamic_cast<cPuntoDeVenta*>(Locales[0][i]);//hacemos dynamic cast

			GananciaDiaria += aux->getGananciaDiaria();// llamamos a su getter y actualizamos el atributo
			GananciaTotal += aux->getGananciaDiaria();
			aux->setGananciaDiaria(0);
			aux->setLitrosVendidosDiarios(0);
		}
	}

	
	return GananciaTotal;
}

void cCerveceria::Historial()
{
	CalcularGananciaTotal();
	cout << "La ganancia del dia es " << GananciaDiaria << endl;
	cout << "La ganancia total hasta el dia de hoy es " << GananciaTotal << endl;
}

void cCerveceria::TICK()
{
	for (int i = 0; i < Locales->getCA(); i++)//recorremos la lista de locales
	{
		cBar* aux = dynamic_cast<cBar*>(Locales[0][i]);//hacemos dynamic cast
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
			cPuntoDeVenta* aux = dynamic_cast<cPuntoDeVenta*>(Locales[0][i]);//hacemos dynamic cast
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

	for (int i = 0; i < Locales->getCA(); i++)//recorremos la lista de locales
	{
		cBar* aux = dynamic_cast<cBar*>(Locales[0][i]);//hacemos sya=namic cast
		if (aux != NULL)
		{
			aux->FinDeJornada();//llamamos a finalizar jornada
		}
		else
		{
			cPuntoDeVenta* aux = dynamic_cast<cPuntoDeVenta*>(Locales[0][i]);//hacemos synamic cast
			aux->FinDeJornada();//llamamos a finalizar jornada
		}
	}
	Historial();//Imprimimos
}