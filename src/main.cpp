#include <chrono>
#include <cmath>
#include <iostream>

unsigned long int recursive_fib_count = 0;
unsigned long long int iterative_fib_count = 0;

unsigned int iterative_fib(unsigned int n) {
  unsigned int i = 1, k, F = 0;
  for (k = 1; k <= n; k++) {
    F += i;
    i = F - i;
  }
  return F;
}

void call_iterative_fib(int seconds) {
  std::chrono::steady_clock::time_point start =
      std::chrono::steady_clock::now();

  std::chrono::steady_clock::time_point end =
      start + std::chrono::seconds(seconds);

  int ith_fib = 1;

  while (std::chrono::steady_clock::now() < end) {
    iterative_fib(ith_fib);
    ith_fib++;
    iterative_fib_count++;
  }
}

unsigned long long int
fibonacciWithTimeLimit(int n, std::chrono::steady_clock::time_point end) {
  if (std::chrono::steady_clock::now() >= end) {
    return 0;
  }

  if (n <= 1)
    return n;
  return fibonacciWithTimeLimit(n - 1, end) +
         fibonacciWithTimeLimit(n - 2, end);
}

void recursive_fib_with_time_limit(int seconds) {
  std::chrono::steady_clock::time_point start =
      std::chrono::steady_clock::now();

  std::chrono::steady_clock::time_point end =
      start + std::chrono::seconds(seconds);

  unsigned int n = 1;
  while (fibonacciWithTimeLimit(n, end) != 0) {
    n++;
    recursive_fib_count++;
  }
}

int main() {

  for (int s = 15; s <= 120; s += 15) {

    recursive_fib_with_time_limit(s);
    call_iterative_fib(s);

    std::cout << "Recursivo " << recursive_fib_count << std::endl;

    std::cout << "Iterativo " << iterative_fib_count << std::endl;

    recursive_fib_count = iterative_fib_count = 0;
  }

  return 0;
}
