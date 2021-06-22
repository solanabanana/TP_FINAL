#include "cCerveceria.h"
#include "cBar.h"
#include"cPuntoDeVenta.h"
cCerveceria::cCerveceria(cListaT<cLocal> locales)
{
	GananciaDiaria = 0;
	GananciaTotal = 0;
}

cCerveceria::~cCerveceria()
{
}

float cCerveceria::CalcularGananciaTotal(){


	for (unsigned int i = 0; i < Locales.getCA(); i++)
	{
		cBar* aux = dynamic_cast<cBar*>(Locales);
		if (aux != NULL)
		{
			GananciaDiaria += aux->getGananciaDiaria();
			GananciaTotal += GananciaDiaria;
		}
		else
		{
			cPuntoDeVenta *aux = dynamic_cast<cPuntoDeVenta*>(Locales);

			GananciaDiaria += aux->getGananciaDiaria();
			GananciaTotal += GananciaDiaria;
		}
	}

	
	return GananciaTotal;
}

void cCerveceria::Historial()
{
	for (int i = 0; i < Locales.getCA(); i++)
	{
		cout << Locales[i]<<endl;
	}
}

void cCerveceria::TICK()
{
	for (int i = 0; i < Locales.getCA(); i++)
	{
		cBar* aux = dynamic_cast<cBar*>(Locales);
		if (aux != NULL)
		{
			try {
				aux->SimularCliente();
			}
			catch (exception* ex)
			{
				cout << ex->what() << endl;
				delete ex;
			}
		}
		else
		{
			cPuntoDeVenta* aux = dynamic_cast<cPuntoDeVenta*>(Locales);
			try {
				aux->SimularCliente();
			}
			catch(exception*ex){

				cout << ex->what() << endl;
				delete ex;
			}
		}
	}
}

void cCerveceria::FinalizarJornada() {

	for (int i = 0; i < Locales.getCA(); i++)
	{
		cBar* aux = dynamic_cast<cBar*>(Locales);
		if (aux != NULL)
		{
			aux->FinDeJornada();
			GananciaTotal = 0;
			Historial();
		}
		else
		{
			cPuntoDeVenta* aux = dynamic_cast<cPuntoDeVenta*>(Locales);
			aux->FinDeJornada();
			GananciaTotal = 0;
			Historial();
		}
	}
}