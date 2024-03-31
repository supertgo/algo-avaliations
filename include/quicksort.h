#ifndef QUICKSORT_HH
#define QUICKSORT_HH

class Quicksort {
public:
  void partition(int *v, int l, int r, int *i, int *j);
  void quicksort(int *v, int l, int r);
  void insertionsort(int *v, int l, int r);
  void quicksort_ins(int *v, int l, int r);
  void iterative_quicksort(int *v, int left, int right);
  void iterative_quicksort_ins(int *v, int left, int right);
};

#endif //  QUICKSORT_HH
