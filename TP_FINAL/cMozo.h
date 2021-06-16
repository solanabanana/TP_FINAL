#pragma once
#include "cEmpleado.h"
using namespace std;
class cMozo :
    public cEmpleado
{
public:
    cMozo(string cuit);
    ~cMozo() {};

    void CalcularHorasTrabajadas();// const override;
    void CalcularSalario();// const override;
    void LimpiarMesa(int NumMesa);
};

