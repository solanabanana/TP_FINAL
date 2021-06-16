#pragma once
#include "cListaT.h"
class cFecha;
using namespace std;
class cEmpleado
{
protected:
	const string CUIT;
	//Consideramos que quizás sea mejor tener un doble puntero para poder acceder a las entradas y salidas de todos los días
	cListaT<cFecha> Entrada;
	cListaT<cFecha> Salida;
	int SalarioxHora;
	int Horas_trabajadas;

public:
	cEmpleado(string cuit, int salario);
	~cEmpleado() {};
	virtual void CalcularHorasTrabajadas() const = 0;
	virtual void CalcularSalario() const = 0;
	string getClave()const { return CUIT; };
	int getSalario() { return SalarioxHora; };
	void setSalario(int salario) { SalarioxHora = salario; };
	void setHoras(int hora) { Horas_trabajadas = hora; };
	int getHoras() { return Horas_trabajadas; };
	

};

