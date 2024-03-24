#include <chrono>
#include <cmath>
#include <iostream>

unsigned int FibIter(unsigned int n) {
  unsigned int i = 1, k, F = 0;
  for (k = 1; k <= n; k++) {
    F += i;
    i = F - i;
  }
  return F;
}

void iterative_fib() {
  unsigned int i = 1, k, count = 0;
  unsigned long long int a = 0, b = 1;

  std::cout << "Function is executing..." << std::endl;
  std::chrono::steady_clock::time_point start =
      std::chrono::steady_clock::now();

  std::chrono::steady_clock::time_point end = start + std::chrono::seconds(120);

  while (std::chrono::steady_clock::now() < end) {
    unsigned long long int next = a + b;
    a = b;
    b = next;

    count++;
  }

  std::cout << count << std::endl;
  std::cout << "Function execution complete." << std::endl;
}

unsigned long long int fibCount = 0;

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
    fibCount++;
  }
}

int main() {
  int executionTimeInSeconds = 5;

  // iterative_fib();

  recursive_fib_with_time_limit(10);

  // std::cout << "Execution stopped after " << executionTimeInSeconds
  //           << " seconds." << std::endl;

  // std::cout << FibIter(5) << std::endl;

  return 0;
}
