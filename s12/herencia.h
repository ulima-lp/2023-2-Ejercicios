#include <iostream>

enum class Sexo
{
    Femenino, Masculino
};

class Animal
{
private:
    
public:
    float peso;
    Sexo sexo;

    virtual void Caminar() = 0; // metodo abstracto
    void Respirar();
};

class SerHumano : public Animal
{
public:
    void Caminar() override;
};

class Perro : public Animal
{
public:
    void Caminar() override;
};

