#include "cLocal.h"
#include "cFecha.h"
//construcro por parametros
int cLocal::counter = 0;
cLocal::cLocal(cEncargado* encargado, cListaT<cCerveza> cervezas, cListaT<cEmpleado> empleados, string nombre, int numero, string ubicacion): Nombre(nombre), Numero(numero), Ubicacion(ubicacion)
{
	counter++;
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
	for (int i = 0; i < Cervezas.getCA(); ++i)//recorro la lista de cervezas
	{
		if (Cervezas[i]->getTipo() == tipo) Cervezas[i]->setCant_Barriles(Cervezas[i]->getCantBarriles() + cant);//si son del tipo que quiero actualizar llamo al setter
	}
}

float cLocal::getGananciaDiaria()
{
	return GananciaDiaria;
}

void cLocal::setGanancia(float money)
{
	GananciaTotal += money - GananciaDiaria;
	GananciaDiaria += money;
	
}

void cLocal::setGananciaDiaria(float money)
{
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

void cLocal::setLitrosVendidosDiarios(float litros)
{
	LitrosVendidosDiarios = litros;
}

eCerveza cLocal::ConvertirTipoCerveza(int tipo)
{
	eCerveza Tipo;
	if (tipo == 0)Tipo = RUBIA;
	if (tipo == 1)Tipo = NEGRA;
	if (tipo == 2)Tipo = ROJA;
	if (tipo == 3)Tipo = IPA;
	if (tipo == 4)Tipo = HONEY;
	return Tipo;
}

void cLocal::FinDeJornada()
{//Se retiran todos los empleados y se deja todo okay
	//Se registra la salida de los empleados
	cFecha* salida = new cFecha(0, 0, 0, 0, 0);
	salida->setHoy();
	//Si el encargado todavia esta en el local, tambien se registra su salida
	if(Encargado != NULL) Encargado->Salida->AgregarObjeto(salida);
	Encargado->CalcularHorasTrabajadas();
	for (int i = 0; i < Empleados.getCA(); ++i)
	{
		Empleados[i]->Salida->AgregarObjeto(salida);
		cMozo* auxm = dynamic_cast<cMozo*>(Empleados[i]);
		if (auxm != NULL) auxm->CalcularHorasTrabajadas();
		else
		{
			cVendedor* auxv = dynamic_cast<cVendedor*>(Empleados[i]);
			auxv->CalcularHorasTrabajadas();
		}
	}
	//Se retiran todos los empleados que aun esten en el local
	Empleados.QuitarTodos();
	//Se ponen los datos diarios a cero
	//Imprimimos los datos del local.
	cout << this;
}
int cLocal::getCounter()
{
	return counter;
}
void cLocal::ImprimirEmpleados()
{
	cout << this;
	cout << "Encargado: " << endl;
	Encargado->ImprimirEmpleado();
	for (int i = 0; i < Empleados.getCA(); ++i)
	{
		Empleados[i]->ImprimirEmpleado();
	}
}
//sobrecarga del operador
ostream& operator<<(ostream& os, const cLocal* local)
{
	os << "Nombre: " << local->Nombre << endl;
	os << "Ubicacion: " << local->Ubicacion << endl;
	os << "Codigo: " << local->Numero << endl;
	os << "Litros Vendidos: " << local->LitrosVendidosDiarios << endl;
	os << "Monto total: " << local->GananciaDiaria << endl << endl;
	return os;
	
}
