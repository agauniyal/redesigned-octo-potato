#include "rang.hpp"
#include "genId.hpp"

int main(int argc, char **argv)
{
	if (argc < 3 || argc > 4) {
		std::cerr << rang::fg::red << rang::style::bold
		          << "wrong arguments provided\n"
		          << "usage: program <seq> <range> <skip>\n"
		          << rang::style::reset;
		return -1;
	}

	unsigned int seq   = std::atoi(argv[1]);
	unsigned int range = std::atoi(argv[2]);
	unsigned int skip  = 0;
	if (argc == 4) {
		skip = std::atoi(argv[3]);
	}

	std::cout << rang::fg::blue << rang::style::bold
	          << "\nPreparing to start Benchmarks\n"
	          << rang::style::reset << std::endl;

	genId::seqContainer sequence;
	sequence = genId::make_sequence(seq, range, skip);

	for (size_t i = 0; i < sequence.size(); ++i) {
		auto stats = genId::generate(sequence[i].first, sequence[i].second);
		genId::printer(sequence[i].first, sequence[i].second, stats);
	}
	std::cout << rang::fg::blue << rang::style::bold
	          << "\nFinished execution\n\n"
	          << rang::style::reset;
}
