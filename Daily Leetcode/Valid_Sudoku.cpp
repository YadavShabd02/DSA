#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> col(9);
        vector<unordered_set<char>> boxes(9);

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char val = board[r][c];

                if(val == '.') {
                    continue;
                }

                if (rows[r].count(val)) {
                    return false;
                }
                rows[r].insert(val);

                if (col[c].count(val)) {
                    return false;
                }
                col[c].insert(val);
                
                int idx = (r / 3) * 3 + (c / 3);
                if (boxes[idx].count(val)) {
                    return false;
                }
                boxes[idx].insert(val);
            }
        }

        return true;
    }
};

int main() {

    return 0;
}