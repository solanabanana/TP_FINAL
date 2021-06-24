#include "Simulador.h"
//constructor
Simulador::Simulador(cListaT<cCerveza>& cb, cListaT<cCerveza>& cp, cListaT<cEmpleado>& eb, cListaT<cEmpleado>& ep)
{
	cervezas_bar = new cListaT<cCerveza>(cb);
	cervezas_puntoventa = new cListaT<cCerveza>(cp);
	empleados_bar = new cListaT<cEmpleado>(eb);
	empleados_puntoventa = new cListaT<cEmpleado>(ep);;
}

void Simulador::AgregarCervezas()
{	//Nos creamos cervezas para el bar y el punto de venta y las agregamos a sus listas
	cCerveza* nueva_cerveza;
	nueva_cerveza = new cCerveza(eCerveza::RUBIA, 5, 500, 200, 100);
	*cervezas_bar + nueva_cerveza;
	nueva_cerveza = new cCerveza(eCerveza::RUBIA, 10, 450, 0, 0);
	*cervezas_puntoventa + nueva_cerveza;
	nueva_cerveza = new cCerveza(eCerveza::HONEY, 5, 550, 250, 150);
	*cervezas_bar + nueva_cerveza;
	nueva_cerveza = new cCerveza(eCerveza::HONEY, 7, 450, 0, 0);
	*cervezas_puntoventa + nueva_cerveza;
	nueva_cerveza = new cCerveza(eCerveza::ROJA, 7, 400, 150, 100);
	*cervezas_bar + nueva_cerveza;
	nueva_cerveza = new cCerveza(eCerveza::ROJA, 9, 350, 0, 0);
	*cervezas_puntoventa + nueva_cerveza;
	nueva_cerveza = new cCerveza(eCerveza::NEGRA, 4, 400, 200, 100);
	*cervezas_bar + nueva_cerveza;
	nueva_cerveza = new cCerveza(eCerveza::NEGRA, 7, 350, 0, 0);
	*cervezas_puntoventa + nueva_cerveza;
	nueva_cerveza = new cCerveza(eCerveza::IPA, 9, 500, 250, 125);
	*cervezas_bar + nueva_cerveza;
	nueva_cerveza = new cCerveza(eCerveza::IPA, 14,450, 0, 0);
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
