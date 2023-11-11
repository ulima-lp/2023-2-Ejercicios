#include "instrumentos.h"
#include "herencia.h"
#include <iostream>

void HacerCaminar(Animal* animal)
{
    animal->Caminar();
}

int main()
{
    //Animal* a1 = new Animal();
    Perro* pipo = new Perro();
    SerHumano* juler = new SerHumano();

    HacerCaminar(pipo);
    HacerCaminar(juler);

    return 0;
}