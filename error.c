// File: error.c
// Subject: IJC
// Project: #1
// Author: Andrii Klymenko, FIT VUT
// Login: xklyme00
// Date: 3.2.2025
// Compiled: gcc version 11.4.0

#include "error.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// prints an error message and possible arguments to the stderr
void warning(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "Warning: ");
    vfprintf(stderr, fmt, args);
    va_end(args);
}

// works in the same way as 'warning_msg' but in the end terminates the program with 'exit(1)'
void error_exit(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "Error: ");
    vfprintf(stderr, fmt, args);
    va_end(args);
    exit(1);
}