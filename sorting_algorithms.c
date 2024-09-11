#include "sorting_algorithms.h"



void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition_low(int *arr, int low, int high) {

    
    int p = arr[low];
    int i = low;
    int j = high;

    while (i < j) {

     
        while (arr[i] <= p && i <= high - 1) {
            i++;
        }

        
        while (arr[j] > p && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quick_sort_low(int *arr, int low, int high) {
    if (low < high) {

      
        int pi = partition_low(arr, low, high);

       
        quick_sort_low(arr, low, pi - 1);
        quick_sort_low(arr, pi + 1, high);
    }
}
int partition_median(int *arr, int low, int high) {
    int mid = (low + high) / 2;
    if (arr[low] < arr[mid])
        swap(&arr[mid], &arr[low]);
    if (arr[low] < arr[high])
        swap(&arr[high], &arr[low]);
    if (arr[mid] < arr[high])
        swap(&arr[mid], &arr[high]);

    swap(&arr[mid], &arr[low]);

    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1)
            i++;
        while (arr[j] > pivot && j >= low + 1)
            j--;
        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quick_sort_median(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition_median(arr, low, high);

        quick_sort_median(arr, low, pi - 1);
        quick_sort_median(arr, pi + 1, high);
    }
}
int partition_high(int *arr, int low, int high) {

    
    int p = arr[high];
    int i = low-1;
    

   for (int j = low; j < high; j++) {
      if (arr[j] < p) {
            i++;
           swap(&arr[i],&arr[j]);
        }
    }

     
       
      
    swap(&arr[i+1], &arr[high]);
    return i+1;
}
void quick_sort_high(int *arr, int low, int high) {
    if (low < high) {

       int pi = partition_high(arr, low, high);

    
        quick_sort_high(arr, low, pi - 1);
        quick_sort_high(arr, pi + 1, high);
    }
}


int getMax(int *arr, int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 

void countSort(int *arr, int n, int exp)
{

    int output[n];
    int i, count[10] = { 0 };
 
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
       for (i = 0; i < n; i++)
        arr[i] = output[i];
}

 
void radix_sort(int *arr, int size)
{
  
    int m = getMax(arr, size);
 

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, size, exp);
}

void insertion_sort(int *arr, int size) {
    int i, j, key;

    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}


void bubble_sort(int *arr, int size) {
    int i, j, temp;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void merge(int *arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    
    int leftArr[n1], rightArr[n2];

    
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

  
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
 while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void merge_sort(int *arr, int left, int right) {
    if (left < right) {
      
       
        int mid = left + (right - left) / 2;

     
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

       
        merge(arr, left, mid, right);
    }
}




void heapify(int *arr, int N, int i)
{
    
    int largest = i;

   
    int left = 2 * i + 1;

    
    int right = 2 * i + 2;

    
    if (left < N && arr[left] > arr[largest])

        largest = left;

    
    if (right < N && arr[right] > arr[largest])

        largest = right;

    
    if (largest != i) {

        swap(&arr[i], &arr[largest]);

        
        heapify(arr, N, largest);
    }
}


void heap_sort(int *arr, int size)
{

    
    for (int i = size / 2 - 1; i >= 0; i--)

        heapify(arr, size, i);

    
    for (int i = size - 1; i >= 0; i--) {

        swap(&arr[0], &arr[i]);

       
        heapify(arr, i, 0);
    }
}

void shell_sort(int *arr, int size) {
 
    for (int gap = size/2; gap > 0; gap /= 2)
    {
       
        for (int i = gap; i < size; i += 1)
        {
            
            int temp = arr[i];

       
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            
            arr[j] = temp;
        }
}
}

    