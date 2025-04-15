#include <stdio.h>
#include <stdlib.h>


void binary(int arr[], int n, int key) {
    int low = 0;
    int high = n;


    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            printf("Element found at index %d  \n", mid);;
            return;

        } else if (arr[mid] < key) {
            low = mid +1;
        } else {
            high = mid -1;
        }
        }
    printf("Element not found in the array");
    return;

} 

int main() {
    int arr[20];
    int n;
    int key;

    printf("Enter the number of elements: \n");
    scanf("%d", &n);

    printf("Enter the elements: \n");
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the element to search: \n");
    scanf("%d", &key);

    binary(arr, n, key);
    return 0;
}