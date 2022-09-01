#include "sorting.h"

void swap(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux; 
}

void fill_random_values(int v[], int size){
  srand(time(NULL)); //gets current time as random seed
  int r = rand() % 100;
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
