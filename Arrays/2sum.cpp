#include <bits/stdc++.h>
using namespace std;

/*
    File: 2sum.cpp

    Description:
    Given an array of integers and a target, returns indices of the two numbers
    such that they add up to the target. Uses a hash map (unordered_map) to
    look up complements in O(1) average time.

    Visualization (example: nums = [2,7,11,15], target = 9):
    - i=0: nums[0] = 2 → complement = 9 - 2 = 7 → 7 not in map yet → insert (2 → index 0).
    - i=1: nums[1] = 7 → complement = 9 - 7 = 2 → 2 found in map (index 0) → return [0, 1].

    Time Complexity (TC): O(n)
      - Single pass over `nums`. Each lookup and insert in unordered_map is amortized O(1).
    Space Complexity (SC): O(n)
      - In worst case, we store every element in the unordered_map.

    Edge cases:
    1. No valid pair: returns an empty vector.
    2. Exactly one valid pair guaranteed: returns the pair of indices.
*/

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> m;
        m.reserve(nums.size());  // Reserve to avoid too many rehashes

        for (int i = 0; i < nums.size(); ++i) {
            int c = target - nums[i];
            auto it = m.find(c);
            if (it != m.end()) {
                // Found complement → return indices
                return {it->second, i};
            }
            // Store current number and its index
            m[nums[i]] = i;
        }
        return {};  // No pair found
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int target;
    cin >> target;

    Solution sol;
    vector<int> ans = sol.twoSum(nums, target);

    if (ans.size() == 2) {
        cout << ans[0] << " " << ans[1] << "\n";
    } else {
        cout << "No valid pair found\n";
    }
    return 0;
}
