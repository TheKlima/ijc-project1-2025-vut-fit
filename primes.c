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

    // bitset_alloc(arr1, 23);
    // bitset_setbit(arr1, 22, 1);
    // // bitset_setbit(arr1, 23, 1);
    // // bitset_setbit(arr1, 24, 1);
    // // bitset_setbit(arr1, 26, 1);
    // // bitset_setbit(arr1, 25, 1);
    // bitset_setbit(arr1, -1, 1);
    // bitset_setbit(arr1, -2, 1);
    // bitset_setbit(arr1, -3, 1);
    // bitset_free(arr1);





    // bitset_alloc(arr1, 32);
    // bitset_alloc(arr2, 64);
    // printBitSet(arr1);
    // printBitSet(arr2);
    // bitset_fill(arr1, true);
    // bitset_fill(arr2, true);
    // printBitSet(arr1);
    // printBitSet(arr2);
    // bitset_alloc(arr3, 48);
    // printBitSet(arr3);
    // bitset_fill(arr3, true);
    // printBitSet(arr3);
    // bitset_alloc(arr4, 5);
    // printBitSet(arr4);
    // bitset_fill(arr4, true);
    // printBitSet(arr4);
    // bitset_fill(arr4, false);
    // printBitSet(arr4);
    // bitset_alloc(arr11, 65);
    // printBitSet(arr11);
    // bitset_fill(arr11, true);
    // printBitSet(arr11);
    // bitset_fill(arr11, false);
    // printBitSet(arr11);
    //
    // bitset_alloc(arr5, 127);
    // printBitSet(arr5);
    // bitset_fill(arr5, true);
    // printBitSet(arr5);
    // bitset_fill(arr5, false);
    // printBitSet(arr5);
    // bitset_alloc(arr6, 128);
    // printBitSet(arr6);
    // bitset_fill(arr6, true);
    // printBitSet(arr6);
    // bitset_fill(arr6, false);
    // printBitSet(arr6);
    // bitset_alloc(arr7, 129);
    // printBitSet(arr7);
    // bitset_fill(arr7, true);
    // printBitSet(arr7);
    // bitset_fill(arr7, false);
    // printBitSet(arr7);
    //
    // // bitset_create(arr7, 129);
    // bitset_setbit(arr7, 1, 1);
    // bitset_setbit(arr7, 32, 1);
    // bitset_setbit(arr7, 28, 1);
    // bitset_setbit(arr7, 64, 1);
    // bitset_setbit(arr7, 65, 1);
    // bitset_setbit(arr7, 66, 1);
    // bitset_setbit(arr7, 97, 1);
    // bitset_setbit(arr7, 68, 1);
    // bitset_setbit(arr7, 66, 1);
    // bitset_setbit(arr7, 126, 1);
    // bitset_setbit(arr7, 127, 1);
    // bitset_setbit(arr7, 128, 1);
    // // bitset_setbit(arr7, 129, 1);
    //
    // printf("%lu\n", bitset_getbit(arr7, 1));
    // printf("%lu\n", bitset_getbit(arr7, 32));
    // printf("%lu\n", bitset_getbit(arr7, 28));
    // printf("%lu\n", bitset_getbit(arr7, 64));
    // printf("%lu\n", bitset_getbit(arr7, 65));
    // printf("%lu\n", bitset_getbit(arr7, 66));
    // printf("%lu\n", bitset_getbit(arr7, 97));
    // printf("%lu\n", bitset_getbit(arr7, 68));
    // printf("%lu\n", bitset_getbit(arr7, 66));
    // printf("%lu\n", bitset_getbit(arr7, 126));
    // printf("%lu\n", bitset_getbit(arr7, 127));
    // printf("%lu\n\n", bitset_getbit(arr7, 128));
    // // printf("%lu\n\n", bitset_getbit(arr7, 129));
    //
    // printf("%lu\n", bitset_getbit(arr7, 2));
    // printf("%lu\n", bitset_getbit(arr7, 33));
    // printf("%lu\n", bitset_getbit(arr7, 29));
    // printf("%lu\n", bitset_getbit(arr7, 69));
    // printf("%lu\n", bitset_getbit(arr7, 63));
    // printf("%lu\n", bitset_getbit(arr7, 61));
    // printf("%lu\n", bitset_getbit(arr7, 91));
    // printf("%lu\n", bitset_getbit(arr7, 60));
    // printf("%lu\n", bitset_getbit(arr7, 69));
    // printf("%lu\n", bitset_getbit(arr7, 121));
    // printf("%lu\n", bitset_getbit(arr7, 122));
    // printf("%lu\n", bitset_getbit(arr7, 123));
    // printf("%lu\n\n", bitset_getbit(arr7, 124));
    //
    // bitset_setbit(arr7, 1, 0);
    // bitset_setbit(arr7, 32, 0);
    // bitset_setbit(arr7, 28, 0);
    // bitset_setbit(arr7, 64, 0);
    // bitset_setbit(arr7, 65, 0);
    // bitset_setbit(arr7, 66, 0);
    // bitset_setbit(arr7, 97, 0);
    // bitset_setbit(arr7, 68, 0);
    // bitset_setbit(arr7, 66, 0);
    // bitset_setbit(arr7, 126, 0);
    // bitset_setbit(arr7, 127, 0);
    // bitset_setbit(arr7, 128, 0);
    //
    // printf("%lu\n", bitset_getbit(arr7, 1));
    // printf("%lu\n", bitset_getbit(arr7, 32));
    // printf("%lu\n", bitset_getbit(arr7, 28));
    // printf("%lu\n", bitset_getbit(arr7, 64));
    // printf("%lu\n", bitset_getbit(arr7, 65));
    // printf("%lu\n", bitset_getbit(arr7, 66));
    // printf("%lu\n", bitset_getbit(arr7, 97));
    // printf("%lu\n", bitset_getbit(arr7, 68));
    // printf("%lu\n", bitset_getbit(arr7, 66));
    // printf("%lu\n", bitset_getbit(arr7, 126));
    // printf("%lu\n", bitset_getbit(arr7, 127));
    // printf("%lu\n\n", bitset_getbit(arr7, 128));
    //
    // bitset_free(arr1);
    // bitset_free(arr2);
    //
    // bitset_free(arr3);
    //
    // bitset_free(arr4);
    //
    // bitset_free(arr5);
    //
    // bitset_free(arr6);
    //
    // bitset_free(arr7);
    // bitset_free(arr11);







    // printf("%lu\n", sizeof(unsigned long));
}
