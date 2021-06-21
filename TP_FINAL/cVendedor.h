#pragma once
#include "cEmpleado.h"
using namespace std;
class cVendedor :
    public cEmpleado
{
    friend class cLocal;
public://constructor y destructor
    cVendedor(string cuit);
    ~cVendedor() {};
    //metodos heredados
    void CalcularHorasTrabajadas();
    void CalcularSalario();
};

