#include "instrumentos.h"
#include <iostream>

int main()
{

    
    ListaEnlazadaInstrumentos* listaInst = new ListaEnlazadaInstrumentos();
    listaInst->AgregarInstrumento(1, 20.3);
    listaInst->AgregarInstrumento(2, 10.9);

    delete listaInst;
    
    return 0;
}