#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choosing the last element as the pivot
    int i = (low - 1);  // Pointer for the greater element

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;  // Increment the pointer
            swap(&arr[i], &arr[j]);  // Swap elements
        }
    }

    // Swap the pivot element with the element at i+1
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Recursive Quick Sort function
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Partitioning index

        // Recursively sort elements before partition
        quick_sort(arr, low, pi - 1);
        // Recursively sort elements after partition
        quick_sort(arr, pi + 1, high);
    }
}

// Function to print an array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to test the Quick Sort implementation
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted array: \n");
    print_array(arr, n);

    quick_sort(arr, 0, n - 1);

    printf("Sorted array: \n");
    print_array(arr, n);
    printf("This code is written by Hardik Gulati");
    return 0;
}
