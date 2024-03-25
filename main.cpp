#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int fibonacci(int iIteracoes);
int& absoluto(int& irefNum);
int fatorial(int iValor);
int somaProgressaoAritmetica(int iNumeroTermos, int iPrimeiroTermo, int iUltimoTermo);
int numeroDeDigitos(int iValor);


int main() 
{
    int iValor = -25;
    int irefValorAbsoluto = absoluto(iValor);
    cout << "Valor absoluto: " << irefValorAbsoluto << endl;

    cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n" << endl;

    int iValorFatorial = 5;
    cout << "Fatorial de " << iValorFatorial << ": " << fatorial(iValorFatorial) << endl;

    cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n" << endl;

    int iNumeroTermos = 10;
    int iPrimeiroTermo = 2;
    int iUltimoTermo = 200;
    int iSomaProgressao;
    
    iSomaProgressao = somaProgressaoAritmetica(iNumeroTermos, iPrimeiroTermo, iUltimoTermo);
    cout << "Soma da PA com " << iNumeroTermos << " termos, sendo o primeiro " << iPrimeiroTermo << " e o último " << iUltimoTermo << ": " << iSomaProgressao << endl;

    cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n" << endl;
    
    int iPassos = 6;
    cout << iPassos << "º termo da sequência de fibonacci: " << fibonacci(iPassos) << endl;
    
    cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n" << endl;
    
    int iTeste = 1123123;
    cout << "Número de dígitos de "<< iTeste << ": " << numeroDeDigitos(iTeste) << endl;
    
    return 0;
}

int& absoluto(int& irefNum)
{
    if (irefNum < 0)
    {
        irefNum = (-1) * irefNum;
    }
    
    return irefNum;
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

int fibonacci(int iIteracoes){
  // se for apenas um passo retornamos 0...
  if (iIteracoes == 1){
    return 1;
  }
  
  // senão fazemos as iterações parando um passo antes (para compensar
  // o primeiro if) para o resto da sequência
  int iAnterior = 0;
  int iResultado = 1;

  for (int i = iIteracoes; i > 1; i--){
    iResultado += iAnterior;  
    iAnterior = iResultado - iAnterior;
  }

  return iResultado;
}

int numeroDeDigitos(int iValor)
{
    int iDigitos = 0;
    int iResultadoDiv = 1;
    int iBaseDez = 10;
    
    for (int i = 1; iResultadoDiv > 0; i++)
    {
        iResultadoDiv = iValor / iBaseDez;
        iDigitos = i;
        
        iBaseDez = iBaseDez * 10;
    }
    
    return iDigitos;
}
