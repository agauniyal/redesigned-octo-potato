#include <utility>
#include <vector>

namespace genId {

using stats        = std::pair<unsigned int, long>;
using seqContainer = std::vector<std::pair<unsigned int, unsigned int>>;

seqContainer make_sequence(
  const unsigned int = 5, const unsigned int = 8, const unsigned int = 3);

stats generate(const unsigned int = 10, const unsigned int = 10);

void printer(const unsigned int, const unsigned int, const genId::stats);
}
