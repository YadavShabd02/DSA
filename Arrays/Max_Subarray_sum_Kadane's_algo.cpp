#include <bits/stdc++.h>
using namespace std;

/*
    File: Max_Subarray_sum_Kadane's_algo.cpp

    Description:
    Implements Kadane's algorithm to find the maximum sum of a contiguous subarray
    within a one-dimensional array of numbers (which may include negative values).

    Visualization (step-by-step):
    - We keep a running `sum` that accumulates elements as we iterate.
    - If `sum` ever becomes negative, we “discard” it (reset to 0), because any
      subarray that begins with a negative running sum cannot be optimal.
    - Meanwhile, we track `maxi` (the maximum sum seen so far). At each index `i`,
      we compare the current running sum (after including arr[i]) to `maxi` and update if larger.
    - Optionally, one can consider an empty subarray (sum = 0) as a candidate if all elements are negative;
      uncomment the provided check if that variant is needed.

    Time Complexity (TC): O(n)
      - We scan the array once, performing a constant number of operations per element.
    Space Complexity (SC): O(1)
      - We use only a few auxiliary variables (no extra arrays or dynamic memory).

    Edge cases:
    1. All negative numbers: Without the “empty subarray” check, Kadane’s still picks the largest (least negative) element.
    2. All positive numbers: Accumulates entire array sum.
    3. Mixed positives and negatives: Resets whenever the running sum dips below zero.
*/

long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN;  // Tracks the maximum subarray sum found so far
    long long sum = 0;          // Running sum of the current subarray

    // `sum` and `maxi` progression visualization (example):
    // arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    // i=0: sum = -2  -> reset sum to 0, maxi = -2
    // i=1: sum = 1   -> maxi = 1
    // i=2: sum = -2  -> reset sum to 0, maxi still 1
    // i=3: sum = 4   -> maxi = 4
    // i=4: sum = 3   -> maxi still 4
    // i=5: sum = 5   -> maxi = 5
    // i=6: sum = 6   -> maxi = 6
    // i=7: sum = 1   -> maxi still 6
    // i=8: sum = 5   -> maxi still 6
    // Answer: 6

    for (int i = 0; i < n; i++) {
        sum += arr[i];             // Include current element into running sum

        if (sum > maxi) {
            // If the running sum surpasses previous maximum, update maxi
            maxi = sum;
        }

        if (sum < 0) {
            // If running sum dips below 0, none of its extensions can be better, so reset.
            sum = 0;
        }
    }

    // To consider the empty subarray (sum = 0) when all elements are negative, uncomment below:
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
