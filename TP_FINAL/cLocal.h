#pragma once
#include "cEncargado.h"
#include <sstream>
#include <time.h>
using namespace std;
class cLocal
{
protected:
	cEncargado* Encargado;
	cListaT<cCerveza> Cervezas;
	cListaT<cEmpleado> Empleados;
	float LitrosVendidosDiarios;
	float LitrosVendidosTotales;
	const string Nombre;
	const int Numero;
	const string Ubicacion;
	float GananciaDiaria;
	float GananciaTotal;
	friend class cEncargado;

public:
	cLocal(cEncargado* encargado, cListaT<cCerveza> cervezas, cListaT<cEmpleado> empleados, string nombre, int numero, string ubicacion);
	~cLocal() {}

	void ActualizarCantBarriles(int cant, eCerveza tipo);
	float getGananciaDiaria();
	void setGanancia(float money);
	void LiberarEncargado(); //Probarla, si se pierden los datos del encargado, intentar de otra forma
	float getLitrosVendidosDiarios();
	void setLitrosVendidos(float litros);
	void FinDeJornada();//Se retiran todos los empleados y se deja todo okay
	virtual void SimularCliente()  = 0;
	virtual void SolicitarCerveza(eCerveza tipo, int cant)  = 0;
	virtual void ChequearStock() = 0;
	friend ostream& operator<<(ostream& os, const cLocal* local);
};

