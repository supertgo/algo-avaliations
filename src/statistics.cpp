#include "statistics.h"
#include <string>

Statistics::Statistics(int size) {
  this->size = size;
  this->data = new float[size];
}

Statistics::~Statistics() { delete this->data; }

float Statistics::mean() {
  float acc = 0;
  for (int i = 0; i < this->size; i++) {
    acc += this->data[i];
  }

  return acc / this->size;
}

void Statistics::register_data(float x, int pos) { this->data[pos] = x; }

float Statistics::variance(float mean) {
  float acc = 0;

  for (int i = 0; i < this->size; i++) {
    acc += (this->data[i] - mean) * (this->data[i] - mean);
  }

  return acc / (this->size - 1);
}

void Statistics::print_metrics(std::string method) {
  float mean = this->mean();
  float standart_deviation = std::sqrt(this->variance(mean));

  std::cout << "O método " << method << " teve média de " << mean
            << " milisegundos e desvio padrão de " << standart_deviation
            << std::endl;
}
