#include <bits/stdc++.h>
using namespace std;

/*
    File: Pascal_Triangle.cpp

    Description:
    Generates the first `numRows` rows of Pascal’s Triangle. Each row’s
    elements correspond to the binomial coefficients. This implementation
    computes each row’s values using a multiplicative formula rather than
    computing from the previous row, achieving O(numRows^2) overall.

    Visualization (example: numRows = 5):
        Row 1: [1]
        Row 2: [1, 1]
        Row 3: [1, 2, 1]
        Row 4: [1, 3, 3, 1]
        Row 5: [1, 4, 6, 4, 1]

    How `rowGen` works (for a given row index `r` = numRows):
      - Start with ans = 1, push it.
      - For col from 1 to r-1:
          ans = ans * (r - col) / col
          push ans.
      - This yields the r-th row (1-indexed).

    Time Complexity (TC): O(numRows^2)
      - We generate row 1 (1 element), row 2 (2 elements), … row numRows (numRows elements).
        Summation = 1 + 2 + … + numRows = O(numRows^2).
    Space Complexity (SC): O(numRows^2)
      - We store all rows in a vector of vectors, total elements ~ (numRows * (numRows + 1) / 2).

    Edge cases:
    1. numRows = 0: returns an empty vector.
    2. numRows = 1: returns [[1]].
*/

class Solution {
public:
    // Helper: generate the exact `numRows`th row (1-indexed) of Pascal's triangle
    void rowGen(int numRows, vector<int> &ansRow) {
        long long ans = 1;
        ansRow.push_back(1);  // The first element is always 1

        // For col from 1 to numRows-1, use the binomial coefficient formula:
        //   C(r-1, col) = previous * (r - col) / col
        for (int col = 1; col < numRows; col++) {
            ans = ans * (numRows - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> Ans;
        for (int i = 1; i <= numRows; i++) {
            vector<int> temp;
            rowGen(i, temp);
            Ans.push_back(temp);
        }
        return Ans;
    }
};

int main() {
    int n;
    cin >> n;

    Solution sol;
    vector<vector<int>> ans = sol.generate(n);

    // Print in the specified format: [ [row1], [row2], ... ]
    for (int i = 0; i < n; i++) {
        cout << "[";
        for (size_t j = 0; j < ans[i].size(); j++) {
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
