// File: ppm.h
// Subject: IJC
// Project: #1
// Author: Andrii Klymenko, FIT VUT
// Login: xklyme00
// Date: 3.2.2023
// Compiled: gcc version 11.4.0

#ifndef PPM_H
#define PPM_H

#include <stdio.h>
#include <stdbool.h>

#define MAX_IMAGE_WIDTH 16000            // maximal width of the PPM image
#define MAX_IMAGE_HEIGHT MAX_IMAGE_WIDTH // maximal height of the PPM image
#define MAX_COLOR_VALUE 255
#define MAGIC_NUMBER "P6"
#define MAGI_NUMBER_STR_LENGTH 2

struct ppm {
    unsigned xsize;
    unsigned ysize;
    char data[];    // RGB bytes, in total 3*xsize*ysize
};

struct ppm *ppm_read(const char *filename);
void ppm_free(struct ppm *p);

#endif // PPM_H
