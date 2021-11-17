#include "iesimo.h"
#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b)
{
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void bubble_sort(int *array, int size)
{
  int i, j;
  for (i = 0; i < size; i++)
    for (j = size; j > i + 1; j--)
      if (array[j - 1] < array[j - 2])
        troca(&array[j - 1], &array[j - 2]);
}

void print_array(int *array, int size)
{
  int i;
  for (i = 0; i < size; i++)
    printf("%i ", array[i]);
  printf("\n");
}

int partition(int *array, int inicio, int fim)
{
  int pivot = array[fim - 1];
  int i = -1;
  int j;

  for (j = inicio; j < fim - 1; j++)
    if (array[j] <= pivot)
      troca(&array[++i], &array[j]);
  troca(&array[i + 1], &array[j]);

  return i + 1;
}

int Selecao2(int *array, int i, int inicio, int fim)
{

  int q = partition(array, inicio, fim);
  if (inicio - fim == 0)
  {
    return array[inicio - 1]; // TESTAR COM 0 E 1
  }

  if (i < q)
  {
    return Selecao2(array, i, inicio, q - 1);
  }
  else if (i > q)
  {
    return Selecao2(array, i - (q + 1), q + 1, fim);
  }
  else
  {
    return array[q - 1];
  }
}

int selecao1(int *array, int i, int tamanho)
{
  mergesort2(array, tamanho);
  return array[i - 1];
}

/*
  Dado um vetor de inteiros v e um inteiro n >= 0, ordena o vetor v[0..n-1] em ordem crescente.
*/
void mergesort2(int *v, int n)
{
  int *c = malloc(sizeof(int) * n);
  sort(v, c, 0, n - 1);
  free(c);
}

/*
  Dado um vetor de inteiros v e dois inteiros i e f, ordena o vetor v[i..f] em ordem crescente.
  O vetor c é utilizado internamente durante a ordenação.
*/
void sort(int *v, int *c, int i, int f)
{
  if (i >= f)
    return;

  int m = (i + f) / 2;

  sort(v, c, i, m);
  sort(v, c, m + 1, f);

  /* Se v[m] <= v[m + 1], então v[i..f] já está ordenado. */
  if (v[m] <= v[m + 1])
    return;

  merge(v, c, i, m, f);
}

/*
  Dado um vetor v e três inteiros i, m e f, sendo v[i..m] e v[m+1..f] vetores ordenados,
  coloca os elementos destes vetores, em ordem crescente, no vetor em v[i..f].
*/
void merge(int *v, int *c, int i, int m, int f)
{
  int z,
      iv = i, ic = m + 1;

  for (z = i; z <= f; z++)
    c[z] = v[z];

  z = i;

  while (iv <= m && ic <= f)
  {
    /* Invariante: v[i..z] possui os valores de v[iv..m] e v[ic..f] em ordem crescente. */

    if (c[iv] <= c[ic])
      v[z++] = c[iv++];
    else
      v[z++] = c[ic++];
  }

  while (iv <= m)
    v[z++] = c[iv++];

  while (ic <= f)
    v[z++] = c[ic++];
}

int* cria_vetor(int size){
  int* vetor = malloc(size * sizeof(int));
  return vetor;
}

