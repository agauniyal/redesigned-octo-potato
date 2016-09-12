#include <utility>
#include <vector>

namespace genId {

using stats        = std::pair<unsigned int, long>;
using seqContainer = std::vector<std::pair<unsigned int, unsigned int>>;
using u_int        = unsigned int;

seqContainer make_sequence(const u_int = 5, const u_int = 8, const u_int = 3);

stats generate(const u_int = 10, const u_int = 10, const char[]
  = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

void printer(const u_int, const u_int, const genId::stats);
}
