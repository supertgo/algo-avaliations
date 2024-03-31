#include "quicksort.h"

void Quicksort::partition(int *A, int l, int r, int *i, int *j) {
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

void Quicksort::quicksort(int *A, int l, int r) {
  int i, j;
  partition(A, l, r, &i, &j);

  if (l < j) {
    quicksort(A, l, j);
  }

  if (r > i) {
    quicksort(A, i, r);
  }
}

void Quicksort::insertionsort(int *v, int l, int r) {
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

void Quicksort::quicksort_ins(int *A, int l, int r) {
  int i, j;
  int size = r - l;

  if (size <= 30) {
    insertionsort(A, l, r + 1);
  } else {
    partition(A, l, r, &i, &j);

    if (l < j) {
      quicksort_ins(A, l, j);
    }

    if (r > i) {
      quicksort_ins(A, i, r);
    }
  }
}

void Quicksort::iterative_quicksort(int *v, int left, int right) {
  int stack[right - left + 1];
  int top = -1;

  stack[++top] = left;
  stack[++top] = right;

  while (top >= 0) {
    right = stack[top--];
    left = stack[top--];

    int i = left, j = right;

    partition(v, left, right, &i, &j);

    if (j > left) {
      stack[++top] = left;
      stack[++top] = j;
    }

    if (i < right) {
      stack[++top] = i;
      stack[++top] = right;
    }
  }
}
void Quicksort::iterative_quicksort_ins(int *v, int left, int right) {
  int stack[right - left + 1];
  int top = -1;

  stack[++top] = left;
  stack[++top] = right;

  while (top >= 0) {
    right = stack[top--];
    left = stack[top--];

    if (right - left + 1 <= 30) {
      insertionsort(v, left, right);
    } else {

      int i = left, j = right;

      partition(v, left, right, &i, &j);

      if (j > left) {
        stack[++top] = left;
        stack[++top] = j;
      }

      if (i < right) {
        stack[++top] = i;
        stack[++top] = right;
      }
    }
  }
}
