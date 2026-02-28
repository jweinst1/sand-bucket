#ifndef KEY_BLOCK_HEADER
#define KEY_BLOCK_HEADER

#include "murmur3.h"

template<size_t tableSize>
struct KeyBlock {
	static constexpr size_t blockMask = tableSize - 1;
};

#endif // KEY_BLOCK_HEADER