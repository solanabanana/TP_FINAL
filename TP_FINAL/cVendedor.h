#pragma once
#include "cEmpleado.h"
using namespace std;
class cVendedor :
    public cEmpleado
{
public:
    cVendedor(string cuit);
    ~cVendedor() {};

    int CalcularHorasTrabajadas() const override;
    int CalcularSalario() const override;
};

