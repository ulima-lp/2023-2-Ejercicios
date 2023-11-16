#include "p1.h"

// =============================== Nota ===============================

Nota::Nota()
{
    this->valor = 0;
    this->tipo = Tipo::Laboratorio;
    this->siguienteNota = nullptr;
}

Nota::Nota(int valor, Tipo tipo)
{
    this->valor = valor;
    this->tipo = tipo;
    this->siguienteNota = nullptr;
}

// =============================== Alumno ===============================

Alumno::Alumno()
{
    this->codigo = "";
    this->carrera = "";
    this->siguienteAlumno = nullptr;
    this->listaNotas = nullptr;
}

Alumno::Alumno(std::string codigo, std::string carrera)
{
    this->codigo = codigo;
    this->carrera = carrera;
    this->siguienteAlumno = nullptr;
    this->listaNotas = nullptr;
}

// =============================== Seccion ===============================

Seccion::Seccion()
{
    this->numero = 0;
    this->curso = "";
    this->listaAlumnos = nullptr;
    
}

Seccion::Seccion(int numero, std::string curso)
{
    this->numero = numero;
    this->curso = curso;
    this->listaAlumnos = nullptr;
}
