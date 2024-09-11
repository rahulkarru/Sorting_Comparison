#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generate_random_number(int min, int max);

int generate_unique_random_number(int min, int max, int *generated_numbers, int size);



void read_dataset(const char *filename, int *arr, int size);
void generate_dataset(int size, int min, int max, char *filename);

#endif