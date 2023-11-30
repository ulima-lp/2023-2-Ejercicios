#include <iostream>
#include "p4.h"

using namespace std;

int main()
{
    int numLNC = 0;
    cout << "Ingrese la cadena con el numero en notacion LNC: ";
    cin >> numLNC;

    NumeroDecimal* decimal = new NumeroDecimal(numLNC);
    NumeroLNC* lnc = new NumeroLNC(numLNC);
    decimal->Imprimir();
    lnc->Imprimir();
    return 0;
}