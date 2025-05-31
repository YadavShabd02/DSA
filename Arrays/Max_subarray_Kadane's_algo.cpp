#include <bits/stdc++.h>
using namespace std;

/*
    File: Max_subarray_Kadane's_algo.cpp

    Description:
    Kadane’s algorithm (extended) to not only compute the maximum subarray sum
    but also identify the start and end indices of that subarray. Similar to the
    simpler version, whenever the running sum becomes negative, we reset it, but
    here we also track the beginning of the candidate subarray.

    Visualization (example: arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]):
    - We keep `sum`, `maxi`, `start`, `ansStart`, `ansEnd`.
    - Whenever sum == 0 at a new index i, we mark `start = i`.
    - If sum + arr[i] > maxi, update maxi, ansStart = start, ansEnd = i.
    - If sum becomes negative → reset sum = 0; next iteration marks a new start.

    Time Complexity (TC): O(n)
      - Single pass through the array, constant work per element.
    Space Complexity (SC): O(1)
      - Only uses a few integer variables; prints subarray in O(n) but does not store it.

    Edge cases:
    1. All negative numbers: this version still picks the largest single element but
       the subarray printed is correct. The “empty subarray” variant can be added as needed.
    2. All positive numbers: entire array is chosen.
*/

long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN;   // Best (max) sum seen so far
    long long sum = 0;           // Current running sum
    int start = 0;               // Candidate subarray start index
    int ansStart = -1, ansEnd = -1; // Final result subarray indices

    for (int i = 0; i < n; i++) {
        if (sum == 0) {
            // We are starting a new candidate subarray at index i
            start = i;
        }

        sum += arr[i];  // Extend the candidate subarray

        if (sum > maxi) {
            // We found a better subarray ending at i
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        if (sum < 0) {
            // This candidate can’t contribute to a future optimal subarray
            sum = 0;
        }
    }

    // Print the best subarray
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "]\n";

    // To consider empty subarray when all are negative, uncomment:
    // if (maxi < 0) maxi = 0;

    return maxi;
}

int main() {
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}
