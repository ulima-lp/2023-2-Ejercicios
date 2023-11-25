#include "p2.h"

using namespace Davinci;

// ==================================== Letra =====================================

Letra::Letra(int num)
{
    this->siguiente = nullptr;
    this->caracter = "";
    this->num = num;
}

// ==================================== Frase =====================================

Frase::Frase()
{
    this->longitud = 0;
    this->primeraLetra = nullptr;
}

void Frase::CrearLetra(int num)
{
    Letra* nuevaLetra = new Letra(num);
    if (this->primeraLetra == nullptr)
    {
        this->primeraLetra = nuevaLetra;
    }else
    {
        Letra* pPivotLetra = this->primeraLetra;
        while(pPivotLetra->siguiente != nullptr)
        {
            pPivotLetra = pPivotLetra->siguiente;
        }
        pPivotLetra->siguiente = nuevaLetra;
    }
    this->longitud++;
}

void Frase::CompletarCaracter(int pos, std::string caracter)
{
    Letra* pPivotLetra = this->primeraLetra;

    if (pPivotLetra == nullptr) return;

    int cont = 0;
    while(pPivotLetra != nullptr)
    {
        if (cont == pos)
        {
            pPivotLetra->caracter = caracter;
            return;
        }
        pPivotLetra = pPivotLetra->siguiente;
        cont++;
    }
}

void Frase::Ordenar()
{
    // Metodo: Bubble Sort
    for (int i = 0; i < this->longitud - 1; i++)
    {
        bool huboIntercambio = false;
        for (int j =0 ; j < this->longitud - i - 1; j++ )
        {
            if (this->Obtener(j)->num > this->Obtener(j+1)->num)
            {
                this->Intercambiar(j, j+1);
                huboIntercambio = true;
            }
        }
        if (!huboIntercambio)
        {
            break;
        }
    }
}

Letra *Frase::Obtener(int pos)
{
    Letra* pPivotLetra = this->primeraLetra;

    if (pPivotLetra == nullptr) return nullptr;

    int cont = 0;
    while(pPivotLetra != nullptr)
    {
        if (cont == pos)
        {
            return pPivotLetra;
        }
        pPivotLetra = pPivotLetra->siguiente;
        cont++;
    }
    return nullptr;
}

void Frase::Intercambiar(int pos1, int pos2)
{
    Letra* letra1 = Sacar(pos2);
    Insertar(letra1, pos1);
    Letra* letra2 = Sacar(pos1 + 1);
    Insertar(letra2, pos2);
}

Letra *Frase::Sacar(int pos)
{
    Letra* pPivotLetra = this->primeraLetra;
    Letra* pAnt = nullptr;

    if (pos == 0)
    {
        this->primeraLetra = pPivotLetra->siguiente;
        pPivotLetra->siguiente = nullptr;
        this->longitud--;
        return pPivotLetra;
    }else
    {
        int cont = 0;
        while(pPivotLetra != nullptr)
        {
            if (cont == pos)
            {
                pAnt->siguiente = pPivotLetra->siguiente;
                pPivotLetra->siguiente = nullptr;
                this->longitud--;
                return pPivotLetra;
            }

            pAnt = pPivotLetra;
            pPivotLetra = pPivotLetra->siguiente;
            cont++;
        }
    }

    return nullptr;
}

void Frase::Insertar(Letra* letra, int pos)
{
    if (pos == 0)
    {
        letra->siguiente = this->primeraLetra;
        this->primeraLetra = letra;
        this->longitud++;
    }else
    {
        Letra* pPivotLetra = this->primeraLetra;
        Letra* pAnt = nullptr;

        int cont = 0;
        while (pPivotLetra != nullptr)
        {
            if (cont == pos)
            {
                pAnt->siguiente = letra;
                letra->siguiente = pPivotLetra;
                this->longitud++;
                return;
            }

            pAnt = pPivotLetra;
            pPivotLetra = pPivotLetra->siguiente;
            cont++;
        }
        pAnt->siguiente = letra;
        this->longitud++;
    }
    
}

void Frase::PrintDecodificada()
{
    this->Ordenar();
    Letra* pPivotLetra = this->primeraLetra;
    int cont = 0;

    while(pPivotLetra != nullptr)
    {
        int numSerieFib = Fibonacci(cont);
        if (numSerieFib == pPivotLetra->num)
        {
            std::cout << pPivotLetra->caracter;
            pPivotLetra = pPivotLetra->siguiente;
        }else
        {
            std::cout << " ";
        }
        cont++;
    }
}

void Frase::PrintDebug()
{
    Letra* pPivotLetra = this->primeraLetra;
    while(pPivotLetra != nullptr)
    {
        std::cout << pPivotLetra->caracter << "(" << pPivotLetra->num << ") ";
        pPivotLetra = pPivotLetra->siguiente;
    }
    std::cout << std::endl;
}

int Frase::Fibonacci(int pos)
{
    if (pos == 0)
    {
        return 1;
    }
    if (pos == 1)
    {
        return 2;
    }

    int ant1 = 1;
    int ant2 = 2;
    for (int i = 2; i < pos; i++)
    {
        int res = ant1 + ant2;
        ant1 = ant2;
        ant2 = res;
    }

    return ant1 + ant2;
}
