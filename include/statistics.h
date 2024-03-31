#include <cmath>
#include <iostream>
#include <string>

#ifndef STATISTICS

class Statistics {
public:
  Statistics(int size);
  ~Statistics();
  void print_metrics(std::string method);
  void register_data(float x, int pos);

private:
  int size;
  float *data;
  float mean();
  float variance(float mean);
};

#endif // STATISTICS
