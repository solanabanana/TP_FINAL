#pragma once
#include "cEmpleado.h"
using namespace std;
class cEncargado :
    public cEmpleado
{
public:
    cEncargado(string cuit);
    ~cEncargado() {};

    int CalcularHorasTrabajadas() const override;
    int CalcularSalario() const override;
    int CalcularCantBarriles();
};

