#include "instrumentos.h"
#include <iostream>

int main()
{
    Instrumento i1(1, 30.5f); // i1 es una objeto/instancia de la clase Instrumento
    Instrumento* i2 = new Instrumento(2, 30.5f); // i2 es un objeto/instancia de la clase Instrumento

    // Crear un programa que almacene instrumentos en una lista.
    ListaInstrumentos* lista = new ListaInstrumentos();
    lista->AgregarInstrumento(&i1);
    lista->Imprimir();
    lista->AgregarInstrumento(i2);
    lista->Imprimir();

    ListaEnlazadaInstrumentos* listaEnlazada = new ListaEnlazadaInstrumentos();
    listaEnlazada->AgregarInstrumento(1, 30.5f);
    listaEnlazada->AgregarInstrumento(2, 20.5f);
    listaEnlazada->AgregarInstrumentoAlFinal(3, 10.5f);
    listaEnlazada->Imprimir();

    listaEnlazada->EliminarInstrumento(0);
    listaEnlazada->Imprimir();
    listaEnlazada->EliminarInstrumento(1);
    listaEnlazada->Imprimir();


    // TAREA
    // Implementar EliminarInstrumento (eliminas el ultimo instrumento de la lista)
    // Implementar EliminarInstrumentoDadoCodigo (eliminas el instrumento de determinado codigo)

    return 0;
}