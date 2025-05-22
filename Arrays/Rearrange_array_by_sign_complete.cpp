#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> rearrangeArray(vector<int>& nums) {
            vector<int> neg, pos;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > 0) {
                    pos.push_back(nums[i]); 
                }
                else {
                    neg.push_back(nums[i]);
                }
            }

            if (pos.size() > neg.size()) {
                for (int i = 0; i < neg.size(); i++) {
                    nums[2 * i] = pos[i];
                    nums[2 * i + 1] = neg[i];
                }
                for (int i = 0; i < pos.size() - neg.size(); i++) {
                    nums[2 * neg.size() + i] = pos[neg.size() + i];
                }
            }
            else {
                for (int i = 0; i < pos.size(); i++) {
                    nums[2 * i] = pos[i];
                    nums[2 * i + 1] = neg[i];
                }
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