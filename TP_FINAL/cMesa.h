#pragma once
using namespace std;
class cMesa
{//Cantidad de clientes en la mesa, estado de limpieza y el n�mero para identificarlas
	int CantClientes;
	bool Limpia;
	const int NumMesa;

public:
	cMesa(int num_mesa): NumMesa(num_mesa) {//Comienza la jornada, la mesa est� limpia y sin clientes
		Limpia = true;
		CantClientes = 0;
	};
	~cMesa() {};

	//Necesitamos getter y setter de Limpia y de CantClientes
};

