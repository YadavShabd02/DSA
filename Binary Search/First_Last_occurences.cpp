#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int lowerbound (vector<int>& nums, int target) {
        int ans = nums.size();           // Default: insert at end if not found
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;  // Prevents potential overflow

            if (nums[mid] >= target) {
                // nums[mid] is a candidate (either equal to target or larger),
                // so record mid and move left to check if there’s an earlier position.
                ans = mid;
                high = mid - 1;
            }
            else {
                // nums[mid] < target, so the insert position must be right of mid.
                low = mid + 1;
            }
        }
        return ans;
    }

    int upperBound(vector<int> &nums, int x) {
        int low = 0, high = nums.size() - 1;
        int ans = nums.size();

        while (low <= high) {
            int mid = (low + high) / 2;
            // maybe an answer
            if (nums[mid] > x) {
                ans = mid;
                //look for smaller index on the left
                high = mid - 1;
            }
            else {
                low = mid + 1; // look on the right
            }
        }
        return ans;
    }


public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lowerbound (nums, target);
        if (lb == nums.size() || nums[lb] != target) return {-1, -1};
        return {lb, upperBound(nums, target) - 1};
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
    vector<int> result = sol.searchRange(nums, target);

    // Print floor index followed by ceil index (space-separated)
    // If no floor/ceil exists, the value will be -1
    cout << result[0] << " " << result[1];
    return 0;
}