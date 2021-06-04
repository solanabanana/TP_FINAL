#pragma once
#include "cLocal.h"
#include "cMesa.h"
#include "cMozo.h"
#include "cVendedor.h"
class cBar :
    public cLocal
{
    cListaT<cMesa> Mesas;

public:
    cBar(cEmpleado* encargado, cListaT<cCerveza> cervezas, cListaT<cEmpleado> empleados, string nombre, int numero, string ubicacion, cListaT<cMesa> mesas);
    ~cBar() {};

    void SimularCliente() const override;
    void SolicitarCerveza() const override;
};

