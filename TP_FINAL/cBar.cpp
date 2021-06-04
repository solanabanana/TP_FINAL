#include "cBar.h"

cBar::cBar(cEmpleado* encargado, cListaT<cCerveza> cervezas, cListaT<cEmpleado> empleados, string nombre, int numero, string ubicacion, cListaT<cMesa> mesas): cLocal(encargado, cervezas, empleados, nombre, numero, ubicacion)
{
	this->Mesas = mesas;
}

void cBar::SimularCliente() const
{
}

void cBar::SolicitarCerveza() const
{
}
