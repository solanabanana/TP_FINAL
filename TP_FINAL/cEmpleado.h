#pragma once
#include "cListaT.h"
class cFecha;
using namespace std;
class cEmpleado
{
protected:
	const int CUIT;
	//Consideramos que quiz�s sea mejor tener un doble puntero para poder acceder a las entradas y salidas de todos los d�as
	cListaT<cFecha> Entrada;
	cListaT<cFecha> Salida;
	int SalarioxHora;

public:
	cEmpleado(int cuit);
	~cEmpleado() {};
	virtual int CalcularHorasTrabajadas() const = 0;
	virtual int CalcularSalario() const = 0;
};

