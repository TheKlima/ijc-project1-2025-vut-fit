// File: bitset.c
// Subject: IJC
// Project: #1
// Author: Andrii Klymenko, FIT VUT
// Login: xklyme00
// Date: 3.2.2025
// Compiled: gcc version 11.4.0

#ifdef USE_INLINE

#include "bitset.h"
#include <stdbool.h>

// declarations of the inline functions
extern inline void bitset_free(bitset_t bitset);
extern inline bitset_index_t bitset_size(bitset_t bitset);
extern inline void bitset_fill(bitset_t bitset, bool expr);
extern inline void bitset_setbit(bitset_t bitset, bitset_index_t idx, bool expr);
extern inline int bitset_getbit(bitset_t bitset, bitset_index_t idx);

#endif // USE_INLINE
