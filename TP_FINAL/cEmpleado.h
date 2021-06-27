#pragma once
#include "cListaT.h"
#include <sstream>
class cFecha;

using namespace std;
class cEmpleado
{
	friend class cLocal;
protected:
	//declaramos los atributos
	string CUIT;
	cListaT<cFecha>* Entrada;
	cListaT<cFecha>* Salida;
	int SalarioxHora;
	int Horas_trabajadas;
	int Horas_trabajadas_Minutos;
	bool ocupado;

public:
	//contructor y destructor virtual 
	cEmpleado(string cuit, int salario);
	virtual ~cEmpleado() {};
	//metodos virtual para clases hijas
	virtual void CalcularHorasTrabajadas() = 0;
	virtual void CalcularSalario()  = 0;
	//getters y setters
	string getClave() { return CUIT; };
	int getSalario() { return SalarioxHora; };
	void setSalario(int salario) { SalarioxHora = salario; };
	void setHoras(int hora, int min) { Horas_trabajadas = hora; Horas_trabajadas_Minutos = min; };
	void setEntrada();
	int getHoras() { return Horas_trabajadas; };
	int getMin() { return Horas_trabajadas_Minutos; };
	bool getOcupado() { return ocupado; };
	void setOcupado(bool estado) { ocupado = estado; };
	string to_stringEmpleado();
	void ImprimirEmpleado();
	

};

