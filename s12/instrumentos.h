#include <iostream>

class Instrumento
{
private:
public:
    float precio; // atributo
    int codigo; // atributo
    Instrumento* siguiente; // atributo
    static int contador; // atributo clase

    Instrumento(); // Metodo constructor
    Instrumento(int codigo, float precio); // Metodo constructor secundario
    float GetPrecio(); // Metodo
};

class ListaArreglosInstrumentos
{
private:
    int longitud;
    Instrumento* pInst;
public:
    ListaArreglosInstrumentos();
    void AgregarInstrumento(Instrumento* instrumento);
    void Imprimir();
    int GetLongitud();
    static void ImprimirInstrumento(Instrumento* instrumento);
};

// ========================================

class ListaEnlazadaInstrumentos
{
public:
    Instrumento* pPrimer;
    int longitud;

    ListaEnlazadaInstrumentos(); // constructor
    ~ListaEnlazadaInstrumentos(); // destructor
    void AgregarInstrumento(int codigo, float precio);
    void AgregarInstrumentoAlFinal(int codigo, float precio);
    void EliminarInstrumento(int pos);
    Instrumento* BuscarPorCodigo(int codigo);
    void Imprimir();
};

class Persona
{
public:
    std::string nombre;
    ListaEnlazadaInstrumentos* listaInstrumentos;

    Persona(std::string nombre);

    void AgregarInstrumento(int codigo, float precio);
};