#pragma once
#include "cLocal.h"
#include "cVendedor.h"
class cPuntoDeVenta :
    public cLocal
{
public:

    cPuntoDeVenta(cEncargado* encargado, cListaT<cCerveza> cervezas, cListaT<cEmpleado> empleados, string nombre, int numero, string ubicacion);
    ~cPuntoDeVenta() {};

    void SimularCliente();
    void SolicitarCerveza(eCerveza tipo, int cant);
    void ChequearStock();
};

