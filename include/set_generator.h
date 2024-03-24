#include <unordered_set>
#include <vector>

class SetGenerator {
public:
  SetGenerator(unsigned int size);
  const std::unordered_set<int> generate_set();
  std::vector<int>
  parse_set_vector(const std::unordered_set<int> random_int_set);

private:
  unsigned int size;
};
