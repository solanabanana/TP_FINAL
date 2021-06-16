#pragma once
#include "cEmpleado.h"
using namespace std;
class cVendedor :
    public cEmpleado
{
public:
    cVendedor(string cuit);
    ~cVendedor() {};

    void CalcularHorasTrabajadas();// const override;
    void CalcularSalario();// const override;
};

