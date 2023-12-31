#ifndef FACTORS_H
#define FACTORS_H

/* Header files */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* Prototype functions */
void factorize(FILE *file);
int is_prime(long long num);
void prime_factors(long long num);

#endif /* FACTORS_H */
