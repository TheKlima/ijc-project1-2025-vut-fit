// File: ppm.c
// Subject: IJC
// Project: #1
// Author: Andrii Klymenko, FIT VUT
// Login: xklyme00
// Date: 3.2.2023
// Compiled: gcc version 11.4.0

#include "ppm.h"
#include <ctype.h>
#include "error.h"
#include <stdlib.h>
#include <string.h>

// loads the contents of the PPM file with name 'filename' into dynamically allocated structure 'ppm'
struct ppm *ppm_read(const char *filename)
{
    FILE *fp = fopen(filename, "r");

    if(fp == NULL)
    {
        warning("couldn't open a file with a name '%s'.\n", filename);
        return NULL;
    }

    char magic_number[MAGI_NUMBER_STR_LENGTH + 1];
    unsigned x_size, y_size, max_color_value;

    if(fscanf(fp,  "%2s %u %u %u", magic_number,  &x_size, &y_size, &max_color_value) != 4
        || strcmp(magic_number, MAGIC_NUMBER) != 0
        || x_size > MAX_IMAGE_WIDTH
        || y_size > MAX_IMAGE_HEIGHT
        || max_color_value != MAX_COLOR_VALUE
        || !isspace(getc(fp)))
    {
        warning("invalid PPM file %s for this project.\n", filename);
        fclose(fp);
        return NULL;
    }

    int bytes_in_img = 3 * x_size * y_size;
    struct ppm *ppm = (struct ppm*) malloc(sizeof(struct ppm) + bytes_in_img);

    if(ppm == NULL)
    {
        warning("couldn't allocate memory for 'ppm' structure\n");
        fclose(fp);
        return NULL;
    }

    ppm->xsize = x_size;
    ppm->ysize = y_size;

    int i = 0;
    int c;

    while(i < bytes_in_img && (c = getc(fp)) != EOF)
    {
        ppm->data[i++] = c;
    }

    if(i != bytes_in_img || getc(fp) != EOF)
    {
        warning("size of the PPM file '%s' specified in this file differs from its actual size.\n", filename);
        fclose(fp);
        ppm_free(ppm);
        return NULL;
    }

    fclose(fp);
    return ppm;
}

// frees dynamically allocated memory for a ppm structure in the 'ppm_read' function
void ppm_free(struct ppm *p)
{
    free(p);
}
