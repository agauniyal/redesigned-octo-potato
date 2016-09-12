#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <chrono>
#include <iomanip>

#include "genId.hpp"
#include "rang.hpp"

genId::stats genId::generate(
  const unsigned int numTimes, const unsigned int len)
{
	unsigned int duplicates = 0;
	std::vector<std::string> v;
	v.resize(numTimes);

	const char alphabet[]
	  = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	char shortId[10] = "";
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 61);

	auto t1 = std::chrono::high_resolution_clock::now();

	for (unsigned int l = 0; l < numTimes; l++) {
		for (unsigned int i = 0; i < len; i++) {
			shortId[i] = alphabet[dis(gen)];
		}
		if (std::find(v.begin(), v.end(), shortId) != v.end()) {
			++duplicates;
		} else {
			v.push_back(shortId);
		}
	}

	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration
	  = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

	return std::make_pair(duplicates, duration);
}

void genId::printer(unsigned int first, unsigned int second, genId::stats s)
{
	std::cout << rang::fg::gray << rang::style::bold << "["
	          << rang::style::reset << rang::fg::yellow << std::left
	          << std::setw(10) << first << std::setw(2) << second
	          << rang::style::reset << rang::fg::gray << rang::style::bold
	          << "]" << rang::style::reset;

	std::cout << "\tDuplicates: " << rang::style::bold << rang::fg::red
	          << std::setw(3) << s.first << rang::style::reset
	          << "\tExecution(us) : " << rang::style::bold << rang::fg::magenta
	          << std::setw(10) << s.second << rang::style::reset << "\n";
}

genId::seqContainer genId::make_sequence(
  unsigned int power, unsigned int range, unsigned int skip)
{
	genId::seqContainer result;
	if (power > 1 || range > 1 || skip > 0 || skip < range) {
		unsigned int limit = 10;
		for (unsigned int i = 1; i < power; ++i) {
			limit *= 10;
		}

		for (unsigned int i = 10; i < limit; i *= 10) {
			for (unsigned int j = skip; j <= range; ++j) {
				result.emplace_back(i, j);
			}
		}
	}
	return result;
}
