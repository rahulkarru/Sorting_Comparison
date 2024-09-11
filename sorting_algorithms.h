#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <stdio.h>
#include <stdlib.h>


void swap(int* a, int* b);
void quick_sort_low(int *arr, int low, int high);
int partition_low(int *arr, int low, int high);
void quick_sort_median(int *arr, int low, int high);
int partition_median(int *arr, int low, int high);
void quick_sort_high(int *arr, int low, int high);
int partition_high(int *arr, int low, int high);
int getMax(int *arr, int n);
void countSort(int *arr, int n, int exp);

void radix_sort(int *arr, int size);


void insertion_sort(int *arr, int size);


void bubble_sort(int *arr, int size);


void merge(int *arr, int left, int mid, int right);
void merge_sort(int *arr, int low, int high);



void heapify(int *arr, int N, int i);
void heap_sort(int *arr, int size);


void shell_sort(int *arr, int size);

#endif