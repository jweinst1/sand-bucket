#include "utils-funcs.h"

constexpr size_t bitCountNoIntrsics(size_t number) {
	size_t bitCount = 0;
	for (size_t i = 0; i < 64; ++i)
	{
		bitCount += (number >> i) & 1;
	}
	return bitCount;
}