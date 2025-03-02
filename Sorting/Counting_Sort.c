#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum value in an array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Counting Sort Implementation
void countingSort(int arr[], int n) {
    int max = getMax(arr, n); // Find the maximum element in the array

    // Step 1: Create and initialize the count array
    int *count = (int*)calloc((max + 1), sizeof(int));

    // Step 2: Store the frequency of each element
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Step 3: Modify count array to store cumulative frequency
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Step 4: Create output array
    int *output = (int*)malloc(n * sizeof(int));

    // Step 5: Place elements into output array in sorted order
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Step 6: Copy sorted elements back to original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    // Free dynamically allocated memory
    free(count);
    free(output);
}

// Utility function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver Code
int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    countingSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
