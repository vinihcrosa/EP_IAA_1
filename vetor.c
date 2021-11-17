#include <stdio.h>
#include <stdlib.h> // necessário p/ as funções rand() e srand()
#include <time.h>   //necessário p/ função time()
#define FALSE 0
#define TRUE 1

/**
 * @brief 
 * 
 * @param argc 
 *  1 - numero de elementos
 *  2 - nome do arquivo de saida
 * @param argv 
 * @return ** int 
 */
int main(int argc, char **argv)
{
  /**
   * @todo 
   *  sanitizacao de entrada
   */
  int tamanho = atoi(argv[1]);

  srand(clock());

  int *vetor = malloc(tamanho * sizeof(int));
  int i = 0;
  for (i = 0; i < tamanho; i++)
  {
    vetor[i] = rand();
  }

  FILE *file = fopen(argv[2], "w");

  fprintf(file, "%d\n", tamanho);
  for (i = 0; i < tamanho; i++)
  {
    fprintf(file, "%d\n", vetor[i]);
  }
  fclose(file);
}
