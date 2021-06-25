#pragma once
#include <time.h>
#include <string>
#include <iostream>
using namespace std;
class cFecha
{//creo mis atributos
	int Minutos;
	int Horas;
	int Dia;
	int Mes;
	int Anio;
public:
	//contructor y destructor
	cFecha(int Min, int Hor, int dia, int mes, int anio);
	~cFecha() {};
	//setters
	void setActualizar(int minutos, int horas, int dia, int mes, int anio);
	void setHoy();
	//to string e imprimir
	string to_stringFecha();
	void ImprimirFecha();
	//getters
	int getMinutos() { return Minutos; };
	int getHoras() { return Horas; };
	int getDia() { return Dia; };
	int getMes() { return Mes; };
	int getAnio() { return Anio; };

};


