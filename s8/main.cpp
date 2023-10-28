#include <iostream>

struct Persona
{
    std::string nombre;
    int edad;
    float estatura;
};

Persona persona;

void LeerDatos()
{
    std::cout << "Ingrese nombre: ";
    std::cin >> persona.nombre;

    std::cout << "Ingrese edad: ";
    std::cin >> persona.edad;

    std::cout << "Ingrese estatura: ";
    std::cin >> persona.estatura;
}



int main()
{
    LeerDatos();

    return 0;
}