#include "../include/set_generator.h"
#include <iostream>
#include <vector>

#define MAX_SIZE 1e1

void partition(std::vector<int> &A, int l, int r, int *i, int *j) {
  *i = l;
  *j = r;
  int pivot = A[(*i + *j) / 2];

  do {
    while (A[*i] < pivot) {
      (*i)++;
    }

    while (A[*j] > pivot) {
      (*j)--;
    }

    if (*i <= *j) {
      int aux;
      aux = A[*i];
      A[*i] = A[*j];
      A[*j] = aux;
      (*i)++;
      (*j)--;
    }
  } while (*i <= *j);
}

void quickSort(std::vector<int> &A, int l, int r) {
  int i, j;
  partition(A, l, r, &i, &j);

  if (l < j) {
    quickSort(A, l, j);
  }

  if (r > i) {
    quickSort(A, i, r);
  }
}

void insertionSort(std::vector<int> &v, int l, int r) {
  for (int i = l + 1; i < r; i++) {
    int aux = v[i];
    int j = i - 1;

    while (j >= 0 && aux < v[j]) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = aux;
  }
}

void quickSortIns(std::vector<int> &A, int l, int r) {
  int i, j;
  int size = r - l;

  if (size <= 30) {
    insertionSort(A, l, r + 1);
  } else {
    partition(A, l, r, &i, &j);

    if (l < j) {
      quickSortIns(A, l, j);
    }

    if (r > i) {
      quickSortIns(A, i, r);
    }
  }
}

void print_vector(std::vector<int> &v) {
  for (const auto &element : v) {
    std::cout << element << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char *argv[]) {

  SetGenerator *unordered_set = new SetGenerator(MAX_SIZE);

  std::vector<int> v =
      unordered_set->parse_set_vector(unordered_set->generate_set());

  std::vector<int> a = v;
  std::vector<int> b = v;

  quickSortIns(v, 0, v.size() - 1);

  print_vector(v);

  return 0;
}
