#pragma once
#include "cEmpleado.h"
#include "cCerveza.h"
#include "cListaT.h"
using namespace std;
class cLocal
{
	int DineroGanado;
	cEmpleado* Encargado;
	cListaT<cCerveza> Cervezas;
	cListaT<cEmpleado> Empleados;
	int LitrosVendidos;
	const string Nombre;
	const int Numero;
	const string Ubicacion;
	int Ganancia;

public:
	cLocal(cEmpleado* encargado, cListaT<cCerveza> cervezas, cListaT<cEmpleado> empleados, string nombre, int numero, string ubicacion);
	~cLocal() {}

	void ActalizarCantBarriles();
	int CalcularGanancia();
	void CalcularLitrosVendidos();
	void FinDeJornada();//Se retiran todos los empleados y se deja todo okay
	virtual void SimularCliente() const = 0;
	virtual void SolicitarCerveza() const = 0;
};

