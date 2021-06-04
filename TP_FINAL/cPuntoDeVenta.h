#pragma once
#include "cLocal.h"
#include "cVendedor.h"
class cPuntoDeVenta :
    public cLocal
{
public:

    cPuntoDeVenta(cEmpleado* encargado, cListaT<cCerveza> cervezas, cListaT<cEmpleado> empleados, string nombre, int numero, string ubicacion);
    ~cPuntoDeVenta() {};

    void SimularCliente() const override;
    void SolicitarCerveza() const override;
};

