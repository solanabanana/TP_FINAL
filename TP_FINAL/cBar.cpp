#include "cBar.h"

cBar::cBar(cEncargado* encargado, cListaT<cCerveza> cervezas, cListaT<cEmpleado> empleados, string nombre, int numero, string ubicacion, cListaT<cMesa> mesas): cLocal(encargado, cervezas, empleados, nombre, numero, ubicacion)
{
	this->Mesas = mesas;
}

void cBar::SimularCliente() 
{//Aca simulamos que llegan de 1 a 10 clientes y que algunos pediran de 1 a 5 pintas y los demas de 1 a 4 medias pintas
	srand(time(NULL));
	int clientes = 0, pintas = 0, mediaspintas = 0, div = 0, tipo1 = 0, tipo2 = 0, mesa1 = 0, mesa2 = 0;
	tipo1 = rand() % 5;//tipo de cerveza 1
	tipo2 = rand() % 5;//tipo de cerveza 2
	clientes = 1 + rand() % 11;
	div = rand() % clientes+1;//numero entre 0 y la cantidad de clientes
	pintas = 1 + rand() % 6;
	mediaspintas = 1 + rand() % 5;
	//div sera la cantidad de clientes que van a pedir pintas y clientes - div pediran las medias pintas
	float litros1 = 0, litros2 = 0, ganancia = 0;
	litros1 = (float)div * pintas * 0.5;//Cada pinta es medio litro de cerveza
	litros2 = (float)(clientes - div) * mediaspintas * 0.25;//Cada media pinta es 1/4 litro de cerveza
	//Hacemos que nuestros dos grupos de clientes ocupen dos mesas libres y ya ponemos que estan sucias
	for (int i = 0; i < Mesas.CA; ++i)
	{
		if (Mesas[i]->getOcupado() == false)
		{
			Mesas[i]->setCantClientes(div);
			Mesas[i]->setLimpia(false);
			mesa1 = Mesas[i]->getNum();
		}
	}
	for (int i = 0; i < Mesas.CA; ++i)
	{
		if (Mesas[i]->getOcupado() == false)
		{
			Mesas[i]->setCantClientes(clientes - div);
			Mesas[i]->setLimpia(false);
			mesa2 = Mesas[i]->getNum();
		}
	}
	//Actualizamos la cantidad de litros de cada cerveza, dependiendo del tipo que se compro en cada caso y calculamos la ganancia total de la simulacion
	for (int i = 0; i < Cervezas.CA; ++i)
	{
		if (Cervezas[i]->getTipo() == tipo1)
		{
			if (Cervezas[i]->getLitros() >= litros1)

			{
				Cervezas[i]->setLitros(Cervezas[i]->getLitros() - litros1);
				ganancia += (float)div * pintas * Cervezas[i]->getPrecioPinta();
			}
			else throw new exception("No hay suficiente cerveza de este tipo");
		}
		if (Cervezas[i]->getTipo() == tipo2)
		{
			if (Cervezas[i]->getLitros() >= litros2)
			{
				Cervezas[i]->setLitros(Cervezas[i]->getLitros() - litros2);
				ganancia += (float)(clientes - div) * mediaspintas * Cervezas[i]->getPrecioMedia();
			}
			else throw new exception("No hay suficiente cerveza de este tipo");
		}
	}
	setGanancia(GananciaDiaria + ganancia);//Actualizamos las ganancias del local
	setLitrosVendidos(LitrosVendidosDiarios + litros1 + litros2);//Actualizamos la cantidad de litros que se vendieron en el local
	//Limpiamos las mesas
	cMozo* mozo;
	for (int j = 0; j < Empleados.CA; ++j)//recorremos la lista de empleados
	{
		mozo = dynamic_cast<cMozo*>(Empleados[j]);//a cada empleado hacemos el dynamic cast cMozo
		if (mozo != NULL && Empleados[j]->getOcupado() == true)//Si el empleado es un mozo y esta libre
		{//Los setOcupado() son mas simulacion que todo, porque no tienen ningun proposito
			Empleados[j]->setOcupado(true);//Lo ponemos como ocupado
			mozo->LimpiarMesa(mesa1, this);//El mozo limpia la mesa
			Empleados[j]->setOcupado(false);
			for (int k = j; k < Empleados.CA(); ++k)//No queremos que el mismo mozo limpie las dos mesas
			{
				mozo = dynamic_cast<cMozo*>(Empleados[k]);
				if (mozo != NULL && Empleados[k]->getOcupado() == true)//Si el empleado es un mozo y esta libre
				{
					Empleados[k]->setOcupado(true);//Lo ponemos como ocupado
					mozo->LimpiarMesa(mesa2, this);//El mozo limpia la mesa
					Empleados[k]->setOcupado(false);//Lo liberamos
				}
			}
		}
	}
}

void cBar::SolicitarCerveza(eCerveza tipo, int cant) 
{
	for (int i = 0; i < Cervezas.CA; ++i)
	{
		if (Cervezas[i]->getTipo() == tipo)
		{
			Cervezas[i]->setCantBarriles(cant);
			cout << "Se le informa a los mozos que se actualizo la cantidad de este tipo de cerveza" << endl;
			GananciaTotal =- cant * 6000;//Para el bar, cada barril de cerveza le sale 6000 pesos, se lo restamos a la ganancia total
			//No se lo restamos a ganancia diaria porque en ese atributo solo queremos saber cuanto se gano ese dia
		}
	}
}
void cBar::ChequearStock()
{
	bool ver;
	cLocal* aux = dynamic_cast<cLocal*>(this);
	ver = Encargado->CalcularCantBarriles(eCerveza::HONEY, aux);
	if (ver == true) SolicitarCerveza(eCerveza::HONEY,Encargado->CantCerveza(eCerveza::HONEY, aux));
	ver = Encargado->CalcularCantBarriles(eCerveza::IPA, this);
	if (ver == true) SolicitarCerveza(eCerveza::IPA, Encargado->CantCerveza(eCerveza::IPA, aux));
	ver = Encargado->CalcularCantBarriles(eCerveza::NEGRA, this);
	if (ver == true) SolicitarCerveza(eCerveza::NEGRA, Encargado->CantCerveza(eCerveza::NEGRA, aux));
	ver = Encargado->CalcularCantBarriles(eCerveza::ROJA, this);
	if (ver == true) SolicitarCerveza(eCerveza::ROJA, Encargado->CantCerveza(eCerveza::ROJA, aux));
	ver = Encargado->CalcularCantBarriles(eCerveza::RUBIA, this);
	if (ver == true) SolicitarCerveza(eCerveza::RUBIA, Encargado->CantCerveza(eCerveza::RUBIA, aux));
	cout << "El stock esta perfecto, se puede abrir el bar :)." << endl;
}
