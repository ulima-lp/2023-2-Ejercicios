#include <iostream>

enum class Tipo
{
    Laboratorio, Asignacion
};

class Nota
{
public:
    int valor;
    Tipo tipo;
    Nota* siguienteNota;

    Nota();
};

class Alumno
{
public:
    std::string codigo;
    std::string carrera;
    Alumno* siguienteAlumno;
    Nota* listaNotas;

    Alumno();
    void RegistrarNota(int valor, Tipo tipo);
};

class Seccion
{
public:
    int numero;
    std::string curso;
    Alumno* listaAlumnos;

    Seccion();
    void RegistrarAlumno(std::string codigo, std::string nombreCarrera);
    void RegistrarNota(std::string codigo, int valor, Tipo tipo);
    float CalcularPromedio();
};

