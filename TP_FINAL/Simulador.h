#pragma once
#include "cCerveza.h"
#include "cEncargado.h"
#include "cBar.h"
#include "cPuntoDeVenta.h"
#include "cCerveceria.h"
using namespace std;
class Simulador
{
private:
	//creo listas privadas
	cListaT<cCerveza>* cervezas_bar;
	cListaT<cCerveza>* cervezas_puntoventa;
	cListaT<cEmpleado>* empleados_bar;
	cListaT<cEmpleado>* empleados_puntoventa;
public:
	//contructor y destructor
	Simulador(cListaT<cCerveza>& cb, cListaT<cCerveza>& cp, cListaT<cEmpleado>& eb, cListaT<cEmpleado>& ep);
	~Simulador() {};
	//metodos
	void AgregarCervezas();
	void AgregarEmpleados();
};

