#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int jump = 0, l = 0, r = 0;
        while (r < nums.size() - 1) {
            int farthest = 0;
            for (int i = l; i <= r; i++) {
                farthest = max(farthest, i + nums[i]);
        }
            l = r + 1;
            r = farthest;
            jump++;
        }
        return jump;
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
    int result = sol.jump(num);
    cout << result << endl;
    return 0;
}