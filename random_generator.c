#include "random_generator.h"


int generate_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}
void read_dataset(const char *filename, int *arr, int size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        if (fscanf(file, "%d", &arr[i]) != 1) {
            perror("Failed to read integer");
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
}
int generate_unique_random_number(int min, int max, int *generated_numbers, int size) {
    int random_number;
    int i;

    do {
        random_number = generate_random_number(min, max);
        for (i = 0; i < size; i++) {
            if (generated_numbers[i] == random_number) {
                break;
            }
        }
    } while (i < size);

    return random_number;
}

void generate_dataset(int size, int min, int max, char *filename) {
    int i;
    int *generated_numbers = (int *)malloc(size * sizeof(int));
    FILE *fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (i = 0; i < size; i++) {
        generated_numbers[i] = generate_unique_random_number(min, max, generated_numbers, i);
        fprintf(fp, "%d\n", generated_numbers[i]);
    }

    fclose(fp);
    free(generated_numbers);
}