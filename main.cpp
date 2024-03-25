#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int abs(int iNum);
int Fatorial(int iValor);

int main() 
{
    int iValor = -25;
    int iValorAbsoluto = abs(iValor);
    cout << "Valor absoluto de " << iValor << ": " << iValorAbsoluto << endl;

    int iValorFatorial = 5;
    cout << Fatorial(iValorFatorial) << endl;
    
    return 0;
}

int abs(int iNum)
{
    if (iNum < 0)
    {
        iNum = (-1) * iNum;
    }
    
    return iNum;
}

int Fatorial(int iValor)
{
    int iResultado = 1;
    
    for (int i=iValor; i>1; i--)
    {
        iResultado = iResultado * i;
    }
    
    return iResultado;
}
