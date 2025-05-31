#include <bits/stdc++.h>
using namespace std;

/*
    File: Next_permutation_of_array.cpp

    Description:
    Implements the “next permutation” algorithm: given a sequence of numbers,
    transforms it into the lexicographically next greater permutation. If such a
    permutation is not possible (i.e., the sequence is in descending order), it
    rearranges to the lowest possible order (ascending sort).

    Visualization (example: [1, 3, 5, 4, 2]):
    Step 1: Find the rightmost index `i` where nums[i] < nums[i+1].
            In this example: pairs are (1<3), (3<5), (5>4), (4>2). So breakpoint = i=1 (value 3).
    Step 2: Find the smallest element > nums[breakpoint] from the right. Here, breakpoint value = 3.
            Searching from end: 2? no; 4? yes (>3). So swap 3 and 4 → [1, 4, 5, 3, 2].
    Step 3: Reverse everything to the right of `breakpoint` (index 1). Right subarray was [5,3,2].
            Reverse it to [2,3,5]. Final: [1, 4, 2, 3, 5].

    Time Complexity (TC): O(n)
      - One backward scan to find the breakpoint, one backward scan to find the swap target,
        and a reversal of the suffix: each takes O(n) in worst case, so overall O(n).
    Space Complexity (SC): O(1)
      - In-place swaps and reversals, only constant extra space.

    Edge cases:
    1. Entire array is non-increasing (e.g., [5,4,3,2,1]). Then `breakpoint` stays -1, so we reverse the whole array → [1,2,3,4,5].
    2. Small arrays (n=0,1): trivial handling (breakpoint remains -1, reverse does nothing or sorts size 1).
*/

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int n = nums.size();
        int breakpoint = -1;

        // Step 1: Find the first index from right where nums[i] < nums[i+1].
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                breakpoint = i;
                break;
            }
        }

        if (breakpoint == -1) {
            // The sequence is in non-increasing order. Reverse entire array to obtain lowest order.
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find the rightmost element greater than nums[breakpoint], and swap.
        for (int i = n - 1; i > breakpoint; i--) {
            if (nums[i] > nums[breakpoint]) {
                swap(nums[i], nums[breakpoint]);
                break;
            }
        }

        // Step 3: Reverse the subarray to the right of `breakpoint` to get the minimal suffix.
        reverse(nums.begin() + breakpoint + 1, nums.end());
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution ob;
    ob.nextPermutation(nums);

    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}
