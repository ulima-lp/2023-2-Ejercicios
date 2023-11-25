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

class ListaInstrumentos
{

public:
    int longitud;
    virtual void AgregarInstrumento(Instrumento* instrumento) = 0;
    virtual void AgregarInstrumento(int codigo, float precio) = 0;
    virtual void EliminarInstrumento(int pos) = 0;
    virtual Instrumento* BuscarPorCodigo(int codigo) = 0;
    virtual void Imprimir() = 0;
    int GetLongitud(); // NO es abstracto y NO es polimorfico
    static void ImprimirInstrumento(Instrumento* instrumento);
};

class ListaArreglosInstrumentos : public ListaInstrumentos
{
private:
    int longitud;
    Instrumento* pInst;
public:
    ListaArreglosInstrumentos();
    void AgregarInstrumento(Instrumento* instrumento) override;
    void AgregarInstrumento(int codigo, float precio) override;
    void EliminarInstrumento(int pos) override;
    Instrumento* BuscarPorCodigo(int codigo) override;
    void Imprimir() override;
    
};

// ========================================

class ListaEnlazadaInstrumentos : public ListaInstrumentos
{
public:
    Instrumento* pPrimer;
    int longitud;

    ListaEnlazadaInstrumentos(); // constructor
    ~ListaEnlazadaInstrumentos(); // destructor
    void AgregarInstrumento(Instrumento* instrumento) override;
    void AgregarInstrumento(int codigo, float precio) override;
    void AgregarInstrumentoAlFinal(int codigo, float precio);
    void EliminarInstrumento(int pos) override;
    Instrumento* BuscarPorCodigo(int codigo) override;
    void Imprimir() override;
};

class Persona
{
public:
    std::string nombre;
    ListaEnlazadaInstrumentos* listaInstrumentos;

    Persona(std::string nombre);

    void AgregarInstrumento(int codigo, float precio);
};