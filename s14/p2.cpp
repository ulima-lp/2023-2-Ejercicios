#include "p2.h"

// ==================================== Letra =====================================

Letra::Letra(int num)
{
    this->siguiente = nullptr;
    this->caracter = "";
    this->num = num;
}

// ==================================== Frase =====================================

Frase::Frase()
{
    this->longitud = 0;
    this->primeraLetra = nullptr;
}

void Frase::CrearLetra(int num)
{
    Letra* nuevaLetra = new Letra(num);
    if (this->primeraLetra == nullptr)
    {
        this->primeraLetra = nuevaLetra;
    }else
    {
        Letra* pPivotLetra = this->primeraLetra;
        while(pPivotLetra->siguiente != nullptr)
        {
            pPivotLetra = pPivotLetra->siguiente;
        }
        pPivotLetra->siguiente = nuevaLetra;
    }
    this->longitud++;
}

void Frase::CompletarCaracter(int pos, std::string caracter)
{
}
