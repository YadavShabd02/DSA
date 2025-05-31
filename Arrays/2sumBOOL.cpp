#include <bits/stdc++.h>
using namespace std;

/*
    File: 2sumBOOL.cpp

    Description:
    Given an array of integers and a target value, determines if there exist two
    numbers in the array that sum up to the target. Returns "YES" if such a pair
    exists, otherwise "NO". Uses the two-pointer technique after sorting.

    Visualization (example: arr = [3, 1, 4, 2], target = 6):
    1. Sort → [1, 2, 3, 4]
    2. left = 0 (value 1), right = 3 (value 4):
       sum = 1 + 4 = 5 < 6 → move left++ → left = 1 (value 2)
    3. left = 1 (value 2), right = 3 (value 4):
       sum = 2 + 4 = 6 == 6 → FOUND → return "YES"

    Time Complexity (TC): O(n log n)
      - Sorting costs O(n log n), then one O(n) two-pointer scan.
    Space Complexity (SC): O(1) or O(n) depending on sorting implementation
      - If in-place sort is used, extra space is O(1) aside from input. Some C++ implementations may use O(log n) recursion stack.

    Edge cases:
    1. Duplicate values (e.g., [3,3], target=6): the two-pointer approach still works.
    2. Array of size < 2: immediately returns "NO".
*/

string twoSum(int n, vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());  // Sort the array first
    int left = 0, right = n - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return "YES";
        }
        else if (sum < target) {
            left++;    // Need a larger sum → move left pointer right
        }
        else {
            right--;   // Sum too big → move right pointer left
        }
    }
    return "NO";
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    string ans = twoSum(n, arr, target);
    cout << ans << endl;
    return 0;
}
