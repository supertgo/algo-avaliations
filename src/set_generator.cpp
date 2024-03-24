#include "../include/set_generator.h"
#include <cstdlib>

SetGenerator::SetGenerator(unsigned int size) { this->size = size; }

const std::unordered_set<int> SetGenerator::generate_set() {
  std::srand(time(0));

  std::unordered_set<int> random_int_set;

  while (random_int_set.size() != this->size) {
    random_int_set.insert(std::rand());
  }

  return random_int_set;
}

std::vector<int>
SetGenerator::parse_set_vector(std::unordered_set<int> random_int_set) {
  std::vector<int> v;
  v.reserve(random_int_set.size());

  std::copy(random_int_set.begin(), random_int_set.end(),
            std::back_inserter(v));

  return v;
}
