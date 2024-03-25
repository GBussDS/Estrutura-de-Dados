#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int Fibonacci(int iIteracoes);

int main() 
{
  cout << Fibonacci(5);

  return 0;
}

int Fibonacci(int iIteracoes){
  // se for apenas um passo retornamos 0...
  if (iIteracoes == 1){
    return 0;
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