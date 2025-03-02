#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10  // Number of buckets

// Structure for a bucket
typedef struct {
    int* values;
    int count;
} Bucket;

// Function to perform insertion sort within a bucket
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Bucket Sort implementation
void bucketSort(int arr[], int n) {
    // Step 1: Create buckets
    Bucket buckets[BUCKET_SIZE];
    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i].values = (int*)malloc(n * sizeof(int));
        buckets[i].count = 0;
    }

    // Step 2: Scatter elements into appropriate buckets
    int max_value = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max_value)
            max_value = arr[i];

    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] * BUCKET_SIZE) / (max_value + 1);
        buckets[bucketIndex].values[buckets[bucketIndex].count++] = arr[i];
    }

    // Step 3: Sort each bucket using insertion sort
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        insertionSort(buckets[i].values, buckets[i].count);
        for (int j = 0; j < buckets[i].count; j++)
            arr[index++] = buckets[i].values[j];
    }

    // Step 4: Free allocated memory
    for (int i = 0; i < BUCKET_SIZE; i++)
        free(buckets[i].values);
}

// Utility function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver Code
int main() {
    int arr[] = {42, 32, 33, 52, 37, 47, 51, 66, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
