#include "quicksort.h"
#include "statistics.h"
#include <chrono>

#define MAX_SIZE 10000

int main(int argc, char *argv[]) {
  std::srand(time(0));

  Quicksort quick;

  Statistics *statRecursive = new Statistics(50);
  Statistics *statRecursiveIns = new Statistics(50);
  Statistics *statIterative = new Statistics(50);
  Statistics *statIterativeIns = new Statistics(50);

  for (int i = 0; i < 50; i++) {
    int quick_recursive[MAX_SIZE];

    for (int j = 0; j < MAX_SIZE; j++) {
      quick_recursive[j] = std::rand();
    }

    int quick_recursive_ins[MAX_SIZE];
    int quick_iterative[MAX_SIZE];
    int quick_iterative_ins[MAX_SIZE];

    std::copy(quick_recursive, quick_recursive + MAX_SIZE, quick_recursive_ins);
    std::copy(quick_recursive, quick_recursive + MAX_SIZE, quick_iterative);
    std::copy(quick_recursive, quick_recursive + MAX_SIZE, quick_iterative_ins);

    auto start_recursive = std::chrono::high_resolution_clock::now();
    quick.quicksort(quick_recursive, 0, MAX_SIZE - 1);
    auto stop_recursive = std::chrono::high_resolution_clock::now();

    auto start_recursive_ins = std::chrono::high_resolution_clock::now();
    quick.quicksort_ins(quick_recursive_ins, 0, MAX_SIZE - 1);
    auto stopRecursiveIns = std::chrono::high_resolution_clock::now();

    auto start_iterative = std::chrono::high_resolution_clock::now();
    quick.iterative_quicksort(quick_iterative, 0, MAX_SIZE - 1);
    auto stop_iterative = std::chrono::high_resolution_clock::now();

    auto start_iterative_ins = std::chrono::high_resolution_clock::now();
    quick.iterative_quicksort_ins(quick_iterative_ins, 0, MAX_SIZE - 1);
    auto stop_iterative_ins = std::chrono::high_resolution_clock::now();

    auto duration_recursive =
        std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(
            stop_recursive - start_recursive);

    auto duration_recursive_ins =
        std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(
            stopRecursiveIns - start_recursive_ins);

    auto duration_iterative =
        std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(
            stop_iterative - start_iterative);

    auto duration_iterative_ins =
        std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(
            stop_iterative_ins - start_iterative_ins);

    statRecursive->register_data(duration_recursive.count(), i);
    statRecursiveIns->register_data(duration_recursive_ins.count(), i);
    statIterative->register_data(duration_iterative.count(), i);
    statIterativeIns->register_data(duration_iterative_ins.count(), i);
  }

  statRecursive->print_metrics("Quicksort recursivo");
  statRecursiveIns->print_metrics("Quicksort recursivo com inserção");
  statIterative->print_metrics("Quicksort iterativo");
  statIterativeIns->print_metrics("Quicksort iterativo com inserção");

  return 0;
}
