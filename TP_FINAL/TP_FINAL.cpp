#include <iostream>
#include "cCerveza.h"
#include "cEncargado.h"
#include "cBar.h"
#include "cPuntoDeVenta.h"
#include "cCerveceria.h"
int main()//HACER FUNCION SIMULACION QUE HAGA TODO ESTO Y LLAMARLA ACA EN EL MAIN
{//Simulacion de una jornada laboral
	cListaT<cCerveza>* cervezas_bar = new cListaT<cCerveza>();
	cListaT<cCerveza>* cervezas_puntoventa = new cListaT<cCerveza>();
	//Nos creamos cervezas para el bar y el punto de venta y las agregamos a sus listas
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
	//Creamos encargados para bar y punto de venta
	cEmpleado* encargado_bar = new cEncargado(234);
	cEmpleado* encargado_puntoventa = new cEncargado(456);
	//Listas de empleados para los locales
	cListaT<cEmpleado> *empleados_bar = new cListaT<cEmpleado>();
	cListaT<cEmpleado> *empleados_puntoventa = new cListaT<cEmpleado>();
	//Creamos dos vendedores para cada local y los agregamos a las listas
	cEmpleado* nuevo_empleado;
	nuevo_empleado = new cVendedor(321);
	*empleados_bar + nuevo_empleado;
	nuevo_empleado = new cVendedor(654);
	*empleados_bar + nuevo_empleado;
	nuevo_empleado = new cVendedor(987);
	*empleados_puntoventa + nuevo_empleado;
	nuevo_empleado = new cVendedor(765);
	*empleados_puntoventa + nuevo_empleado;
	nuevo_empleado = new cMozo(564);
	*empleados_bar + nuevo_empleado;
	nuevo_empleado = new cMozo(865);
	*empleados_bar + nuevo_empleado;
	//Creamos la lista de mesas para el bar con tres mesas
	cListaT<cMesa>* mesas = new cListaT<cMesa>();
	cMesa* nueva_mesa;
	for (int i = 0; i < 3; ++i)
	{
		nueva_mesa = new cMesa(i);
		*mesas + nueva_mesa;
	}
	//Nos creamos un bar y un punto de venta con los datos que ya creamos
	cLocal* Bar1 = new cBar(encargado_bar, *cervezas_bar, *empleados_bar, "Pride", 34, "Moreno 850", *mesas);
	cLocal* PuntoDeVenta1 = new cPuntoDeVenta(encargado_puntoventa, *cervezas_puntoventa, *empleados_puntoventa, "Pride-Venta", 43, "Paraguay 768");
	//Creamos la lista de locales y le agregamos los locales
	cListaT<cLocal>* locales = new cListaT<cLocal>();
	*locales + Bar1;
	*locales + PuntoDeVenta1;
	//Nos creamos la cerveceria
	cCerveceria* Pride = new cCerveceria(*locales);
	//Simulacion de llegada de clientes y actualizacion de datos
	Pride->TICK();
	//Se va un mozo del bar
	*empleados_bar - empleados_bar[0][865];
	Pride->TICK();
	Pride->TICK();

	//Se cierra el día en los locales, se imprime el historial y se retiran todos los empleados
	//En Historial() vamos a utilizar la sobrecarga del operador <<
	Pride->FinalizarJornada();
	//Liberamos la memoria que utilizamos en el main
	delete nueva_cerveza;
	delete nuevo_empleado;
	delete encargado_bar;
	delete encargado_puntoventa;
	delete nueva_mesa;
	delete Bar1;
	delete PuntoDeVenta1;
	delete cervezas_bar;
	delete cervezas_puntoventa;
	delete empleados_bar;
	delete empleados_puntoventa;
	delete mesas;
	delete locales;
	delete Pride;
	//Baby main, si necesitamos agregar otras cosas lo haremos cuando tengamos los métodos hechos :D
}
