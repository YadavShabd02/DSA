#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool lemonade (vector<int> arr) {
            int five = 0, ten = 0;
            for (int i = 0; i < arr.size(); i++) {
                if (arr[i] == 5) {
                    five++;
                    continue;
                }
                else if (arr[i] == 10) {
                    if (five) {
                        five--;
                        ten++;
                    }
                    else return false;
                }
                else {
                    if (five && ten) {
                        ten--;
                        five--;
                    }
                    else if (five >= 3) {
                        five = five - 3;
                    }
                    else return false;
                }
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
    bool result = sol.lemonade(num);

    if (result) {
        cout << "TRUE" << endl;
    }
    else cout << "FALSE" << endl;
    return 0;
}