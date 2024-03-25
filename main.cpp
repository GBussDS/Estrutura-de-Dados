#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int abs(int iNum);
int fatorial(int iValor);
int somaProgressaoAritmetica(int iNumeroTermos, int iPrimeiroTermo, int iUltimoTermo);

int main() 
{
    int iValor = -25;
    int iValorAbsoluto = abs(iValor);
    cout << "Valor absoluto de " << iValor << ": " << iValorAbsoluto << endl;

    cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n" << endl;

    int iValorFatorial = 5;
    cout << Fatorial(iValorFatorial) << endl;

    cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n" << endl;

    iSomaProgressao = somaProgressaoAritmetica(iNumeroTermos, iPrimeiroTermo, iUltimoTermo);
    cout << "Soma da PA com " << iNumeroTermos << " termos, sendo o primeiro " << iPrimeiroTermo << " e o último " << iUltimoTermo << ": " << iSomaProgressao << endl;
    
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

int fatorial(int iValor)
{
    int iResultado = 1;
    
    for (int i=iValor; i>1; i--)
    {
        iResultado = iResultado * i;
    }
    
    return iResultado;
}

int somaProgressaoAritmetica(int iNumeroTermos, int iPrimeiroTermo, int iUltimoTermo)
{
    int iSoma;
    
    iSoma = (iNumeroTermos / 2) * (iPrimeiroTermo + iUltimoTermo);
    
    return iSoma;
}
