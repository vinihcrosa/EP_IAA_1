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
 *  2 - arquivo de vetores a ser analisado 
 * @param argv 
 * @return int 
 */
int main(int argc, char **argv)
{

  int iesimo = atoi(argv[1]);
  FILE *file = fopen(argv[2], "r");
  if (!file)
  {
    printf("Error: nao foi possivel abrir o arquivo %s", argv[2]);

    return -1;
  }
  int tamanho;
  fscanf(file, "%d", &tamanho);
  int *vetor = malloc(tamanho * sizeof(int));
  for (int i = 0; i < tamanho; i++)
    fscanf(file, "%d", &vetor[i]);
  fclose(file);

  FILE *dados = fopen(argv[3], "a");

  bubble_sort(vetor, tamanho);

  //print_array(vetor, tamanho);

  int tempoInicio, tempoSelecao1, tempoSelecao2;

  tempoInicio = clock();

  Selecao2(vetor, tamanho / 2, 0, tamanho);

  tempoSelecao2 = clock() - tempoInicio;

  tempoInicio = clock();
  selecao1(vetor, tamanho / 2, tamanho);

  tempoSelecao1 = clock() - tempoInicio;

  fprintf(dados, "%d, %d\n", tempoSelecao1, tempoSelecao2);
  fclose(dados);

  printf("%d, %d\n", tempoSelecao1, tempoSelecao2);
  return 0;
}