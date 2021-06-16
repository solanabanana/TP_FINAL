#pragma once
#include "cEmpleado.h"
class cCerveza;
class cLocal;
using namespace std;
class cEncargado :
    public cEmpleado
{
public:
    cEncargado(string cuit);
    ~cEncargado() {};

    void CalcularHorasTrabajadas();// const override;
    void CalcularSalario();// const override;
    void CalcularCantBarriles(cCerveza cerveza, cLocal* local);
};

