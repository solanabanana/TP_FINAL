#pragma once
#include "cListaT.h"
class cLocal;
using namespace std;
class cCerveceria
{//La cervecer�a tiene un atributo que es la ganancia total que ser� la suma de la ganancia de todos los locales y ademas,
	//una lista de estos mismos locales
	float GananciaTotal;
	cListaT<cLocal> Locales;

public:
	//constructor y destructor
	cCerveceria(cListaT<cLocal> locales);
	~cCerveceria();
	float CalcularGananciaTotal();//Calcula la ganancia total de nuestra cervecer�a
	void Historial();//se muestra una lista de litros vendidos y el monto total de cada local y la ganancia total de la cervecer�a
	void FinalizarJornada();//Se llama a FinalDeJornada(), CalcularGananciaTotal() y se llama a Historial()
	void TICK();//Simulacion de llegada de clientes, compra, etc
};

