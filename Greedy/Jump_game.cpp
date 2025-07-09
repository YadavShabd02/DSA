#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i <= maxi) {
                maxi = max(maxi, i + nums[i]);
            }
            else return false;
        }
        return true;
    }
};

int main() {
    int m;
    cin >> m;                      
    vector<int> num(m);
    for (int i = 0; i < m; ++i) {
        cin >> num[i];              
    }                    

    Solution sol;
    bool result = sol.canJump(num);

    if (result) {
        cout << "TRUE" << endl;
    }
    else cout << "FALSE" << endl;
    return 0;
}