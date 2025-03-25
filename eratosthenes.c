// File: eratosthenes.c
// Subject: IJC
// Project: #1
// Author: Andrii Klymenko, FIT VUT
// Login: xklyme00
// Date: 3.2.2023
// Compiled: gcc version 11.4.0

#include <math.h>
#include "bitset.h"
#include "eratosthenes.h"

// implementation of sieve of Eratosthenes algorithm
void Eratosthenes(bitset_t arr)
{
    bitset_index_t arr_size = bitset_size(arr);
    bitset_fill(arr, arr_size);

    bitset_setbit(arr, 0, false); // 0 is not a prime number
    bitset_setbit(arr, 1, false); // 1 is not a prime number

    double loops_number = sqrt((double) arr_size);
    for(bitset_index_t i = 2; i < (bitset_index_t) loops_number; ++i)
    {
        if(bitset_getbit(arr, i))
        {
            for(bitset_index_t j = 2 * i; j < arr_size; j += i)
            {
                bitset_setbit(arr, j, false);
            }
        }
    }
}