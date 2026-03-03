#ifndef KEY_BLOCK_HEADER
#define KEY_BLOCK_HEADER

#include "murmur3.h"
#include "utils-funcs.h"



template<size_t tableSize>
struct KeyBlock {
	static constexpr size_t bitCount = bitCountNoIntrsics(tableSize);
	static_assert(bitCount == 1, "Table size must be power of two");
	static constexpr size_t blockMask = tableSize - 1;
};

#endif // KEY_BLOCK_HEADER