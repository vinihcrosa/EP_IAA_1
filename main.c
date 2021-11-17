#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "iesimo.h"

#define FALSE 0
#define TRUE 1

/**
 * @brief 
 * 
 * @param argc
 *  1 - iesimo numero
 *  2 - tamanho do vetor a ser analisado 
 * @param argv 
 * @return int 
 */
int main(int argc, char **argv)
{

  int iesimo = atoi(argv[1]);
  int tamanho = atoi(argv[2]);
  int *vetor = cria_vetor(tamanho);
  srand(time(NULL));
  for (int i = 0; i < tamanho; i++)
    vetor[i] = rand();

  FILE *dados = fopen(argv[3], "a");

  bubble_sort(vetor, tamanho);


  int tempoInicio, tempoSelecao1, tempoSelecao2;

  tempoInicio = clock();

  int sel2 = Selecao2(vetor, iesimo, 0, tamanho);

  tempoSelecao2 = clock() - tempoInicio;

  tempoInicio = clock();
  int sel1 = selecao1(vetor, iesimo, tamanho);

  tempoSelecao1 = clock() - tempoInicio;

  fprintf(dados, "%d, %d\n", tempoSelecao1, tempoSelecao2);
  fclose(dados);
  
  free(vetor);

  printf("%d, %d\n", tempoSelecao1, tempoSelecao2);
  return 0;
}