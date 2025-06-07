#include <bits/stdc++.h>
using namespace std;

/*
    File: Single_Element_in_a_Sorted_Array.cpp

    Description:
    Given a sorted array `nums` where every element appears exactly twice except for one element 
    that appears only once, this code finds and returns that single non-duplicate element. 
    It uses a modified binary search leveraging index parity to locate the unique element in O(log n) time.

    Problem Context:
    - Array is sorted and its length `n` is odd.
    - All elements except one appear exactly twice and are adjacent (e.g., [1,1,2,3,3,4,4,8,8]).
    - We want to find the single element (2 in this example) in logarithmic time without extra space.

    Approach:
    - Check edge cases first: if the single element is at the beginning or the end.
    - Use binary search on indices [1..n-2]:
        * For a given `mid`, if `nums[mid]` is not equal to its neighbors, it’s the answer.
        * Otherwise, determine which half (left or right) contains the single element by comparing 
          `mid`’s parity with its matching side:
            - If `mid` is odd and `nums[mid] == nums[mid-1]`, the pair is left-aligned, so move `low = mid + 1`.
            - If `mid` is even and `nums[mid] == nums[mid+1]`, the pair is right-aligned, so also move `low = mid + 1`.
            - Otherwise, move `high = mid - 1`.
    - This parity-based logic works because before the single element, pairs start at even indices, 
      and after the single element, pairs start at odd indices.

    Visualization (example: nums = [1,1,2,2,3,3,4,8,8]):
      n = 9
      Step 1: Check edges:
        nums[0] == nums[1] (1 == 1) → first is not unique.
        nums[8] == nums[7] (8 == 8) → last is not unique.

      Binary Search on [low=1 .. high=7]:
      Iteration 1:
        mid = (1 + 7) / 2 = 4 → nums[4] = 3
        nums[4-1] = nums[3] = 2, nums[4+1] = nums[5] = 3
        nums[mid] == nums[mid+1] (3 == 3) AND mid is even (4 % 2 == 0)
          → Pair is right-aligned (3’s pair starts at mid=4), so the single element must be left
          → Move high = mid - 1 = 3

      Iteration 2:
        low = 1, high = 3 → mid = (1 + 3) / 2 = 2 → nums[2] = 2
        nums[2-1] = nums[1] = 1, nums[2+1] = nums[3] = 2
        nums[mid] == nums[mid+1] (2 == 2) AND mid is even (2 % 2 == 0)
          → Pair is right-aligned, single element is to the left
          → Move high = mid - 1 = 1

      Iteration 3:
        low = 1, high = 1 → mid = 1 → nums[1] = 1
        nums[1-1] = nums[0] = 1, nums[1+1] = nums[2] = 2
        nums[mid] == nums[mid-1] (1 == 1) AND mid is odd (1 % 2 == 1)
          → Pair is left-aligned, so the single element is to the right
          → Move low = mid + 1 = 2

      Now low (2) > high (1) → exit loop. But notice we haven't returned inside loop because we haven’t found 
      an index where nums[mid] differs from both neighbors. However, by this point, we know the only candidate 
      left must be at low = 2. To cover such scenarios, edge-case checks caught index 2 earlier:
        nums[2] != nums[1] and nums[2] != nums[3] → returns nums[2] = 2.

    Time Complexity (TC): O(log n)
      - We halve the search window each iteration via binary search.

    Space Complexity (SC): O(1)
      - Uses only a few integer variables (`low`, `high`, `mid`, `n`) with no extra data structures.

    Edge Cases:
      1. Array of size 1 (n == 1): return `nums[0]` directly.
      2. Unique element at index 0: if `nums[0] != nums[1]`.
      3. Unique element at index n-1: if `nums[n-1] != nums[n-2]`.
      4. All other cases: binary search between indices 1 and n-2 safely finds the single element.

    Detailed Branch Logic:
      - If `nums[mid] != nums[mid-1]` and `nums[mid] != nums[mid+1]`: `nums[mid]` is the unique element.
      - Else, check pair alignment:
          * `(mid % 2 == 1 && nums[mid-1] == nums[mid])`: `mid` odd and matches left neighbor → unique is to the right.
          * `(mid % 2 == 0 && nums[mid+1] == nums[mid])`: `mid` even and matches right neighbor → unique is to the right.
          * Otherwise, unique is to the left (`high = mid - 1`).
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        // Edge case: only one element
        if (n == 1) 
            return nums[0];
        // Check if the first element is unique
        if (nums[0] != nums[1]) 
            return nums[0];
        // Check if the last element is unique
        if (nums[n-1] != nums[n-2]) 
            return nums[n-1];

        int low = 1;
        int high = n - 2;

        // Binary search between indices 1 and n-2
        while (low <= high) {
            int mid = (low + high) / 2;

            // If nums[mid] differs from both neighbors, it's the unique element
            if (nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]) {
                return nums[mid];
            }
            // If mid is odd and matches with left neighbor, or mid is even and matches right neighbor,
            // the single element lies to the right
            else if ((mid % 2 == 1 && nums[mid-1] == nums[mid]) || 
                     (mid % 2 == 0 && nums[mid+1] == nums[mid])) {
                low = mid + 1;
            }
            // Otherwise, the single element lies to the left
            else {
                high = mid - 1;
            }
        }

        // Should never reach here if input constraints are satisfied
        return -1;
    }
};

int main() {
    int n;
    cin >> n;                      // Number of elements in the array (odd, ≥1)
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];            // Input the sorted array with exactly one unique element
    }

    Solution sol;
    int uniqueVal = sol.singleNonDuplicate(nums);

    cout << uniqueVal << "\n";     // Output the single non-duplicate element
    return 0;
}
