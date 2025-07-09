#include <bits/stdc++.h>
using namespace std;

/*
    File: Erase_Overlap_Intervals.cpp

    Description:
    Given a collection of intervals, this code finds the minimum number of intervals 
    you need to remove to make the rest of the intervals non-overlapping. We achieve this 
    by selecting the maximum number of non-overlapping intervals via a greedy strategy:
      1. Sort all intervals by their finish time (earliest finish first).
      2. Iterate through the sorted list, always picking the next interval whose start 
         is not less than the end of the last selected interval.
    The answer is total intervals minus the count of selected (non-overlapping) intervals.

    Visualization (example):
      intervals = [[1,2],[2,3],[3,4],[1,3]]
      Sorted by end time: [[1,2],[2,3],[1,3],[3,4]]
        • Select [1,2] (end=2), count=1
        • [2,3]: start=2 ≥ 2 → select, count=2 (end=3)
        • [1,3]: start=1 < 3 → skip
        • [3,4]: start=3 ≥ 3 → select, count=3
      Non-overlapping = 3, so removals = 4 − 3 = 1.

    Time Complexity (TC): O(n log n)
      - Sorting intervals takes O(n log n).
      - Single pass selection takes O(n).

    Space Complexity (SC): O(log n) on average due to sort recursion (or O(n) worst-case),
      plus O(1) for pointers and counters.

    Edge Cases:
      1. n = 0: no intervals → return 0.
      2. All intervals non-overlapping: removals = 0.
      3. All intervals overlap: removals = n − 1.
      4. Intervals with identical end times: tie-broken by stable sort (preserves input order),
         selection logic still holds.

    Inline Comments below explain each key step.
*/

class Solution {
public:
    // Comparator to sort intervals by their ending time (ascending)
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();            
        if (n == 0) return 0;                // No intervals → nothing to remove

        // Sort intervals by end time
        sort(intervals.begin(), intervals.end(), cmp);

        // Always pick the first interval after sorting
        int lastEnd = intervals[0][1];      
        int count = 1;                      // Count of non-overlapping intervals

        // Iterate through the remaining intervals
        for (int i = 1; i < n; i++) {
            // If the current interval starts after or exactly at the last end,
            // it does not overlap and can be selected
            if (intervals[i][0] >= lastEnd) {
                lastEnd = intervals[i][1];  // Update last selected end time
                count++;                    // Increment the count
            }
            // Otherwise, skip this interval (i.e., consider it removed)
        }

        // Total removals = total intervals − selected non-overlapping intervals
        return n - count;
    }
};

int main() {
    int n;
    cin >> n;                            // Number of intervals
    vector<vector<int>> intervals(n, vector<int>(2));

    // Read the intervals
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i][0]         // start time
            >> intervals[i][1];        // end time
    }

    Solution sol;
    int removals = sol.eraseOverlapIntervals(intervals);

    cout << removals << "\n";           // Output the minimum removals required
    return 0;
}
