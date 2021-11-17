#ifndef IESIMO_H
#define IESIMO_H

void troca(int *a, int *b);

void bubble_sort(int *array, int size);

void print_array(int *array, int size);

int partition(int *array, int inicio, int fim);

int selecao1(int *array, int i, int tamanho);

int Selecao2(int *array, int i, int inicio, int fim);

void mergesort2(int *v, int n);
void sort(int *v, int *c, int i, int f);
void merge(int *v, int *c, int i, int m, int f);
int* cria_vetor(int size);
#endif
