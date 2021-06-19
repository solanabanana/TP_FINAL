#pragma once
#include "cEmpleado.h"
#include "cCerveza.h"
//class cCerveza;
class cLocal;
using namespace std;
class cEncargado :
    public cEmpleado
{
    friend class cLocal;
public:
    cEncargado(string cuit);
    ~cEncargado() {};

    void CalcularHorasTrabajadas();// const override;
    void CalcularSalario();// const override;
    int CalcularCantBarriles(eCerveza tipo, cLocal* local);
    int CantCerveza(eCerveza tipo, cLocal* local);
};

