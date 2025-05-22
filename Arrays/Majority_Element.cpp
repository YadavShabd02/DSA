#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int cnt = 0;
        int el;
        for (int i = 0; i < nums.size(); i++)
        {
            if (cnt == 0)
            {
                el = nums[i];
                cnt++;
            }
            else if (nums[i] != el)
            {
                cnt--;
            }
            else
            {
                cnt++;
            }
        }
        return el;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution ob;
    int ans = ob.majorityElement(nums);

    cout << "Major Element is: " << ans;
    return 0;
}