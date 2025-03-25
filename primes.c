// File: primes.c
// Subject: IJC
// Project: #1
// Author: Andrii Klymenko, FIT VUT
// Login: xklyme00
// Date: 3.2.2023
// Compiled: gcc version 11.4.0

#include <stdio.h>
#include <time.h>
#include "bitset.h"
#include "eratosthenes.h"

#define MAX_SIZE 333000000  // max size of the array of bits
#define LAST_CNT 10        // number of needed prime numbers

void printBitSet(bitset_t bitset)
{
    int i = 0;
    for( ; (bitset_index_t) i < bitset[0] / (sizeof(bitset_index_t) * 8); ++i)
    {
        printf("%lx ", bitset[i + 1]);
    }
    if(bitset[0] % (sizeof(bitset_index_t) * 8) != 0) printf("%lx ", bitset[i + 1]);
    putchar('\n');
}

int main()
{
    time_t start = clock();

    bitset_create(arr, MAX_SIZE);
    Eratosthenes(arr);

    bitset_index_t primes[LAST_CNT];
    bitset_index_t count = 0;

    for(bitset_index_t i = MAX_SIZE - 1; count < LAST_CNT; --i)
    {
        if(bitset_getbit(arr, i))
        {
            primes[count++] = i;
        }
    }

    for(int i = LAST_CNT - 1; i >= 0; --i)
    {
        printf("%ld\n", primes[i]);
    }

    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
    return 0;
}
