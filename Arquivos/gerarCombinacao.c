#include "gerarCombinacao.h"
#include "gerarArvore.h"

void gerarCombinacao(int espacos[], int qE, int qA, int m[qE][qE], int *Pparar_programa)
{
  // vetor que guarda temporariamente a combinação gerada que define
  // uma árvore com "qA" cores Azuis
  int combinacaoAtual[qA];

  // índices incial e final para o vetor "espacos"
  int inicio = 0;
  int fim = qE-1;

  // indice que será usado na outra função
  int indice = 0;

  int *PPparar_programa;
  PPparar_programa = Pparar_programa;
  
  gerarArvore(espacos, combinacaoAtual, inicio, fim, indice, qA, qE, m, PPparar_programa);
}

