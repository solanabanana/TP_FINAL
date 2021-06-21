#pragma once
#include "cEmpleado.h"
class cBar;
using namespace std;
class cMozo :
    public cEmpleado
{
    friend class cLocal;
public://constructor  y destructor
    cMozo(string cuit);
    ~cMozo() {};
    //metodos heredados
    void CalcularHorasTrabajadas();
    void CalcularSalario();
    //metodo propio de la clase
    void LimpiarMesa(int NumMesa, cBar* bar);
};

