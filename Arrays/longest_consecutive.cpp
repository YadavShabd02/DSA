#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int Longest(vector<int>& nums) {
            int longest = 1, cnt = 1;
            int currentmin = 0;
            unordered_set<int> ans(nums.size());

            for (int i = 0; i < nums.size(); i++) {
                ans.insert(nums[i]);
            }

            for (auto it : ans) {
                if(ans.find(it - 1) == ans.end()) {
                    cnt = 1;
                    currentmin = it;
                }
                while (ans.find(currentmin + 1) != ans.end()) {
                    cnt++;
                    currentmin++;
                }
                longest = max(longest, cnt);
            }
            return longest;
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
    cout << ob.Longest(nums) << endl;

    return 0;
}