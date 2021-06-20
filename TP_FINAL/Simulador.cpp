#include "Simulador.h"

Simulador::Simulador(cListaT<cCerveza>* cb, cListaT<cCerveza>* cp, cListaT<cEmpleado>* eb, cListaT<cEmpleado>* ep)
{
	cervezas_bar = cb;
	cervezas_puntoventa = cp;
	empleados_bar = eb;
	empleados_puntoventa = ep;
}

void Simulador::AgregarCervezas()
{	//Nos creamos cervezas para el bar y el punto de venta y las agregamos a sus listas
	cCerveza* nueva_cerveza;
	nueva_cerveza = new cCerveza(eCerveza::RUBIA, 5);
	*cervezas_bar + nueva_cerveza;
	nueva_cerveza = new cCerveza(eCerveza::RUBIA, 10);
	*cervezas_puntoventa + nueva_cerveza;
	nueva_cerveza = new cCerveza(eCerveza::HONEY, 5);
	*cervezas_bar + nueva_cerveza;
	nueva_cerveza = new cCerveza(eCerveza::HONEY, 7);
	*cervezas_puntoventa + nueva_cerveza;
	nueva_cerveza = new cCerveza(eCerveza::ROJA, 7);
	*cervezas_bar + nueva_cerveza;
	nueva_cerveza = new cCerveza(eCerveza::ROJA, 9);
	*cervezas_puntoventa + nueva_cerveza;
	nueva_cerveza = new cCerveza(eCerveza::NEGRA, 4);
	*cervezas_bar + nueva_cerveza;
	nueva_cerveza = new cCerveza(eCerveza::NEGRA, 7);
	*cervezas_puntoventa + nueva_cerveza;
	nueva_cerveza = new cCerveza(eCerveza::IPA, 9);
	*cervezas_bar + nueva_cerveza;
	nueva_cerveza = new cCerveza(eCerveza::IPA, 14);
	*cervezas_puntoventa + nueva_cerveza;
	//nueva_cerveza = NULL; ??
	//delete nueva_cerveza ??
}

void Simulador::AgregarEmpleados()
{//Creamos dos vendedores para cada local y los agregamos a las listas
	cEmpleado* nuevo_empleado;
	nuevo_empleado = new cVendedor("321");
	*empleados_bar + nuevo_empleado;
	nuevo_empleado = new cVendedor("654");
	*empleados_bar + nuevo_empleado;
	nuevo_empleado = new cVendedor("987");
	*empleados_puntoventa + nuevo_empleado;
	nuevo_empleado = new cVendedor("765");
	*empleados_puntoventa + nuevo_empleado;
	nuevo_empleado = new cMozo("564");
	*empleados_bar + nuevo_empleado;
	nuevo_empleado = new cMozo("865");
	*empleados_bar + nuevo_empleado;
	//nuevo_empleado = NULL; ??
    //delete nuevo_empleado ??
}