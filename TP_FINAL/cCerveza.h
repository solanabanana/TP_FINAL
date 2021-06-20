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
	int CantBarriles;  //Barriles de 50L cada uno
	float PrecioxLitro;
	float Precio_Pinta;
	float Precio_media_Pinta;
	int CantLitros;
	eCerveza Tipo;

public:
	cCerveza(eCerveza tipo, int cant_barriles, float PrecioxLitro, float Precio_Pinta, float Precio_media_Pinta) : Tipo(tipo)
	{
		CantBarriles = cant_barriles;
		this->PrecioxLitro = PrecioxLitro;
		this->Precio_Pinta = Precio_Pinta;
		this->Precio_media_Pinta = Precio_media_Pinta;
		CantLitros = 0;
	};
	~cCerveza() {};

	void setCant_Barriles(int num) { CantBarriles = num; }
	void CalcLitros() { CantLitros = CantBarriles * 50; }
	void setLitros(float Litros) { CantLitros = Litros; }
	int getCantBarriles() { return CantBarriles; };
	int getCantLitros() { return CantLitros; };
	int getPrecioxLitro() { return PrecioxLitro; };
	int getPrecio_Pinta() { return Precio_Pinta; };
	int getprecio_medi_pinta() { return Precio_media_Pinta; };
	eCerveza getTipo() { return Tipo; };

