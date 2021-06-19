#pragma once
#include "cListaT.h"
class cFecha;

using namespace std;
class cEmpleado
{
	friend class cLocal;
protected:
	const string CUIT;
	//Consideramos que quizás sea mejor tener un doble puntero para poder acceder a las entradas y salidas de todos los días
	cListaT<cFecha> Entrada;
	cListaT<cFecha> Salida;
	int SalarioxHora;
	int Horas_trabajadas;
	int Horas_trabajadas_Minutos;
	bool ocupado;

public:
	cEmpleado(string cuit, int salario);
	~cEmpleado() {};
	virtual void CalcularHorasTrabajadas() const = 0;
	virtual void CalcularSalario() const = 0;
	string getClave()const { return CUIT; };
	int getSalario() { return SalarioxHora; };
	void setSalario(int salario) { SalarioxHora = salario; };
	void setHoras(int hora, int min) { Horas_trabajadas = hora; Horas_trabajadas_Minutos = min; };
	int getHoras() { return Horas_trabajadas; };
	int getMin() { return Horas_trabajadas_Minutos; };
	bool getOcupado() { return ocupado; };
	void setOcupado(bool estado) { ocupado = estado; };
	

};

