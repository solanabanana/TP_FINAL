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
{//creo los atributos
	int CantBarriles;  //Barriles de 8L cada uno
	float PrecioxLitro;
	float Precio_Pinta;
	float Precio_media_Pinta;
	int CantLitros;
	eCerveza Tipo;

public://constructor y destructor
	cCerveza(eCerveza tipo, int cant_barriles, float PrecioxLitro, float Precio_Pinta, float Precio_media_Pinta)
	{
		CantBarriles = cant_barriles;
		this->Tipo = tipo;
		this->PrecioxLitro = PrecioxLitro;
		this->Precio_Pinta = Precio_Pinta;
		this->Precio_media_Pinta = Precio_media_Pinta;
		CantLitros = cant_barriles * 8;
	};
	~cCerveza() {};
	//metodo
	void CalcLitros() { CantLitros = CantBarriles * 8; }
	//setters y getters
	void setLitros(float Litros) { CantLitros = Litros; }
	void setTipo(eCerveza tipo) { Tipo = tipo; }
	void setCant_Barriles(int num) { CantBarriles = num; CalcLitros(); }
	int getCantBarriles() { return CantBarriles; };
	int getCantLitros() { return CantLitros; };
	float getPrecioxLitro() { return PrecioxLitro; };
	float getPrecio_Pinta() { return Precio_Pinta; };
	float getprecio_medi_pinta() { return Precio_media_Pinta; };
	eCerveza getTipo() { return Tipo; };
	friend istream& operator>>(istream& is, cCerveza& C)
	{
		string tipo;
		cout << "Ingrese la cantidad de barriles: ";
		is >> C.CantBarriles;
		cout << endl << "Ingrese el precio por litro: ";
		is >> C.PrecioxLitro;
		cout << endl << "Ingrese el precio de la pinta: ";
		is >> C.Precio_Pinta;
		cout << endl << "Ingrese el precio de la media pinta: ";
		is >> C.Precio_media_Pinta;
		cout << endl << "Ingrese el tipo de cerveza: ";
		cin >> tipo;
		if (tipo == "rubia") C.setTipo(eCerveza::RUBIA);
		if (tipo == "roja") C.setTipo(eCerveza::ROJA);
		if (tipo == "honey") C.setTipo(eCerveza::HONEY);
		if (tipo == "negra") C.setTipo(eCerveza::NEGRA);
		if (tipo == "ipa") C.setTipo(eCerveza::IPA);
		return is;
	}
};