#pragma once
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void bubble_sort(int v[], int size);
void insertion_sort(int v[], int size);
void selection_sort(int v[], int size);
void merge_sort(int v[], int start, int end);


void fill_random_values(int v[], int size);
void swap(int*, int*);
void print_vector(int v[], int size);
