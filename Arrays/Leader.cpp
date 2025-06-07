#include <bits/stdc++.h>
using namespace std;

/*
    File: Leader.cpp

    Description:
    Finds all “leader” elements in the array. An element is a leader if it is
    strictly greater than all elements to its right. After collecting them by
    scanning from right to left, we sort them in ascending order before returning.

    Visualization (example: [16, 17, 4, 3, 5, 2]):
    - Start from the rightmost element = 2 → maxi = 2 → 2 is a leader.
    - Next = 5 > 2 → maxi = 5 → 5 is a leader.
    - Next = 3 < 5 → skip.
    - Next = 4 < 5 → skip.
    - Next = 17 > 5 → maxi = 17 → 17 is a leader.
    - Next = 16 < 17 → skip.
    Leaders collected in reverse order: [2, 5, 17]. Sort them → [2, 5, 17].

    Time Complexity (TC): O(n log n)
      - O(n) to scan from right to left and collect leaders; O(m log m) to sort the collected leaders,
        where m ≤ n. In worst case, all elements are leaders (strictly increasing from left to right),
        so sorting m = n costs O(n log n).
    Space Complexity (SC): O(n)
      - In the worst case, the `ans` vector stores up to n leaders before sorting.

    Edge cases:
    1. Strictly increasing array: every element is a leader; final result is the sorted array itself.
    2. Strictly decreasing array: only the first (leftmost) element is not a leader; all others are leaders.
*/

class Solution {
public:
    vector<int> Leader(vector<int>& nums) {
        int maxi = INT_MIN;
        vector<int> ans;
        int n = nums.size();

        // Scan from right to left
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > maxi) {
                // Current element is greater than anything seen to its right → it’s a leader
                ans.push_back(nums[i]);
                maxi = nums[i];
            }
        }

        // `ans` currently holds leaders in reverse order
        sort(ans.begin(), ans.end());
        return ans;
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
    vector<int> ans = ob.Leader(nums);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
