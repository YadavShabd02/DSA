#include <bits/stdc++.h>
using namespace std;

/*
    File: Rearrange_array_by_sign.cpp

    Description:
    Given an array of positive and negative integers (equal count guaranteed),
    rearranges the array so that positive and negative numbers alternate, while
    preserving original relative order among positives and among negatives.

    Visualization (example: nums = [3, -2, 1, -5, 4, -1]):
    - We set up two indices: `pos` = 0 (next free even index for a positive),
      `neg` = 1 (next free odd index for a negative).
    - Traverse the original array in one pass:
        i=0: nums[0] = 3 → place at ans[0], pos += 2 → pos=2
        i=1: nums[1] = -2 → place at ans[1], neg += 2 → neg=3
        i=2: nums[2] = 1 → place at ans[2], pos += 2 → pos=4
        i=3: nums[3] = -5 → place at ans[3], neg += 2 → neg=5
        i=4: nums[4] = 4 → place at ans[4], pos += 2 → pos=6
        i=5: nums[5] = -1 → place at ans[5], neg += 2 → neg=7
    - Final `ans`: [3, -2, 1, -5, 4, -1]

    Time Complexity (TC): O(n)
      - One pass to build `ans`. All operations are O(1) inside the loop.
    Space Complexity (SC): O(n)
      - We use a separate output array `ans` of size n.

    Edge cases:
    1. The problem statement usually guarantees equal count of positives and negatives.
       If counts differ, the code still places what it can but may leave trailing zeros in `ans`.
    2. All positives or all negatives: result will be lost in zeros for the missing sign positions.
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);  // Initialize result with zeros
        int pos = 0, neg = 1;   // Even indices for positives, odd for negatives

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans[pos] = nums[i];
                pos += 2;
            }
            else {
                ans[neg] = nums[i];
                neg += 2;
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    Solution sol;
    vector<int> ans = sol.rearrangeArray(nums);
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}
