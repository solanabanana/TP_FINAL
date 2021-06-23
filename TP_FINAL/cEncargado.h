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
public://constructor y destructor
    cEncargado(string cuit);
    ~cEncargado() {};
    //metodos heredador
    void CalcularHorasTrabajadas();
    void CalcularSalario();
    //metodos propios de la clase
    int CalcularCantBarriles(eCerveza tipo, cLocal* local);
    int CantCerveza(eCerveza tipo, cLocal* local);
    void CalcularLitros(eCerveza tipo, cLocal* local);
    
};

