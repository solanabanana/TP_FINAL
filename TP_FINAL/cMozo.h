#pragma once
#include "cEmpleado.h"
class cBar;
using namespace std;
class cMozo :
    public cEmpleado
{
    friend class cLocal;
public:
    cMozo(string cuit);
    ~cMozo() {};

    void CalcularHorasTrabajadas();// const override;
    void CalcularSalario();// const override;
    void LimpiarMesa(int NumMesa, cBar* bar);
};

