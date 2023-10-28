#include <iostream>

class Instrumento
{
private:
public:
    float precio; // atributo
    int codigo; // atributo
    Instrumento* siguiente; // atributo

    Instrumento(); // Metodo constructor
    Instrumento(int codigo, float precio); // Metodo constructor secundario
    float GetPrecio(); // Metodo
};

class ListaInstrumentos
{
private:
    int longitud;
    Instrumento* pInst;
public:
    ListaInstrumentos();
    void AgregarInstrumento(Instrumento* instrumento);
    void Imprimir();
    int GetLongitud();
};

// ========================================

class ListaEnlazadaInstrumentos
{
public:
    Instrumento* pPrimer;
    int longitud;

    ListaEnlazadaInstrumentos();
    void AgregarInstrumento(int codigo, float precio);
    void AgregarInstrumentoAlFinal(int codigo, float precio);
    void EliminarInstrumento(int pos);
    Instrumento* BuscarPorCodigo(int codigo);
    void Imprimir();
};