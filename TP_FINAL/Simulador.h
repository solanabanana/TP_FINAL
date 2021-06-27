#pragma once
#include "cCerveza.h"
#include "cEncargado.h"
#include "cBar.h"
#include "cPuntoDeVenta.h"
#include "cCerveceria.h"
void AgregarCervezas(cListaT<cCerveza>&cervezas_bar, cListaT<cCerveza>& cervezas_puntoventa) 
	{	//Nos creamos cervezas para el bar y el punto de venta y las agregamos a sus listas
		cCerveza* nueva_cerveza;
		nueva_cerveza = new cCerveza(eCerveza::RUBIA, 2, 450, 200, 300);
		cervezas_bar + nueva_cerveza;
		nueva_cerveza = new cCerveza(eCerveza::RUBIA, 0, 0, 0, 0);
		cin >> *nueva_cerveza;//Probamos la sobrecarga del operador >>
		cervezas_puntoventa + nueva_cerveza;
		nueva_cerveza = new cCerveza(eCerveza::HONEY, 3, 550, 250, 150);
		cervezas_bar + nueva_cerveza;
		nueva_cerveza = new cCerveza(eCerveza::HONEY, 1, 450, 0, 0);
		cervezas_puntoventa + nueva_cerveza;
		nueva_cerveza = new cCerveza(eCerveza::ROJA, 2, 400, 150, 100);
		cervezas_bar + nueva_cerveza;
		nueva_cerveza = new cCerveza(eCerveza::ROJA, 5, 350, 0, 0);
		cervezas_puntoventa + nueva_cerveza;
		nueva_cerveza = new cCerveza(eCerveza::NEGRA, 4, 400, 200, 100);
		cervezas_bar + nueva_cerveza;
		nueva_cerveza = new cCerveza(eCerveza::NEGRA, 7, 350, 0, 0);
		cervezas_puntoventa + nueva_cerveza;
		nueva_cerveza = new cCerveza(eCerveza::IPA, 9, 500, 250, 125);
		cervezas_bar + nueva_cerveza;
		nueva_cerveza = new cCerveza(eCerveza::IPA, 14, 450, 0, 0);
		cervezas_puntoventa + nueva_cerveza;
	};
	

	void AgregarEmpleados(cListaT<cEmpleado>&empleados_bar, cListaT<cEmpleado>& empleados_puntoventa) {
		//Creamos dos vendedores para cada local y los agregamos a las listas
		cEmpleado* nuevo_empleado;
		nuevo_empleado = new cVendedor("321");
		nuevo_empleado->setEntrada();
		empleados_bar + nuevo_empleado;
		nuevo_empleado = new cVendedor("654");
		nuevo_empleado->setEntrada();
		empleados_bar + nuevo_empleado;
		nuevo_empleado = new cVendedor("987");
		nuevo_empleado->setEntrada();
		empleados_puntoventa + nuevo_empleado;
		nuevo_empleado = new cVendedor("765");
		nuevo_empleado->setEntrada();
		empleados_puntoventa + nuevo_empleado;
		nuevo_empleado = new cMozo("564");
		nuevo_empleado->setEntrada();
		empleados_bar + nuevo_empleado;
		nuevo_empleado = new cMozo("865");
		nuevo_empleado->setEntrada();
		empleados_bar + nuevo_empleado;
	}

