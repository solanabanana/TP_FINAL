#include "cPuntoDeVenta.h"

cPuntoDeVenta::cPuntoDeVenta(cEncargado* encargado, cListaT<cCerveza> cervezas, cListaT<cEmpleado> empleados, string nombre, int numero, string ubicacion): cLocal(encargado, cervezas, empleados, nombre, numero, ubicacion)
{
}

void cPuntoDeVenta::ChequearStock()
{//cheuqeo stock de cada tipo de cerveza y luego cuento la cantidad de litros por cerveza para verificar
	bool ver;
	cLocal* aux = dynamic_cast<cLocal*>(this);
	ver = Encargado->CalcularCantBarriles(eCerveza::HONEY, aux);
	if (ver == true) SolicitarCerveza(eCerveza::HONEY, Encargado->CantCerveza(eCerveza::HONEY, aux));
	ver = Encargado->CalcularCantBarriles(eCerveza::IPA, this);
	if (ver == true) SolicitarCerveza(eCerveza::IPA, Encargado->CantCerveza(eCerveza::IPA, aux));
	ver = Encargado->CalcularCantBarriles(eCerveza::NEGRA, this);
	if (ver == true) SolicitarCerveza(eCerveza::NEGRA, Encargado->CantCerveza(eCerveza::NEGRA, aux));
	ver = Encargado->CalcularCantBarriles(eCerveza::ROJA, this);
	if (ver == true) SolicitarCerveza(eCerveza::ROJA, Encargado->CantCerveza(eCerveza::ROJA, aux));
	ver = Encargado->CalcularCantBarriles(eCerveza::RUBIA, this);
	if (ver == true) SolicitarCerveza(eCerveza::RUBIA, Encargado->CantCerveza(eCerveza::RUBIA, aux));
	cout << "Se debe hacer un conteo de la cantidad de barriles para verificar que se haya stockeado correctamente, el encargado registrara los litros de cerveza que hay disponibles." << endl;
	Encargado->CalcularLitros(eCerveza::HONEY, aux);
	Encargado->CalcularLitros(eCerveza::IPA, aux);
	Encargado->CalcularLitros(eCerveza::NEGRA, aux);
	Encargado->CalcularLitros(eCerveza::ROJA, aux);
	Encargado->CalcularLitros(eCerveza::RUBIA, aux);
}

void cPuntoDeVenta::SimularCliente()
{
	//Aca simulamos que llegan de 1 a 10 clientes y que algunos pediran de 1 a 5 pintas y los demas de 1 a 4 medias pintas
	srand(time(NULL));
	int clientes = 0, lit = 0, mediolit = 0, div = 0, tipo1 = 0, tipo2 = 0, mesa1 = 0, mesa2 = 0;
	tipo1 = rand() % 5;//tipo de cerveza 1
	tipo2 = rand() % 5;//tipo de cerveza 2
	clientes = 1 + rand() % 11;
	div = rand() % clientes + 1;//numero entre 0 y la cantidad de clientes
	lit = 1 + rand() % 3;
	mediolit = 1 + rand() % 4;
	//div sera la cantidad de clientes que van a pedir pintas y clientes - div pediran las medias pintas
	float litros1 = 0, litros2 = 0, ganancia = 0;
	litros1 = (float)div * lit;//Cada pinta es medio litro de cerveza
	litros2 = (float)(clientes - div) * mediolit;//Cada media pinta es 1/4 litro de cerveza
	//Convertimos los tipos de cerveza de int a eCerveza
	eCerveza t1, t2;
	t1 = ConvertirTipoCerveza(tipo1);
	t2 = ConvertirTipoCerveza(tipo2);
	//Actualizamos la cantidad de litros de cada cerveza, dependiendo del tipo que se compro en cada caso y calculamos la ganancia total de la simulacion
	for (int i = 0; i < Cervezas.getCA(); ++i)
	{
		if (Cervezas[i]->getTipo() == t1)
		{
			if (Cervezas[i]->getCantLitros() >= litros1)

			{
				Cervezas[i]->setLitros(Cervezas[i]->getCantLitros() - litros1);
				ganancia += (float)div * lit * Cervezas[i]->getPrecioxLitro();
			}
			else throw new exception("No hay suficiente cerveza de este tipo");
		}
		if (Cervezas[i]->getTipo() == t2)
		{
			if (Cervezas[i]->getCantLitros() >= litros2)
			{
				Cervezas[i]->setLitros(Cervezas[i]->getCantLitros() - litros2);
				ganancia += (float)(clientes - div) * mediolit * Cervezas[i]->getPrecioxLitro()/2;
			}
			else throw new exception("No hay suficiente cerveza de este tipo");
		}
	}
	setGanancia(GananciaDiaria + ganancia);//Actualizamos las ganancias del local
	setLitrosVendidos(LitrosVendidosDiarios + litros1 + litros2);//Actualizamos la cantidad de litros que se vendieron en el local
}

void cPuntoDeVenta::SolicitarCerveza(eCerveza tipo, int cant)
{
	for (int i = 0; i < Cervezas.getCA(); ++i)
	{
		if (Cervezas[i]->getTipo() == tipo)
		{
			Cervezas[i]->setCant_Barriles(cant);
			cout << "Se le informa a la empresa que se actualizo la cantidad de este tipo de cerveza en un punto de venta" << endl;
			GananciaTotal =- cant * 3000;//Los barriles les sale la mitad a los puntos de venta ya que usualmente compran mas cantidad
		}
	}
}
