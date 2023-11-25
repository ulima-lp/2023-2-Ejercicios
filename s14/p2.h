#include <iostream>

class Letra
{
public:
    int num;
    std::string caracter;
    Letra* siguiente;

    Letra(int num);
};

class Frase
{
public:
    int longitud;
    Letra* primeraLetra;
    Frase();
    void CrearLetra(int num);
    void CompletarCaracter(int pos, std::string caracter);
};