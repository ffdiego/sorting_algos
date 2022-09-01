#include "sorting.h"

void swap(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux; 
}

void fill_random_values(int v[], int size){
  srand(time(NULL)); //gets current time as random seed
  for(int i = 0; i < size; i++)
    v[i] = rand() % 100;
}

void print_vector(int v[], int size){
  for(int i = 0; i < size; i++)
    printf("[%d]", v[i]);
  printf("\n");  
}

void bubble_sort(int v[], int size) {
  int swapped;
  do{
    swapped = 0;
    for(int i = 0; i < size - 1; i++) {
      if(v[i] > v[i+1]){
        swap(&v[i], &v[i+1]);
        swapped = 1;
      }
    }
  } while (swapped);
}

void insertion_sort(int v[], int size) {
  int i, j, selected;
  for(i = 0; i < size; i++) {
    selected = v[i];
    j = i - 1;
    while (j >= 0 && v[j] > selected)
    {
      v[j+1] = v[j];
      j = j - 1;
    }
    v[j+1] = selected;
  }
}

void selection_sort(int v[], int size) {
  int i, j, aux, min;
  for(i = 0; i < size - 1; i++) {
    min = i;
    for(j = i+1; j < size; j++)
      if(v[j] < v[min]) 
        min = j;
    
    if(i != min) {
      swap(&v[i], &v[min]);
    }
  }
}

void merge(int v[], int comeco, int meio, int fim) {
  int i = 0;

  int esquerda = comeco;
  int direita = meio + 1;
  
  int size = fim - comeco + 1;
  int *vAux = calloc(size, sizeof(int));

  while (esquerda <= meio && direita <= fim){
    if(v[esquerda] < v[direita]) {
      vAux[i] = v[esquerda];
      esquerda++;
    } else {
      vAux[i] = v[direita];
      direita++;
    }
    i++;
  }

  while (esquerda <= meio)
  {
    vAux[i] = v[esquerda];
    i++;
    esquerda++;
  }
  while (direita <= fim)
  {
    vAux[i] = v[direita];
    i++;
    direita++;
  }
  for (i = comeco; i <= fim; i++)
  {
    v[i] = vAux[i - comeco];
  }
  
  free(vAux);
}

void merge_sort(int v[], int start, int end) {
  if (start < end) {
    int mid = (start + end) / 2;

    merge_sort(v, start, mid);
    merge_sort(v, mid+1, end);
    merge(v, start, mid, end);
  }
}