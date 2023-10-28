#include "instrumentos.h"

// ===================== Instrumento =================================

Instrumento::Instrumento()
{
    this->precio = 0.0f;
    this->codigo = 0;
    this->siguiente = nullptr;
}

Instrumento::Instrumento(int codigo, float precio)
{
    this->precio = precio;
    this->codigo = codigo;
    this->siguiente = nullptr;
}

float Instrumento::GetPrecio()
{
    return precio;
}

// ===================== ListaInstrumentos =================================

ListaInstrumentos::ListaInstrumentos()
{
    this->longitud = 0;
    this->pInst = nullptr;
}
void ListaInstrumentos::AgregarInstrumento(Instrumento* instrumento)
{
    if (this->pInst == nullptr)
    {
        this->pInst = new Instrumento[this->longitud + 1];
        this->pInst[this->longitud].codigo = instrumento->codigo;
        this->pInst[this->longitud].precio = instrumento->precio;
    }else 
    {
        Instrumento* pTemp = new Instrumento[this->longitud + 1];
        for (int i=0 ; i < this->longitud; i++)
        {
            // Copia de data entre arreglo anterior (pInst) y el nuevo (pTemp)
            pTemp[i].codigo = pInst[i].codigo;
            pTemp[i].precio = pInst[i].precio;
        }
        delete[] this->pInst; // Libero el espacio del arreglo anterior
        this->pInst = pTemp;

        this->pInst[this->longitud].codigo = instrumento->codigo;
        this->pInst[this->longitud].precio = instrumento->precio;
    }

    this->longitud++;
}
void ListaInstrumentos::Imprimir()
{
    for (int i=0; i < this->longitud; i++)
    {
        std::cout << this->pInst[i].codigo << " ";
    }
    std::cout << std::endl;
}
int ListaInstrumentos::GetLongitud()
{
    return this->longitud;
}

// ===================== ListaEnlazadaInstrumentos =================================

ListaEnlazadaInstrumentos::ListaEnlazadaInstrumentos()
{
    this->longitud = 0;
    this->pPrimer = nullptr;
}
void ListaEnlazadaInstrumentos::AgregarInstrumento(int codigo, float precio)
{
    if (this->pPrimer == nullptr)
    {
        // No hay elementos
        Instrumento* pNuevoInstrumento = new Instrumento(codigo, precio);
        this->pPrimer = pNuevoInstrumento;
    }else
    {
        Instrumento* pNuevoInstrumento = new Instrumento(codigo, precio);
        pNuevoInstrumento->siguiente = this->pPrimer;
        this->pPrimer = pNuevoInstrumento;
    }
    this->longitud++;
}

void ListaEnlazadaInstrumentos::AgregarInstrumentoAlFinal(int codigo, float precio)
{
    Instrumento* pNuevoInstrumento = new Instrumento(codigo, precio);

    if (this->pPrimer == nullptr)
    {
        // Caso lista vacia
        this->pPrimer = pNuevoInstrumento;
    }else
    {
        Instrumento* pPivot = this->pPrimer;

        while (pPivot->siguiente != nullptr)
        {
            pPivot = pPivot->siguiente;
        }

        pPivot->siguiente = pNuevoInstrumento;
    }
    this->longitud++;
}

void ListaEnlazadaInstrumentos::EliminarInstrumento(int pos)
{
    if (pos == 0)
    {
        // Eliminar el primero
        Instrumento* pTemp = this->pPrimer;
        this->pPrimer = this->pPrimer->siguiente;
        delete pTemp; // libero memoria
    }else
    {
        Instrumento* pPivot = this->pPrimer;
        Instrumento* pAnt = nullptr;
        int indice = 0;
        while (pPivot != nullptr)
        {
            if (indice == pos)
            {
                // Eliminar
                pAnt->siguiente = pPivot->siguiente;
                delete pPivot;
                break;
            }

            pAnt = pPivot;
            pPivot = pPivot->siguiente;
            indice++;
        }
    }
    this->longitud--;
    
}

Instrumento* ListaEnlazadaInstrumentos::BuscarPorCodigo(int codigo)
{
    Instrumento* pPivot = this->pPrimer;

    while(pPivot != nullptr)
    {
        if (pPivot->codigo == codigo)
        {
            // yay lo encontramos!
            return pPivot;
        }
        pPivot = pPivot->siguiente;
    }
    return nullptr;
}

void ListaEnlazadaInstrumentos::Imprimir()
{
    Instrumento* pPivot = this->pPrimer;

    while(pPivot != nullptr)
    {
            std::cout << "(" << pPivot->codigo << "," << pPivot->precio << ") ";
            pPivot = pPivot->siguiente;
    }
    std::cout << std::endl;
}