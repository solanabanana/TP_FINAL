#pragma once
using namespace std;
typedef enum {//enum de los tipos de cervezas que vende nuestra cervecería
	RUBIA,
	NEGRA,
	ROJA,
	IPA,
	HONEY
} eCerveza;
class cCerveza
{
	int CantBarriles;//Barriles de 50L cada uno
	const eCerveza Tipo;
	
public:
	cCerveza(eCerveza tipo, int cant_barriles) : Tipo(tipo) { CantBarriles = cant_barriles; };
	~cCerveza() {};
	//Necesitamos getter y setter de CantBarriles
};

