#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n-1] > nums[n-2]) return n-1;
        int low=1, high=n-2;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
                return mid;
            }
            else if (nums[mid-1] < nums[mid]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    int n;
    cin >> n;                      // Number of elements in the rotated sorted array
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];            // Input the array elements
    }

    Solution sol;
    int minimum = sol.findPeakElement(nums);

    cout << minimum << "\n";       // Output the minimum element
    return 0;
}