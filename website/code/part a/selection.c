#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min = i;

        for (int j = i+1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
    }   if(min != i) {
            swap(&a[i], &a[min]);
        }
    }
}

void printArray(int arr[], int size) {
    for (int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {

    int arr[20];
    int n;

    printf("Enter the number of elements: \n");
    scanf("%d", &n);

    printf("Enter the elements: \n");
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    printf("Unsorted array: \n");
    printArray(arr, n);

    selection(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;

}