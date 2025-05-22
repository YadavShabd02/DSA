#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rowGen(int numRows, vector<int> &ansRow)
    {
        long long ans = 1;
        ansRow.push_back(1);
        for (int col = 1; col < numRows; col++)
        {
            ans = ans * (numRows - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }
    }

    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> Ans;
        for (int i = 1; i <= numRows; i++)
        {
            vector<int> temp;
            rowGen(i, temp);
            Ans.push_back(temp);
        }
        return Ans;
    }
};

int main()
{
    int n;
    cin >> n;

    Solution sol;
    vector<vector<int>> ans = sol.generate(n);

    for (int i = 0; i < n; i++)
    {
        cout << "[";
        for (size_t j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
            if (j + 1 < ans[i].size())
                cout << ", ";
        }
        cout << "]";
        if (i + 1 < n)
            cout << ", ";
    }
    cout << "\n";
    return 0;
}