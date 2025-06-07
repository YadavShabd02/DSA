#include <bits/stdc++.h>
using namespace std;

/*
    File: Majority_Element.cpp

    Description:
    Uses the Boyer–Moore Voting Algorithm to find the majority element in an array:
    the element that appears more than ⌊n/2⌋ times. First pass identifies a candidate,
    second pass (optional here if guaranteed majority exists) would verify it.

    Visualization (example: nums = [3, 2, 3]):
    - Initialize `cnt = 0`, `el` arbitrary.
    - i=0: cnt=0 → el=3, cnt=1.
    - i=1: nums[1]=2 != el → cnt=0.
    - i=2: cnt=0 → el=3, cnt=1.
    Final candidate `el = 3`.

    Time Complexity (TC): O(n)
      - One pass to find candidate in O(n). No need for second pass if guaranteed.
    Space Complexity (SC): O(1)
      - Only uses two integer variables (`cnt` and `el`).

    Edge cases:
    1. Single element array: returns that element.
    2. Guaranteed majority: no second pass needed.
    3. If majority not guaranteed, one must add a second pass to confirm.
*/

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int cnt = 0;
        int el = 0;  // Candidate majority element

        for (int i = 0; i < nums.size(); i++) {
            if (cnt == 0) {
                // Reset candidate to current element
                el = nums[i];
                cnt = 1;
            }
            else if (nums[i] != el) {
                // Vote against candidate
                cnt--;
            }
            else {
                // Vote for candidate
                cnt++;
            }
        }
        // Optional: second pass to verify `el` is actually the majority if not guaranteed.
        return el;
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
    int ans = ob.majorityElement(nums);

    cout << "Majority Element is: " << ans;
    return 0;
}
