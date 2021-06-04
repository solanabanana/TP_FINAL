#pragma once
#include "cEmpleado.h"
using namespace std;
class cMozo :
    public cEmpleado
{
public:
    cMozo(int cuit);
    ~cMozo() {};

    int CalcularHorasTrabajadas() const override;
    int CalcularSalario() const override;
    void LimpiarMesa(int NumMesa);
};

