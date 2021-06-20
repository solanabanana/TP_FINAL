#include "cLocal.h"

cLocal::cLocal(cEncargado* encargado, cListaT<cCerveza> cervezas, cListaT<cEmpleado> empleados, string nombre, int numero, string ubicacion): Nombre(nombre), Numero(numero), Ubicacion(ubicacion)
{
	Empleados = empleados;
	Encargado = encargado;
	Cervezas = cervezas;
	GananciaDiaria = 0;
	LitrosVendidosDiarios = 0;
	GananciaTotal = 0;
	LitrosVendidosTotales = 0;
}

void cLocal::ActualizarCantBarriles(int cant, eCerveza tipo)
{
	for (int i = 0; i < Cervezas.getCA(); ++i)
	{
		if (Cervezas[i]->getTipo() == tipo) Cervezas[i]->setCant_Barriles(Cervezas[i]->getCantBarriles() + cant);
	}
}

float cLocal::getGananciaDiaria()
{
	return GananciaDiaria;
}

void cLocal::setGanancia(float money)
{
	GananciaTotal += money - GananciaDiaria;
	GananciaDiaria = money;
	
}

void cLocal::LiberarEncargado()
{
	Encargado = NULL;
}

float cLocal::getLitrosVendidosDiarios()
{
	return LitrosVendidosDiarios;
}

void cLocal::setLitrosVendidos(float litros)
{
	LitrosVendidosTotales += litros - LitrosVendidosDiarios;
	LitrosVendidosDiarios += litros;
}

void cLocal::FinDeJornada()
{//Se retiran todos los empleados y se deja todo okay
	//Se registra la salida de los empleados
	cFecha* salida;//VER ESTO
	salida->setHoy();
	//Si el encargado todavia esta en el local, tambien se registra su salida
	if(Encargado != NULL) Encargado->Salida.AgregarObjeto(salida);
	for (int i = 0; i < Empleados.getCA(); ++i)
	{
		Empleados[i]->Salida.AgregarObjeto(salida);
	}
	//Se retiran todos los empleados que aun esten en el local
	Empleados.QuitarTodos();
	//Se ponen los datos diarios a cero
	GananciaDiaria = 0;
	LitrosVendidosDiarios = 0;
}

ostream& operator<<(ostream& os, const cLocal* local)
{
	os << "Nombre: " << local->Nombre << endl;
	os << "Ubicacion: " << local->Ubicacion << endl;
	os << "Codigo" << local->Numero << endl;
	os << "Litros Vendidos: " << local->LitrosVendidosDiarios << endl;
	os << "Monto total: " << local->GananciaDiaria << endl;
	return os;
	
}
