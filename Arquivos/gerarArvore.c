#include "gerarArvore.h"

#include <stdio.h>

void gerarArvore(int espacos[], int combinacaoAtualAzul[], int inicio, int fim, int indice, int qA, int qE, int m[qE][qE], int *PPparar_programa)
{
  int tamanho_arvore = qE;
  char arvore[tamanho_arvore];
  int indice_aux;
  int indice_aux2;
  int tamanho_comb;
  int qV = qE - qA;
  int combinacaoAtualVermelha[qV];
  //int qCompMaxA = 0; // Quantidade máxima de comparações dos Azuis na verificação da árvore
  //int qCompMaxV = 0; // Quantidade máxima de comparações dos Vermelhos na verificação da árvore
  //int qCompMax; // Quantidade máxima na verificação da árvore
  int parar_iteracao1 = 0; // Variável auxiliar para controlar iteração da validação da árvore de natal
  int parar_iteracao2 = 0;

  // qCompMaxA
  //for (int k=1; k<=(qA -1); k++)
  //{
    //qCompMaxA = qCompMaxA + (qA - k);
  //}

  // qCompMaxV
  //for (int k=1; k<=(qV -1); k++)
  //{
   // qCompMaxV = qCompMaxV + (qV - k);
  //}

  // imprime as combinacoes e as árvores (correspondente) atuais geradas
  if (indice == qA)
  {
    if(qE == 0)
    {
      //printf("Árvores impossíveis de se fazer!\n");
    }
    else
    {
      if (qA == 0)
      {
        // combinação
        //printf("A:[] ");
        //printf("V:[");
        indice_aux2 = 0;
        for (int i=0; i<=(qE-1); i++)
        {
          //printf(" %d ", espacos[i]);
          combinacaoAtualVermelha[indice_aux2] = espacos[i];
          //printf(" %d ", combinacaoAtualVermelha[indice_aux2]);
          indice_aux2++;
        }
        //printf("] = ");

        // árvore correspondente
        //printf("[");

        for (int k=0; k<=(tamanho_arvore-1); k++)
        {
          arvore[k] = 'V';
          //printf(" %c ", arvore[k]);
        }
        //printf("]");
      }
      else
      {
        // combinação
        //printf("A:[");
        tamanho_comb = 0;
        for (int j=0; j<=(qA-1); j++)
        {
          //printf(" %d ", combinacaoAtualAzul[j]);
          tamanho_comb++;
        }
        //printf("] ");

        indice_aux = 0;
        indice_aux2 = 0;
        //printf("V:[");
        for (int j=0; j<=(qE-1); j++)
        {
          if(espacos[j] != combinacaoAtualAzul[indice_aux])
          {
            //printf(" %d ", espacos[j]);
            combinacaoAtualVermelha[indice_aux2] = espacos[j];
            //printf(" %d ", combinacaoAtualVermelha[indice_aux2]);
            indice_aux2++;
          }
          else
          {
            if (indice_aux < (tamanho_comb-1))
            {
              indice_aux++;
            }
          }
        }
        //printf("] = ");

        
        // árvore correspondente
        indice_aux = 0;
        //printf("[");
        for (int k=0; k<=(tamanho_arvore-1); k++)
        {
          if (k == combinacaoAtualAzul[indice_aux])
          {
            arvore[k] = 'A';
            if (indice_aux < (tamanho_comb-1))
            {
              indice_aux++;
            }
          }
          else
          {
            arvore[k] = 'V';
          }
          //printf(" %c ", arvore[k]);
        } 
        //printf("]");
      }


      // validando árvores
      parar_iteracao1 = 0;
      for (int i=0; i<=(qA-2); i++)
      {
        for (int j=(i+1); j<=(qA-1); j++)
        {
          if(m[ combinacaoAtualAzul[i] ][ combinacaoAtualAzul[j] ] == 1)
          {
            parar_iteracao1 = 1;
            break;
          }
        } 
        if(parar_iteracao1 == 1)
        {
          break;
        }
      }

      if(parar_iteracao1 == 0)
      {
        parar_iteracao2 = 0;
        for (int i=0; i<=(qV-2); i++)
        {
          for (int j=(i+1); j<=(qV-1); j++)
          {
            if(m[ combinacaoAtualVermelha[i] ][ combinacaoAtualVermelha[j] ] == 1)
            {
              parar_iteracao2 = 1;
              break;
            }
          }
          if(parar_iteracao2 == 1)
          {
            break;
          }
        }
      }

      if ((parar_iteracao1 == 0) && (parar_iteracao2 == 0))
      {
        // árvore correspondente
        printf("[");
        for (int k=0; k<=(tamanho_arvore-1); k++)
        {
          printf(" %c ", arvore[k]);
        }
        printf("] ");
        printf(" Arvore VALIDA\n");
        *PPparar_programa = 1;
      }
      /*else
      {
        printf(" Arvore invalida\n");
      }*/    

    }
    return;
  }

  // gera a combinação atual
  for (int i=inicio; i<=fim && (fim-i+1)>=(qA-indice); i++)
  {
    combinacaoAtualAzul[indice] = espacos[i];
    //inicio = i+1; ----> não sei porque não funcionou assim
    //indice = indice + 1; ----> não sei porque não funcionou assim
    if (*PPparar_programa == 0)
    {
      gerarArvore(espacos, combinacaoAtualAzul, i+1, fim, indice+1, qA, qE, m, PPparar_programa);
    }
  }
}




