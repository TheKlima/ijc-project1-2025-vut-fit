// File: steg-decode.c
// Subject: IJC
// Project: #1
// Author: Andrii Klymenko, FIT VUT
// Login: xklyme00
// Date: 3.2.2023
// Compiled: gcc version 11.4.0

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ppm.h"
#include "eratosthenes.h"
#include "bitset.h"
#include "error.h"

#define START_PRIMES 101

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        error_exit("program expects only one argument.\n");
    }

    struct ppm *ppm = ppm_read(argv[1]);

    if(ppm == NULL)
    {
        error_exit("ppm_read: couldn't read an image in PPM format.\n");
    }

    bitset_index_t arr_size = ppm->xsize * ppm->ysize * 3;
    bitset_alloc(arr, arr_size);

    Eratosthenes(arr);

    char current_char = 0;
    char processed_bits = 0;
    bool end = false;

    for(bitset_index_t i = START_PRIMES; i < arr_size; ++i)
    {
        if(bitset_getbit(arr, i))
        {
            current_char |= ((ppm->data[i] & 1) << processed_bits);
            ++processed_bits;

            if(processed_bits == 8)
            {
                if(current_char == '\0')
                {
                    end = true;
                    break;
                }

                putchar(current_char);
                processed_bits = 0;
                current_char = 0;
            }
        }
    }

    putchar('\n');

    if(!end)
    {
        error_exit("wrong format of the ppm file for current project: there is no '\\0' character in the end of the secret message.\n");
    }

    bitset_free(arr);
    ppm_free(ppm);
    return 0;
}
