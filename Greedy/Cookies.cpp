#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int l=0, r=0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while (l < s.size() && r < g.size()) {
            if (s[l] >= g[r]) {
                r = r + 1;
            }
            l = l + 1;
        }
        return r;
    }
};

int main() {
    int n;
    cin >> n;   
    vector<int> nums(n);                     
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];               
    }

    int m;
    cin >> m;                      
    vector<int> num(m);
    for (int i = 0; i < m; ++i) {
        cin >> num[i];            
    }                    

    Solution sol;
    int result = sol.findContentChildren(nums, num);

    cout << result << endl;
    return 0;
}