#include <stdio.h>

// Function to get the maximum value in the array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Function to do counting sort based on digit place value
void countingSort(int arr[], int n, int exp) {
    int output[n]; // Output array
    int count[10] = {0}; // Count array initialized to zero

    // Count occurrences of each digit
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that it contains the position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy output array to original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Function to perform Radix Sort
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    // Apply counting sort for each digit place value
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    radixSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}
