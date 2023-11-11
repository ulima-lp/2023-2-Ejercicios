#include "herencia.h"

void Animal::Respirar()
{
    std::cout << "Respirando" << std::endl;
}

void SerHumano::Caminar()
{
    std::cout << "Ser Humano Caminando..." << std::endl;
}

void Perro::Caminar()
{
    std::cout << "Perro Caminando..." << std::endl;
}
