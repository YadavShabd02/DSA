#include <bits/stdc++.h>
using namespace std;

/*
    File: Sort_0_1_2.cpp

    Description:
    Sorts an array containing only 0s, 1s, and 2s (Dutch National Flag problem),
    rearranging in-place so that all 0s come first, then 1s, then 2s. Uses three
    indices: `low`, `mid`, and `high`. 

    Visualization (example: nums = [2, 0, 2, 1, 1, 0]):
    - low = 0, mid = 0, high = 5
    - i=0 (mid=0): nums[0]=2 → swap(nums[mid], nums[high]) → swap(2, 0) → nums=[0,0,2,1,1,2]; high=4; (don’t move mid yet)
    - mid still 0: nums[0]=0 → swap(nums[low],nums[mid]) → same; low=1; mid=1 → nums=[0,0,2,1,1,2]
    - mid=1: nums[1]=0 → swap(nums[low],nums[mid]) → same; low=2; mid=2
    - mid=2: nums[2]=2 → swap(nums[mid],nums[high]) → swap(2,1) → nums=[0,0,1,1,2,2]; high=3; (mid stays)
    - mid=2: nums[2]=1 → mid=3
    - mid=3: nums[3]=1 → mid=4 (now mid > high → stop)
    Final: [0, 0, 1, 1, 2, 2]

    Time Complexity (TC): O(n)
      - Single pass: each element is inspected once, and either mid or high moves.
    Space Complexity (SC): O(1)
      - In-place sorting with three pointers, no extra arrays.

    Edge cases:
    1. All elements the same: loop still visits each index, but swaps are trivial/no-op.
    2. Empty array: no operations.
    3. Already sorted: prunes quickly through mid increments.
*/

class Solution {
public:
    void Sort(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                // Swap 0 to the front segment
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                // 1 is in the correct “middle” segment → just move mid
                mid++;
            }
            else { // nums[mid] == 2
                // Swap 2 to the end segment
                swap(nums[mid], nums[high]);
                high--;
                // Do not increment mid because swapped element at mid might be 0 or 1
            }
        }
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
    ob.Sort(nums);

    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << nums[i];
    }
    cout << "]";
    return 0;
}
