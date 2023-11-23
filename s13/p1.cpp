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

void Alumno::RegistrarNota(int valor, Tipo tipo)
{
    Nota* nuevaNota = new Nota(valor, tipo);
    if (this->listaNotas == nullptr)
    {
        // No hay notas registradas para este alumno.
        this->listaNotas = nuevaNota;
    }else
    {
        Nota* pPivotNota = this->listaNotas;
        while(pPivotNota->siguienteNota != nullptr)
        {
            pPivotNota = pPivotNota->siguienteNota;
        }
        pPivotNota->siguienteNota = nuevaNota;
    }
}

float Alumno::CalcularPromedio()
{
    Nota* pPivotNota = this->listaNotas;

    if (pPivotNota == nullptr) return 0.0f;

    float acumNota = 0.0f;
    int cantidadNotas = 0;

    while(pPivotNota != nullptr)
    {
        acumNota += pPivotNota->valor;
        cantidadNotas++;
        pPivotNota = pPivotNota->siguienteNota;
    }

    return acumNota / cantidadNotas;
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

Alumno* Seccion::BuscarAlumno(std::string codigo)
{
    Alumno* pPivotAlumno = this->listaAlumnos;
    while (pPivotAlumno != nullptr)
    {
        if (pPivotAlumno->codigo == codigo)
        {
            // Lo encontre!
            return pPivotAlumno;
        }

        pPivotAlumno = pPivotAlumno->siguienteAlumno;
    }
    return nullptr;
}

void Seccion::RegistrarAlumno(std::string codigo, std::string nombreCarrera)
{
    Alumno* nuevoAlumno = new Alumno(codigo, nombreCarrera);
    if (this->listaAlumnos == nullptr)
    {
        // No hay alumnos en la seccion
        this->listaAlumnos = nuevoAlumno;

    }else
    {
        // Ya hay alumnos
        Alumno* pPivotAlumno = this->listaAlumnos;
        while(pPivotAlumno->siguienteAlumno != nullptr)
        {
            pPivotAlumno = pPivotAlumno->siguienteAlumno;
        }
        pPivotAlumno->siguienteAlumno = nuevoAlumno;
    }
    
}

void Seccion::RegistrarNota(std::string codigo, int valor, Tipo tipo)
{
    // 1. Buscar alumno
    Alumno* alumno = this->BuscarAlumno(codigo);
    // 2. Registrar nota en alumno encontrado
    if (alumno == nullptr)  return;
    
    alumno->RegistrarNota(valor, tipo);
}

float Seccion::CalcularPromedio()
{
    // Recorrer alumno x alumno y calcular el promedio a cada uno
    Alumno* pPivotAlumno = this->listaAlumnos;

    if (pPivotAlumno == nullptr) return 0.0f;

    float sumaPromedios = 0.0f;
    int cantidadAlumnos = 0;
    while (pPivotAlumno != nullptr)
    {
        sumaPromedios += pPivotAlumno->CalcularPromedio();
        cantidadAlumnos++;
        pPivotAlumno = pPivotAlumno->siguienteAlumno;
    }

    return sumaPromedios / cantidadAlumnos;
}
