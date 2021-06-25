#pragma once
using namespace std;
typedef enum {//enum de los tipos de cervezas que vende nuestra cervecerķa
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
	cCerveza(eCerveza tipo, int cant_barriles, float PrecioxLitro, float Precio_Pinta, float Precio_media_Pinta) : Tipo(tipo)
	{
		CantBarriles = cant_barriles;
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
	void setCant_Barriles(int num) { CantBarriles = num; CalcLitros(); }
	int getCantBarriles() { return CantBarriles; };
	int getCantLitros() { return CantLitros; };
	float getPrecioxLitro() { return PrecioxLitro; };
	float getPrecio_Pinta() { return Precio_Pinta; };
	float getprecio_medi_pinta() { return Precio_media_Pinta; };
	eCerveza getTipo() { return Tipo; };

};