#include <bits/stdc++.h>
using namespace std;

/*
    File: Find_Min_in_Rotated_Sorted_Array.cpp

    Description:
    Given a rotated sorted array `nums` (with no duplicate elements), this code
    finds and returns the minimum element. A rotated sorted array is formed by
    taking an ascending-sorted array and shifting it at some pivot. For example,
    [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2].

    Approach:
    - Use a modified binary search to identify which half of the current window
      is strictly sorted. If the left half [low..mid] is sorted, then the
      smallest element in that half is at `nums[low]`. Otherwise, the right half
      [mid..high] is sorted, and the smallest element in that half is at `nums[mid]`.
    - Update `ans` with the smaller candidate, then shrink the search window
      to exclude the half already examined. Repeat until `low > high`.

    Visualization (example: nums = [4,5,6,7,0,1,2]):
      Initial:
        low = 0, high = 6, ans = +∞

      Iteration 1:
        mid = (0 + 6) / 2 = 3 → nums[mid] = 7
        nums[low] = 4 ≤ nums[mid] = 7 → left half [4,5,6,7] is sorted
          → candidate min in this half = nums[low] = 4 → ans = 4
          → discard left half, search right half → low = mid + 1 = 4

      Iteration 2:
        low = 4, high = 6, mid = (4 + 6) / 2 = 5 → nums[mid] = 1
        nums[low] = 0 ≤ nums[mid] = 1 → left half [0,1] is sorted
          → candidate min in this half = nums[low] = 0 → ans = min(4,0) = 0
          → discard left half, search right half → low = mid + 1 = 6

      Iteration 3:
        low = 6, high = 6, mid = 6 → nums[mid] = 2
        nums[low] = 2 ≤ nums[mid] = 2 → left half [2] is sorted
          → candidate min = nums[low] = 2 → ans = min(0,2) = 0
          → discard left half → low = mid + 1 = 7

      Now low (7) > high (6), exit loop. Final answer = 0.

    Time Complexity (TC): O(log n)
      - Each iteration halves the search window, analogous to binary search.

    Space Complexity (SC): O(1)
      - Uses only a few integer variables (`low`, `high`, `mid`, `ans`) and no extra arrays.

    Edge Cases:
      1. Array is not rotated (e.g., [1,2,3,4,5]):
         - At first check, nums[low] ≤ nums[mid], so ans = nums[low] = 1, then
           low moves beyond high, and returns 1 correctly.
      2. Single-element array (e.g., [10]): returns that element.
      3. Pivot at beginning or end:
         - If pivot is at index 0 (no rotation), handled as above.
         - If pivot is at index n−1 (rotation by n−1), e.g. [2,3,4,5,1], left half
           isn’t always sorted; algorithm finds the correct min at each step.
      4. Large array with minimum near one end: binary search quickly narrows to it.

    Brief Explanation of Branch Logic:
      - Compute `mid = low + (high - low) / 2`.
      - If `nums[low] <= nums[mid]`, the subarray from `low` to `mid` is strictly
        increasing → its minimum is at `nums[low]`. Update `ans = min(ans, nums[low])`
        and move `low = mid + 1` to search in the right half.
      - Otherwise, the right half `[mid..high]` must be strictly increasing → its
        minimum is at `nums[mid]`. Update `ans = min(ans, nums[mid])` and move
        `high = mid - 1` to search in the left half.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = INT_MAX;  // Track the smallest candidate found

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // If left half [low..mid] is sorted
            if (nums[low] <= nums[mid]) {
                // Minimum candidate in this half is nums[low]
                ans = min(ans, nums[low]);
                // Discard the entire left half (including mid) and search right half
                low = mid + 1;
            }
            else {
                // Right half [mid..high] is sorted; its minimum candidate is nums[mid]
                ans = min(ans, nums[mid]);
                // Discard the right half beyond mid and search left half
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;                      // Number of elements in the rotated sorted array
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];            // Input the array elements
    }

    Solution sol;
    int minimum = sol.findMin(nums);

    cout << minimum << "\n";       // Output the minimum element
    return 0;
}
