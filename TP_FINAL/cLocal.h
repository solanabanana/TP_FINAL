#pragma once
#include "cEncargado.h"
#include "cMozo.h"
#include "cVendedor.h"
#include <sstream>
#include <time.h>
using namespace std;
class cLocal
{
protected:
	//creo atributos y listas en protected para que los hijos puedan acceder
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
	friend class cEncargado;//friend de clase encargado

public:
	//contructor y destructor
	cLocal(cEncargado* encargado, cListaT<cCerveza> cervezas, cListaT<cEmpleado> empleados, string nombre, int numero, string ubicacion);
	~cLocal() {}
	//metodos de la clase y getters
	void ActualizarCantBarriles(int cant, eCerveza tipo);
	float getGananciaDiaria();
	void setGanancia(float money);
	void setGananciaDiaria(float money);
	void LiberarEncargado(); //Probarla, si se pierden los datos del encargado, intentar de otra forma
	float getLitrosVendidosDiarios();
	void setLitrosVendidos(float litros);
	void setLitrosVendidosDiarios(float litros);
	eCerveza ConvertirTipoCerveza(int tipo);
	void FinDeJornada();//Se retiran todos los empleados y se deja todo okay
	//metodos virtual a heredar 
	virtual void SimularCliente()  = 0;
	virtual void SolicitarCerveza(eCerveza tipo, int cant)  = 0;
	virtual void ChequearStock() = 0;
	void ImprimirEmpleados();
	//sobrecarga del operador
	friend ostream& operator<<(ostream& os, const cLocal* local);
};

