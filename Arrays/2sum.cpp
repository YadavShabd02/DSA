#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> m;
        m.reserve(nums.size()); 
        for (int i = 0; i < nums.size(); ++i)
        {
            int c = target - nums[i];
            auto it = m.find(c);
            if (it != m.end())
                return {it->second, i};
            m[nums[i]] = i;
        }
        return {};
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