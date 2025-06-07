#include <bits/stdc++.h>
using namespace std;

/*
    File: Search_in_Rotated_Sorted_Array_II.cpp

    Description:
    Given a rotated sorted array `nums` that may contain duplicates, determine
    if a given `target` value exists in the array. This algorithm extends the
    classic binary search on a rotated array to handle duplicates by shrinking
    the search window when the ends and mid are equal.

    Problem Context:
    - A rotated sorted array is formed by taking a sorted array and rotating it
      at some pivot. For example, [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2].
    - Here, duplicates are allowed, making it harder to decide which half is
      strictly ordered.
    - We use a modified binary search: if `nums[low]`, `nums[mid]`, and
      `nums[high]` are equal, we cannot tell which side is sorted, so we shrink
      both ends by one. Otherwise, we check which half is sorted and move the
      pointers accordingly.

    Visualization (example):
      nums = [2, 5, 6, 0, 0, 1, 2], target = 0

      Initial:
        low = 0 (nums[0]=2), high = 6 (nums[6]=2)

      Iteration 1:
        mid = (0 + 6) / 2 = 3 → nums[3] = 0
        nums[mid] == target → found! ans = true, break.

      Another scenario (target = 3, not present):
        low = 0, high = 6, ans = false
        Iteration 1:
          mid = 3 → nums[3] = 0, not equal to 3
          nums[low]=2, nums[mid]=0, nums[high]=2 → not all three equal
          Check if left half is sorted: nums[low]=2 ≤ nums[mid]=0? No → right half is sorted
          Right half is [0,1,2]. Does 3 lie in [0..2]? No → move high = mid - 1 = 2

        Iteration 2:
          low = 0, high = 2 → mid = 1 → nums[1]=5, not equal to 3
          nums[low]=2, nums[mid]=5, nums[high]=6 → not all three equal
          Left half is sorted since nums[low]=2 ≤ nums[mid]=5
          Does 3 lie in [2..5]? Yes → search left half → high = mid - 1 = 0

        Iteration 3:
          low = 0, high = 0 → mid = 0 → nums[0]=2, not equal to 3
          nums[low]=2, nums[mid]=2, nums[high]=2 → all three equal → shrink window:
            low = 1, high = -1

        Now low(1) > high(-1) → exit loop → return false.

    Time Complexity (TC):
      - Average case: O(log n), similar to binary search on a rotated array.
      - Worst case: O(n). When many duplicates exist (e.g., [2,2,2,2,2,...]),
        the shrink-step `low++` and `high--` may run n times, degrading to linear.

    Space Complexity (SC): O(1)
      - Only a few integer variables (`low`, `high`, `mid`, `ans`) are used.

    Edge Cases:
      1. Empty array (nums.size() = 0): returns false immediately.
      2. All elements identical: we keep shrinking until either we find the
         target or low > high.
      3. No rotation (fully sorted): behaves like standard binary search with
         duplicates handling.
      4. Target equal to multiple positions: returns true on first match.

    Outline of Branch Logic:
      - Compute `mid = low + (high - low) / 2`.
      - If `nums[mid] == target`, set `ans = true` and break.
      - If `nums[low] == nums[mid] == nums[high]`, we cannot determine order:
        shrink both ends: `low++`, `high--`.
      - Else, if left half [low..mid] is sorted (`nums[low] ≤ nums[mid]`):
          - If `target` lies within [nums[low]..nums[mid]], move `high = mid - 1`.
          - Otherwise, move `low = mid + 1`.
      - Otherwise, right half [mid..high] must be sorted:
          - If `target` lies within [nums[mid]..nums[high]], move `low = mid + 1`.
          - Otherwise, move `high = mid - 1`.
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        bool ans = false;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                // Found target at mid
                ans = true;
                break;
            }

            // If values at low, mid, and high are equal, we cannot determine which side is ordered
            else if (nums[low] == nums[mid] && nums[high] == nums[mid]) {
                low = low + 1;    // Shrink from left
                high = high - 1;  // Shrink from right
                continue;         // Re-evaluate new low/high
            }

            // If left half [low..mid] is sorted
            else if (nums[low] <= nums[mid]) {
                // If target lies within the sorted left half
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;  // Search left
                } else {
                    low = mid + 1;   // Search right
                }
            }

            // Otherwise, right half [mid..high] must be sorted
            else {
                // If target lies within the sorted right half
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;   // Search right
                } else {
                    high = mid - 1;  // Search left
                }
            }
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;                  // Number of elements in the rotated array
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];        // Input array elements (may contain duplicates)
    }

    int target;
    cin >> target;             // Value to search for

    Solution sol;
    bool found = sol.search(nums, target);

    cout << (found ? "true" : "false") << "\n";
    return 0;
}
