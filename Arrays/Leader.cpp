#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> Leader(vector<int>& nums) {
            int maxi = INT_MIN;
            vector<int> ans;
            for (int i = nums.size() - 1; i >= 0; i--) {
                if (nums[i] > maxi) {
                    ans.push_back(nums[i]);
                    maxi = nums[i];
                }
            }
            sort(ans.begin(), ans.end());
            return ans;
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
    vector<int> ans = ob.Leader(nums);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}