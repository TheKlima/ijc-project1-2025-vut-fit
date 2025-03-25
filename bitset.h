// File: bitset.h
// Subject: IJC
// Project: #1
// Author: Andrii Klymenko, FIT VUT
// Login: xklyme00
// Date: 3.2.2025
// Compiled: gcc version 11.4.0

#ifndef BITSET_H
#define BITSET_H

#include "error.h"
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long *bitset_t; // array of bits
typedef unsigned long bitset_index_t; // index to array of bits

#define BITS_IN_UL (sizeof(bitset_index_t) * CHAR_BIT) // number of bits in 'unsigned long'
#define FIRST_ELEMENT 1 // first element of the bitset array is its size (in number of bits)

// defines and zeroes the variable 'arr_name'
#define bitset_create(arr_name, size) \
    static_assert(size > 0, "Error! Array size must be greater than 0"); \
    bitset_index_t arr_name[(FIRST_ELEMENT) + (size / BITS_IN_UL) + ((size % (BITS_IN_UL)) == 0 ? 0 : 1)] = {size}

// defines and zeroes the variable 'arr_name' using dynamic memory allocation
#define bitset_alloc(arr_name, size) \
    assert(size > 0);            \
    bitset_t arr_name = (bitset_t) calloc((FIRST_ELEMENT) + (size / BITS_IN_UL) + (size % (BITS_IN_UL) == 0 ? 0 : 1), \
        sizeof(bitset_index_t)); \
    if(arr_name == NULL) error_exit("bitset_alloc: Chyba alokace paměti\n");                          \
    arr_name[0] = size

#ifndef USE_INLINE

// frees memory of the dynamically allocated array
#define bitset_free(arr_name) free(arr_name)

// returns size of the array of bits in number of the bits
#define bitset_size(arr_name) (arr_name[0])

// resets or sets to 1 the entire contents of the array based on the value of the expression
#define bitset_fill(arr_name, expr) \
    memset(arr_name + 1, expr ? ULONG_MAX : 0, ((arr_name[0] / BITS_IN_UL) + (arr_name[0] % BITS_IN_UL == 0 ? 0 : 1)) * CHAR_BIT)

// sets the specified bit on the index 'idx' in the array to the value specified by the expression 'expr'
#define bitset_setbit(arr_name, idx, expr) \
    (idx >= bitset_size(arr_name)) ?                 \
        (error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu", (unsigned long)idx, bitset_size(arr_name)), 0) : \
        ((expr) ?                      \
        (arr_name[idx / BITS_IN_UL + FIRST_ELEMENT] |= (1UL << (idx % BITS_IN_UL))) : \
        (arr_name[idx / BITS_IN_UL + FIRST_ELEMENT] &= ~(1UL << (idx % BITS_IN_UL))))

// returns the value of the specified bit on the index 'idx' in the array
#define bitset_getbit(arr_name, idx) \
    ((idx >= bitset_size(arr_name)) ? \
        ((error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu", (unsigned long)idx, bitset_size(arr_name))), 0) : \
        ((arr_name[idx / BITS_IN_UL + FIRST_ELEMENT] >> ((idx % BITS_IN_UL))) & 1UL))

#else

// works in the same way as macro 'bitset_free'
inline void bitset_free(bitset_t arr_name)
{
    free(arr_name);
}

// works in the same way as macro 'bitset_size'
inline bitset_index_t bitset_size(bitset_t arr_name)
{
    return arr_name[0];
}

// works in the same way as macro 'bitset_fill'
inline void bitset_fill(bitset_t bitset, bool expr)
{
    memset(bitset + 1, expr ? ULONG_MAX : 0, ((bitset[0] / BITS_IN_UL) + (bitset[0] % BITS_IN_UL == 0 ? 0 : 1)) * CHAR_BIT);
}

// works in the same way as macro 'bitset_setbit'
inline void bitset_setbit(bitset_t arr_name, bitset_index_t idx, bool expr)
{
    (idx >= bitset_size(arr_name)) ?
        (error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu", (unsigned long)idx, bitset_size(arr_name)), 0) :
        ((expr) ?
        (arr_name[idx / BITS_IN_UL + FIRST_ELEMENT] |= (1UL << (idx % BITS_IN_UL))) :
        (arr_name[idx / BITS_IN_UL + FIRST_ELEMENT] &= ~(1UL << (idx % BITS_IN_UL))));
}

// works in the same way as macro 'bitset_getbit'
inline int bitset_getbit(bitset_t arr_name, bitset_index_t idx)
{
    return ((idx >= bitset_size(arr_name)) ?
        ((error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu", (unsigned long)idx, bitset_size(arr_name))), 0) :
        ((arr_name[idx / BITS_IN_UL + FIRST_ELEMENT] >> ((idx % BITS_IN_UL))) & 1UL));
}

#endif

#endif
