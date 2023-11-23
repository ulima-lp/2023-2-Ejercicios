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
}

void Frase::CompletarCaracter(int pos)
{
}
