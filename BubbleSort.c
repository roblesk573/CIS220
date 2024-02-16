// Kevin Robles
// Chpt2 PA

#include <stdio.h>

// Function to swap two elements
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Bubble sort function
void bubbleSort(int arr[], int n) {
    // Traverse through all elements of the array
    for (int i = 0; i < n-1; i++) {
        // Last i elements are already in place, so only traverse till n-i-1
        for (int j = 0; j < n-i-1; j++) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main() {
    int arr[] = {93, 52, 72, 42, 3, 63, 100, 19, 61, 44, 21, 98, 6, 41, 78, 5, 51, 60, 67, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
   
    // Sort the array using Bubble Sort
    bubbleSort(arr, n);
   
    // Print the sorted array
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n"); // Add a new line at the end of the output
   
    return 0;
}
