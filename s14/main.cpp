#include <iostream>
#include "p2.h"

int main()
{
    /*
    11
    13 2 89 377 8 3 233 34 144 21 1
    OHLAMESAINT
    */
    // 1. Leer la longitud
    int tam;
    std::cin >> tam;

    // 2. Leer los numeros de la sec fib
    Frase* frase = new Frase();
    for (int i=0; i < tam; i++)
    {
        int valor;
        std::cin >> valor;
        frase->CrearLetra(valor);
    }

    // 3. Leer palabra y procesar cada letra
    std::string palabra;
    std::cin >> palabra;

    for (int i=0; i < tam; i++)
    {
        std::string letraTemp(1, palabra[i]);
        frase->CompletarCaracter(i, letraTemp);
    }

    frase->PrintDebug();

    //frase->Intercambiar(9,10);
    frase->Ordenar();

    frase->PrintDebug();
    return 0;
}