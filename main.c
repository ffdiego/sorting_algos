#include <stdio.h>
#include "sorting.h"

int main(int argc, char *argv[]) {
  if(argc != 3) {
    printf("Usage:\n\tsorter SAMPLE_SIZE ALGORYTHM\n");
    return 0;
  }

  unsigned int n = atoi(argv[1]);
  unsigned int algo = atoi(argv[2]);

  printf("| size: %d | algo: %d |\n", n, algo);
  

  int *v = calloc(n, sizeof(int)); 
  fill_random_values(v, n);

  switch (algo)
  {
  case 1:
    printf("Bubble Sort\n");
    bubble_sort(v, n);
    break;
  case 2:
    printf("Insertion Sort\n");
    insertion_sort(v, n);
    break;
  case 3:
    printf("Selection Sort\n");
    selection_sort(v, n);
    break;
  case 4:
    printf("Merge Sort\n");
    merge_sort(v, 0, n);
    break;
  default:
    printf("ERROR: Invalid Sorting Algorythm %d\n", algo);
    return 1;
    break;
  }

  if(n <= 10)
    print_vector(v, n);

  return 0;
}