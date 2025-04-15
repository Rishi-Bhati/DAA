#include <stdio.h>
#include <stdlib.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print the elements of the array
void printArray(int arr[], int size) {
    // Loop through each element and print it
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to partition the array around the pivot element
// Elements smaller than pivot are moved to left, greater to right
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as pivot
    int i = low - 1;       // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(&arr[i], &arr[j]); // Swap current element with element at i
        }
    }
    // Place pivot in the correct position
    swap(&arr[i + 1], &arr[high]);
    return (i + 1); // Return the partition index
}

// Function to implement quick sort using divide and conquer
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high);

        // Recursively sort elements before partition
        quickSort(arr, low, pi - 1);

        // Recursively sort elements after partition
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[20];
    int n;

    // Get the number of elements from user
    printf("Enter the number of elements: \n");
    scanf("%d", &n);

    // Get the elements from user
    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Print the original unsorted array
    printf("Unsorted array: \n");
    printArray(arr, n);

    // Call quick sort function to sort the array
    quickSort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
