#pragma once
#include <time.h>
using namespace std;
class cFecha
{
	int Minutos;
	int Horas;
	int Dia;
	int Mes;
	int Anio;
public:
	cFecha(int Min, int Hor, int Dia, int Mes, int Anio)
	{
		Minutos = Min;
		Horas = Hor;
		Dia = Dia;
		Mes = Mes;
		Anio = Anio;
	};             //Hay que ver si necesitamos definir las fechas cuadno las creamos o si tenemos que crearlas sin nada
	~cFecha() {};

	void setActualizar(int dia, int mes, int anio);
	void setHoy();
	string to_stringFecha();
	void ImprimirFecha();

	int getMinutos() { return Minutos; };
	int getHoras() { return Horas; };
	int getDia() { return Dia; };
	int getMes() { return Mes; };
	int getAnio() { return Anio; };

};

void cFecha::setActualizar(int dia, int mes, int anio)
{
	Dia = dia;
	Mes = mes;
	Anio = anio;
}
void cFecha::setHoy()
{
	time_t t = time(0);
	tm* now = localtime(&t);
	setActualizar(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
}
inline string cFecha::to_stringFecha()
{
	string s = to_string(Dia) + "/" + to_string(Mes) + "/" + to_string(Anio);
	return s;
}
void cFecha::ImprimirFecha()
{
	string s = to_stringFecha();
	cout << s << endl;
}
