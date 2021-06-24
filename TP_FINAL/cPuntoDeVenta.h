#pragma once
#include "cLocal.h"
#include "cVendedor.h"
class cPuntoDeVenta :
    public cLocal
{
public:
    //constructor y destructor
    cPuntoDeVenta(cEncargado* encargado, cListaT<cCerveza> cervezas, cListaT<cEmpleado> empleados, string nombre, int numero, string ubicacion);
    ~cPuntoDeVenta() {};
    //metodos heredados
    void SimularCliente();
    void SolicitarCerveza(eCerveza tipo, int cant);
    void ChequearStock();
};

