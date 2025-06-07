#include <bits/stdc++.h>
using namespace std;

/*
    File: Rearrange_array_by_sign_complete.cpp

    Description:
    Rearranges an array so that positive and negative numbers alternate. Unlike
    the simpler variant, this version does not assume equal counts; it first
    collects positives and negatives into separate arrays, then merges them in
    alternating fashion, appending any leftover values at the end.

    Visualization (example: nums = [3, -2, 1, -5, 4]):
    - pos = [3, 1, 4], neg = [-2, -5]
    - pos.size()=3 > neg.size()=2 → we’ll weave up to length 2:
       i=0: nums[0] = pos[0]=3, nums[1] = neg[0]=-2
       i=1: nums[2] = pos[1]=1, nums[3] = neg[1]=-5
    - We used up all negatives. Remaining positives: pos[2] = 4 → place at nums[4].
    Final: [3, -2, 1, -5, 4]

    Time Complexity (TC): O(n)
      - One pass to separate, one to weave; all operations O(1) per element.
    Space Complexity (SC): O(n)
      - Two auxiliary arrays `pos` and `neg` whose total size = n.

    Edge cases:
    1. All positives or all negatives: result is just the original array.
    2. Difference in counts: leftover elements append at end.
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> neg, pos;
        int n = nums.size();

        // Separate positives and negatives
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                pos.push_back(nums[i]);
            } else {
                neg.push_back(nums[i]);
            }
        }

        // Refill `nums` by weaving pos and neg
        if (pos.size() > neg.size()) {
            // Weave until negatives run out
            for (int i = 0; i < neg.size(); i++) {
                nums[2 * i] = pos[i];
                nums[2 * i + 1] = neg[i];
            }
            // Append remaining positives
            for (int i = 0; i < pos.size() - neg.size(); i++) {
                nums[2 * neg.size() + i] = pos[neg.size() + i];
            }
        } else {
            // pos.size() ≤ neg.size()
            for (int i = 0; i < pos.size(); i++) {
                nums[2 * i] = pos[i];
                nums[2 * i + 1] = neg[i];
            }
            // Append remaining negatives
            for (int i = 0; i < neg.size() - pos.size(); i++) {
                nums[2 * pos.size() + i] = neg[pos.size() + i];
            }
        }
        return nums;
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
