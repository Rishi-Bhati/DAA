#include <stdio.h>
#include <stdlib.h>

// Function to print the elements of the array
void printArray(int arr[], int size) {
    // Loop through each element and print it
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to merge two sorted subarrays into one sorted array
// arr[l..m] and arr[m+1..r] are the two subarrays
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1; // Size of left subarray
    int n2 = r - m;     // Size of right subarray

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    i = 0; // Initial index of left subarray
    j = 0; // Initial index of right subarray
    k = l; // Initial index of merged subarray

    // Compare elements of L[] and R[] and copy the smaller one
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy any remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to implement merge sort using divide and conquer
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Find the middle point to divide the array into two halves
        int m = l + (r - l) / 2;

        // Recursively sort the first half
        mergeSort(arr, l, m);

        // Recursively sort the second half
        mergeSort(arr, m + 1, r);

        // Merge the two sorted halves
        merge(arr, l, m, r);
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

    // Call merge sort function to sort the array
    mergeSort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
