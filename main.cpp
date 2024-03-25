#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int abs(int iNum);

int main() 
{
    int iValor = -25;
    int iValorAbsoluto = abs(iValor);
    cout << "Valor absoluto de " << iValor << ": " << iValorAbsoluto << endl;
    
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
