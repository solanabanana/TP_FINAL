#include "cFecha.h"
//contructor por parametros
cFecha::cFecha(int Min, int Hor, int dia, int mes, int anio)
{
	Minutos = Min;
	Horas = Hor;
	Dia = dia;
	Mes = mes;
	Anio = anio;
}
//implemento los setters
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
//implementacion del to string e imprimir
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