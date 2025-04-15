#include <stdio.h>
#include <stdlib.h>

// Function to print the elements of the array
void printArray(int arr[], int size) {
    // Loop through each element and print it
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to perform insertion sort on an array
void insertion(int arr[], int n) {
    // Start from the second element (index 1)
    // First element (index 0) is considered as sorted
    for (int i = 1; i < n; i++) {
        // Store the current element to be inserted
        int key = arr[i];
        
        // Initialize j as the element before i
        int j = i - 1;
        
        // Move elements that are greater than key
        // to one position ahead of their current position
        // This creates space for inserting the key
        while (j >= 0 && arr[j] > key) {
            // Shift element to right by one position
            arr[j + 1] = arr[j];
            // Move to previous element
            j = j - 1;
        }
        
        // Place the key in its correct position
        // j+1 is the correct position because j was decremented
        // one extra time in the while loop
        arr[j + 1] = key;
    }
}

int main() {
    // Declare array and size variable
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

    // Call insertion sort function to sort the array
    insertion(arr, n);

    // Print the sorted array
    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
