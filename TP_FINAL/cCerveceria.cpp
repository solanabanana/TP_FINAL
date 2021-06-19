#include "cCerveceria.h"

cCerveceria::cCerveceria(cListaT<cLocal> locales)
{
	GananciaTotalDiaria = 0;
}

cCerveceria::~cCerveceria()
{
}

float cCerveceria::CalcularGananciaTotal()
{

	for (unsigned int i = 0; i < Locales->getCA(); i++)
	{
		GananciaTotalDiaria += Locales[i]->getGananciaDiaria();
	}

	return GananciaTotalDiaria;
}

void cCerveceria::Historial()
{
	for (int i = 0; i < Locales->getCA(); i++)
	{
		cout << Locales[i];
	}
}

void cCerveceria::TICK()
{
	for (int i = 0; i < Locales->getCA(); i++)
	{
		Locales[i]->SimularCliente();
	}
}

void cCerveceria::FinalizarJornada() {

	for (int i = 0; i < Locales->getCA(); i++)
	{
		Locales[i]->FinDeJornada();
		GananciaTotalDiaria = 0;
		Historial();
	}
}