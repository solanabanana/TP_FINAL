#include "cPuntoDeVenta.h"

cPuntoDeVenta::cPuntoDeVenta(cEmpleado* encargado, cListaT<cCerveza> cervezas, cListaT<cEmpleado> empleados, string nombre, int numero, string ubicacion): cLocal(encargado, cervezas, empleados, nombre, numero, ubicacion)
{
}

void cPuntoDeVenta::SimularCliente() const
{
}

void cPuntoDeVenta::SolicitarCerveza() const
{
}
