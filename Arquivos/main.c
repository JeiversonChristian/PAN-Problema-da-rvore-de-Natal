// gcc -o main main.c gerarCombinacao.c gerarArvore.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "gerarCombinacao.h"

int main ()
{

  // Explicação da função que controla o tempo de execução--------------------------------------------

  //time.h -> biblioteca
  // clock_t t0, tf; -> tempo inicial e final
  //t0 = clock(); -> tempo inical
  //tf = clock();
  // double tempo_gasto; 
  //tempo_gasto = ((double) (tf - t0))/CLOCKS_PER_SEC;
  //printar tempo gasto

  clock_t t0, tf;
  double tempo_gasto;
  t0 = clock();

    
  // Construindo matriz de adjacências--------------------------------------------------------------

  // quantidade de espaços das árvores de natal
  int qE;

  FILE* arquivo_adjacencias; 

  int maior = -1; // guardará o maior número do arquivo
  int num; // numero do arquivo de texto como inteiro
  char cNum[2]; // numero do arquivo de texto como caractere



  // guarda o maior número do arquivo
  arquivo_adjacencias = fopen("entrada.txt", "r");

  do
  { 
    fscanf(arquivo_adjacencias, "%s", cNum);
    num = strtol(cNum, NULL, 10); // converte para inteiro na base decimal
    if(num > maior)
    {
      maior = num;
    }

  } while (!feof(arquivo_adjacencias));
  fclose(arquivo_adjacencias);


  // a quantidade de espaços da árvore será definida pelo maior número do arquivo
  // Pois a matriz deve ser de dimensão qE x qE
  qE = maior + 1;


  // matriz que armazena as adjacências entre os qE espaços da árvore de natal
  int m[qE][qE];


  int linha_matriz; // vai guardar os números das linhas da matriz
  int ja_setou_linha = 0;// para verificar se já guardou o primeiro nº da linha 
  char palavra_verificadora_final;  // para verificar se foi guardado '\n'
  

  // preenchendo a matriz de adjacências

  arquivo_adjacencias = fopen("entrada.txt", "r");
  do
  {        
    fscanf(arquivo_adjacencias, "%s", cNum);
    num = strtol(cNum, NULL, 10);
    palavra_verificadora_final = fgetc(arquivo_adjacencias);
    

    // se não não é a primeira vez na linha, coloca o número 2 na matriz usando a informação da "linha_matriz"
    if (ja_setou_linha == 1)
    {
      m[linha_matriz][num] = 2; // gambiarra
    }

    // se é a primeira vez na linha, o seu primeiro número é guardado em "linha_matriz"
    if (ja_setou_linha == 0)
    {
      linha_matriz = num;
      ja_setou_linha = 1;  
    } 

    // se chegou no final da linha, a próxima será uma nova
    if (palavra_verificadora_final == '\n')
    {
      ja_setou_linha = 0;
    }           

  }
  while (!feof(arquivo_adjacencias));
  fclose(arquivo_adjacencias);  


  // preenche o resto da matriz e troca os 2's para 1's
  for (int i=0; i<=(qE-1); i++)
  {
    for (int j=0; j<=(qE-1); j++)
    {
      if (i == j) // digagonal principal
      {
        m[i][j] = -1;
      }
      if (m[i][j] != 2 && i != j) // se nao for "2" e nao tiver na diagonal principal
      {
        m[i][j] = 0;
      }
      else
      {
        if (m[i][j] == 2) // gambiarra -> mudar para 1
        {
          m[i][j] = 1;   
        }
        //else
        //{
          //if (i == j) // digagonal principal
          //{
            //m[i][j] = -1;
          //}
        //}
      }
    }
  }

  
  // printa a matriz
  printf("\n                     | Matriz de adjacencias |                     \n");
  printf("\n");
  for (int i=0; i<=(qE-1); i++)
  {
    for (int j=0; j<=(qE-1); j++)
    {
      if (m[i][j] != -1)
      {
        printf("| %d|", m[i][j]);
      }
      else
      {
        printf("|%d|", m[i][j]);
      }
    }
    printf("\n");
  }
  


  // ÁRVORES -----------------------------------------------------------------------------

  // vetor que guarda os números correspondentes aos espaços das árvores de natal
  int espacos[qE];

  // preenchendo espacos[n]: {0, 1, 2, ..., qE-1}
  for (int i=0; i<=(qE-1); i++)
  {
    espacos[i] = i;
  }


  // quantidade de cores Azuis presentes nas árvores de natal
  int qA;

  printf("----------------------------------------------------------------------------------------------------------------------\n");
  printf("             Verificando se ha arvores validas:\n");
  printf("(Obs. Se nao foi mostrada nenhuma arvore, entao nao houve nenhuma valida)\n");
  printf("\n\nCansado de esperar? Aperte Ctrl + C para encerrar o programa.\n\n\n");


  int parar_programa = 0;
  int *Pparar_programa = NULL;
  Pparar_programa = &parar_programa;

  // será gerada uma combinacao de inteiros que definará cada árvore de natal
  // e, para cada árvore gerada, será verificada se ela é uma árvore aceita
  // de acordo com os parâmetros
  // se ela for aceita, a mostraremos

  //printf("\n"------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
  for (int i=0; i<=qE; i++)
  {
    qA = i;
    //printf("Arvores de Natal com %d cores Azuis:\n", qA);
    if (parar_programa == 0)
    {
      gerarCombinacao(espacos, qE, qA, m, Pparar_programa);
    }
    if (parar_programa == 1)
    {
      break;
    }
    //printf("--------------------------------------------------------------------------------------\n");
  }

  tf = clock();
  tempo_gasto = ((double) (tf - t0))/CLOCKS_PER_SEC;
  printf("\nPrograma terminado!");
  printf("\nO tempo de execucao foi: %lfs\n", tempo_gasto);
  printf("----------------------------------------------------------------------------------------------------------------------\n");

  return 0;
}
