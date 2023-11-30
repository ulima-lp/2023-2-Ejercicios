#pragma once

#include <iostream>

using namespace std;

class Digito
{
public:
    int num;
    int pos;
    Digito* siguiente;

    Digito(int num, int pos);
};

class Numero
{
public:
    Digito* primerDigito;
    int cantidadDigitos;

    Numero(int lnc);
    void AgregarDigito(int dig, int cont);
    virtual void Imprimir() = 0; // abstracto
    static int Factorial(int num);
};

class NumeroLNC : public Numero
{
public:
    NumeroLNC(int num);
    void Imprimir() override;
};

class NumeroDecimal : public Numero
{
public:
    NumeroDecimal(int num);
    void Imprimir() override;
};