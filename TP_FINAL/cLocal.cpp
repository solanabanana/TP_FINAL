#include "cLocal.h"

cLocal::cLocal(cEmpleado* encargado, cListaT<cCerveza> cervezas, cListaT<cEmpleado> empleados, string nombre, int numero, string ubicacion): Nombre(nombre), Numero(numero), Ubicacion(ubicacion)
{
	Empleados = empleados;
	Encargado = encargado;
	Cervezas = cervezas;
}

void cLocal::ActalizarCantBarriles()
{
}

int cLocal::CalcularGanancia()
{
	return 0;
}

void cLocal::CalcularLitrosVendidos()
{
}

void cLocal::FinDeJornada()
{
}
