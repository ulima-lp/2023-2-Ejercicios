#include "p4.h"

// ===================================== Digito =====================================

Digito::Digito(int num, int pos)
{
    this->num = num;
    this->pos = pos;
    this->siguiente = nullptr;
}

// ===================================== Numero =====================================

Numero::Numero(int lnc)
{
    // 123 / 10 => 12 
    // 123 % 10 => 3
    this->primerDigito = nullptr;
    this->cantidadDigitos = 0;

    int numTemp = lnc;
    int cont = 0;
    while(numTemp != 0)
    {
        int dig = numTemp % 10;
        AgregarDigito(dig, cont);
        numTemp = numTemp / 10;
        cont++;
    }
}

void Numero::AgregarDigito(int dig, int cont)
{
    Digito* nuevoDigito = new Digito(dig, cont + 1);
    if (this->primerDigito == nullptr)
    {
        this->primerDigito = nuevoDigito;
    }else
    {
        nuevoDigito->siguiente = this->primerDigito;
        this->primerDigito = nuevoDigito;
    }
    this->cantidadDigitos++;
}

int Numero::Factorial(int num)
{
    // f(1) => 1
    // f(2) => 1 * 2
    // f(3)  => 1 * 2 * 3
    // ..
    // f(10) => 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10
    int resFact = 1;
    for (int i=1; i <= num; i++)
    {
        resFact = resFact * i;
    }
    return resFact;
}

// ===================================== NumeroLNC =====================================

NumeroLNC::NumeroLNC(int num) : Numero(num)
{}

void NumeroLNC::Imprimir()
{
    Digito* pPivotDigito = this->primerDigito;
    while(pPivotDigito != nullptr)
    {
        cout << pPivotDigito->num;
        pPivotDigito = pPivotDigito->siguiente;
    }
    cout << endl;
}

// ===================================== NumeroDecimal =====================================

NumeroDecimal::NumeroDecimal(int num) : Numero(num)
{}

void NumeroDecimal::Imprimir()
{
    Digito* pPivotDigito = this->primerDigito;
    int numResultado = 0;
    while(pPivotDigito != nullptr)
    {
        numResultado += pPivotDigito->num * Numero::Factorial(pPivotDigito->pos);

        pPivotDigito = pPivotDigito->siguiente;
    }
    cout << numResultado << endl;
}
