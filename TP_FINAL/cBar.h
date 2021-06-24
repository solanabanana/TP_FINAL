#pragma once
#include "cLocal.h"
#include "cMesa.h"
#include "cMozo.h"
#include "cVendedor.h"
class cBar :
    public cLocal
{
    cListaT<cMesa> Mesas;//lista de mesas
    friend class cMozo;//friend de clase mozo

public:
    //constructor y destructor
    cBar(cEncargado* encargado, cListaT<cCerveza> cervezas, cListaT<cEmpleado> empleados, string nombre, int numero, string ubicacion, cListaT<cMesa> mesas);
    ~cBar() {};
    //metodos heredados
    void SimularCliente();
    void SolicitarCerveza(eCerveza tipo, int cant);
    void ChequearStock();
};

