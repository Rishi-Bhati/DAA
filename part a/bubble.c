#include <stdio.h>
#include <stdlib.h>

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble(int arr[], int n) {
    int swapped;

    for(int i=0; i<n-1; i++) {
        swapped = 0;
        for(int j = 0; j<n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                swapped = 1;
            }
        }
    }
    
}

void printArray(int arr[], int size) {
    for (int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int arr[20];
    int n;

    printf("Enter the number of elements: \n");
    scanf("%d", &n);

    printf("Enter the elements: \n");
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    printf("Unsorted array: \n");
    printArray(arr, n);
    bubble(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;

}