#include <bits/stdc++.h>
using namespace std;

/*
    File: longest_consecutive.cpp

    Description:
    Finds the length of the longest consecutive elements sequence in an unsorted
    array. Uses an unordered_set to allow O(1) average-time lookups to build
    sequences only from potential “sequence starts.”

    Visualization (example: nums = [100, 4, 200, 1, 3, 2]):
    - Insert all numbers into a set: {100,4,200,1,3,2}.
    - Iterate through each element in the set:
        1. If (it - 1) is not in set, treat `it` as potential sequence start.
           For it = 1: (1-1=0) not in set → start counting: 1,2,3,4 appear → length=4.
        2. For it = 2: (2-1=1) is in set → skip, not start.
        3. For it = 3,4: skip for same reason.
        4. For it = 100: (100-1=99) not in set → but no 101 → length=1.
        5. For it = 200: same → length=1.
    - Maximum length found = 4 (for sequence [1,2,3,4]).

    Time Complexity (TC): O(n)
      - Inserting n elements into the unordered_set: O(n) average.
      - For each element, we only attempt to build a sequence if (it – 1) is absent,
        and counting each sequence takes O(k) where k = length of that sequence.
        Across the entire set, each number is visited at most twice (once in insertion,
        once in sequence-building), so it's O(n).
    Space Complexity (SC): O(n)
      - We store all n elements in the unordered_set.

    Edge cases:
    1. Empty array: return 0 or handle accordingly (this code assumes n ≥ 1).
    2. Single element: return 1.
*/

class Solution {
public:
    int Longest(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> s;
        s.reserve(nums.size());
        for (int x : nums) {
            s.insert(x);
        }

        int longest = 1;

        // For each unique element, try to build its consecutive sequence only if it’s a sequence start
        for (auto it : s) {
            if (s.find(it - 1) == s.end()) {
                // `it` is the start of a sequence
                int cnt = 1;
                int current = it;
                while (s.find(current + 1) != s.end()) {
                    cnt++;
                    current++;
                }
                longest = max(longest, cnt);
            }
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
