#include <bits/stdc++.h>
using namespace std;

/*
    File: Search_Insert_Position.cpp

    Description:
    Given a sorted array `nums` and a `target` value, this code finds the index
    at which `target` should be inserted to maintain the array’s sorted order.
    If `target` already exists in `nums`, its current index is returned. Uses
    binary search to achieve O(log n) time.

    Visualization (example: nums = [1, 3, 5, 6], target = 5):
    - low = 0, high = 3, ans = 4 (initially size of nums)
    - Iteration 1:
        mid = 0 + (3 - 0) / 2 = 1 → nums[1] = 3 < 5
        → Move low = mid + 1 = 2
        → ans stays 4
    - Iteration 2:
        low = 2, high = 3 → mid = 2 + (3 - 2) / 2 = 2 → nums[2] = 5 ≥ 5
        → Potential insert index found: ans = 2
        → Move high = mid - 1 = 1
    - Now low (2) > high (1), loop ends → return ans = 2

    Another scenario (example: nums = [1, 3, 5, 6], target = 2):
    - low = 0, high = 3, ans = 4
    - Iteration 1:
        mid = 1 → nums[1] = 3 ≥ 2
        → ans = 1, high = 0
    - Iteration 2:
        low = 0, high = 0 → mid = 0 → nums[0] = 1 < 2
        → low = 1
    - Now low (1) > high (0) → return ans = 1

    Time Complexity (TC): O(log n)
      - Each loop iteration halves the search window.
    Space Complexity (SC): O(1)
      - Only a few integer variables are used.

    Edge cases:
    1. Empty array (nums.size() = 0): returns ans = 0 (insert at beginning).
    2. target smaller than all elements: first comparison sets ans = 0.
    3. target larger than all elements: ans remains nums.size(), meaning insert at end.
    4. target equals an element: returns that element’s index.

    Notes:
    - `ans` is initialized to `nums.size()` so that, if `target` is larger than every element,
      it will be inserted at the end (index = size).
    - Whenever `nums[mid] >= target`, we record `mid` as a potential answer and search left
      (to find the first occurrence or insertion point). Otherwise, we search right.
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans = nums.size();           // Default: insert at end if not found
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;  // Prevents potential overflow

            if (nums[mid] >= target) {
                // nums[mid] is a candidate (either equal to target or larger),
                // so record mid and move left to check if there’s an earlier position.
                ans = mid;
                high = mid - 1;
            }
            else {
                // nums[mid] < target, so the insert position must be right of mid.
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;                          // Number of elements in the sorted array
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];                // Input the sorted array elements
    }

    int target;
    cin >> target;                     // Value to search/insert

    Solution sol;
    int index = sol.searchInsert(nums, target);

    cout << index << "\n";             // Output the index where `target` should be
    return 0;
}
