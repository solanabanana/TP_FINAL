#pragma once
using namespace std;
class cMesa
{
	//Cantidad de clientes en la mesa, estado de limpieza y el número para identificarlas
	int CantClientes;
	bool Limpia;
	const int NumMesa;
	bool Ocupada;
public:
	cMesa(int num_mesa) : NumMesa(num_mesa) {//Comienza la jornada, la mesa está limpia y sin clientes
		Limpia = true;
		CantClientes = 0;
		Ocupada = false;
	};
	~cMesa() {};


	void setLimpia(bool estado) { Limpia = estado; };
	bool getLimpia() { return Limpia; };
	void setCantidadClientes(int clientes) { CantClientes = clientes; };
	int getCantClientes() { return CantClientes; }
	int getNumMesa() { return NumMesa; };
	void setEstado_(bool estado) { Ocupada = estado; };
	bool getOcupada() { return Ocupada; };


};
