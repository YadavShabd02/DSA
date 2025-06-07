#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Returns the index of the smallest element >= x, or -1 if none exists
    int Ceil(const vector<int>& nums, int x) {
        int ans = -1, low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return nums[ans];
    }

    // Returns the index of the largest element <= x, or -1 if none exists
    int Floor(const vector<int>& nums, int x) {
        int ans = -1, low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= x) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return nums[ans];
    }

public:
    // Assumes nums is sorted in non-decreasing order
    // Returns a vector of two integers: {floorIndex, ceilIndex}
    vector<int> getFloorAndCeil(const vector<int>& nums, int x) {
        vector<int> ans;
        ans.push_back(Floor(nums, x));
        ans.push_back(Ceil(nums, x));
        return ans;
    }
};

int main() {
    int n;
    cin >> n;                          // Number of elements in the sorted array
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];                // Input the sorted array elements
    }

    int target;
    cin >> target;                    // The target value

    Solution sol;
    vector<int> result = sol.getFloorAndCeil(nums, target);

    // Print floor index followed by ceil index (space-separated)
    // If no floor/ceil exists, the value will be -1
    cout << result[0] << " " << result[1];
    return 0;
}
