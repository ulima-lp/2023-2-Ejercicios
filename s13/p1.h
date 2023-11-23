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
    Nota(int valor, Tipo tipo);
};

class Alumno
{
public:
    std::string codigo;
    std::string carrera;
    Alumno* siguienteAlumno;
    Nota* listaNotas;

    Alumno();
    Alumno(std::string codigo, std::string carrera);
    void RegistrarNota(int valor, Tipo tipo);
    float CalcularPromedio();
};

class Seccion
{
private:
    Alumno* BuscarAlumno(std::string codigo);
public:
    int numero;
    std::string curso;
    Alumno* listaAlumnos;

    Seccion();
    Seccion(int numero, std::string curso);
    void RegistrarAlumno(std::string codigo, std::string nombreCarrera);
    void RegistrarNota(std::string codigo, int valor, Tipo tipo);
    float CalcularPromedio();
};
