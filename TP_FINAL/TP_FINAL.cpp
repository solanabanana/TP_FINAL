#include <iostream>
#include "Simulador.h"
int main()
{//Simulacion de una jornada laboral
	cListaT<cCerveza>* cervezas_bar = new cListaT<cCerveza>();
	cListaT<cCerveza>* cervezas_puntoventa = new cListaT<cCerveza>();
	//Creamos encargados para bar y punto de venta
	cEncargado* encargado_bar = new cEncargado("234");
	cEncargado* encargado_puntoventa = new cEncargado("456");
	//Listas de empleados para los locales
	cListaT<cEmpleado>* empleados_bar = new cListaT<cEmpleado>();
	cListaT<cEmpleado>* empleados_puntoventa = new cListaT<cEmpleado>();
	//Creamos un simulador para llenar la lista de empleados y cervezas de ambos locales
	AgregarCervezas(*cervezas_bar, *cervezas_puntoventa);
	AgregarEmpleados(*empleados_bar, *empleados_puntoventa);
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
	//En esta funcion ademas imprimimos la info del local para ver que funcione todo correctamente
	Bar1->ImprimirEmpleados();
	PuntoDeVenta1->ImprimirEmpleados();
	//Creamos la lista de locales y le agregamos los locales
	cListaT<cLocal>* locales = new cListaT<cLocal>();
	*locales + Bar1;
	*locales + PuntoDeVenta1;
	//Nos creamos la cerveceria
	cCerveceria* Pride = new cCerveceria(*locales);
	//Simulacion de llegada de clientes y actualizacion de datos
	//Fijarse en BuscarObjeto, esta tirando error.
	Pride->TICK();
	Pride->TICK();
	Pride->TICK();
	//Se cierra el día en los locales, se imprime el historial y se retiran todos los empleados
	//En Historial() dentro de FinalizarJornada() vamos a utilizar la sobrecarga del operador <<
	Pride->FinalizarJornada();
	//La horas de trabajo calculadas nos van a dar cero ya que se calculan en tiempo real y el codigo corre en segundos
	//Liberamos la memoria que utilizamos en el main
	//delete nuevo_empleado; Lo comentamos porque justo borramos el empleado que estaba apuntando nuevo_empleado
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
}
