#include <bits/stdc++.h>
using namespace std;

/*
    File: Max_Meetings_in_Room.cpp

    Description:
    Given 'n' meetings with start times `s[]` and end times `e[]`, this code selects 
    the maximum number of non-overlapping meetings that can be scheduled in one room.
    It uses a greedy algorithm:
      1. Sort all meetings by their finish time (earliest first).
      2. Always pick the next meeting whose start time is strictly greater than the 
         end time of the last selected meeting.

    Visualization (example):
      Meetings (pos: [1..6]): 
        1:[1,2], 2:[3,4], 3:[0,5], 4:[5,7], 5:[8,9], 6:[5,9]
      Sorted by end:
        (1,2,pos1), (3,4,pos2), (0,5,pos3), (5,7,pos4), (8,9,pos5), (5,9,pos6)
      Greedy selection:
        • Select pos1 (end=2)
        • Next start>2 → pos2 (3–4)
        • Next start>4 → pos4 (5–7)
        • Next start>7 → pos5 (8–9)
      Selected order: [1, 2, 4, 5]

    Time Complexity (TC): O(n log n)
      – Sorting takes O(n log n), selecting meetings takes O(n).

    Space Complexity (SC): O(n)
      – Uses an array of n `meeting` structs plus an answer vector.

    Edge Cases:
      1. n = 0 (no meetings)
      2. All meetings overlap (only one can be chosen)
      3. Meetings share the same end time (tie-broken by original position)
*/

struct meeting {
    int start;
    int end;
    int pos;
};

class Solution {
public:
    // Sort by end time ascending; if equal, by original position ascending
    static bool comparator(struct meeting m1, struct meeting m2) {
        if (m1.end < m2.end) return true;
        else if (m1.end > m2.end) return false;
        else return m1.pos < m2.pos;
    }

    void maxMeetings(int s[], int e[], int n) {
        // Build array of meetings
        struct meeting meet[n];
        for (int i = 0; i < n; i++) {
            meet[i].start = s[i];
            meet[i].end   = e[i];
            meet[i].pos   = i + 1;  // 1-based index for output
        }

        // Sort meetings by finish time
        sort(meet, meet + n, comparator);

        vector<int> answer;
        // Pick the first meeting
        int limit = meet[0].end;
        answer.push_back(meet[0].pos);

        // Pick subsequent meetings if they start after the last selected end
        for (int i = 1; i < n; i++) {
            if (meet[i].start > limit) {
                limit = meet[i].end;
                answer.push_back(meet[i].pos);
            }
        }

        // Output the selected meeting order
        cout << "The order in which the meetings will be performed is\n";
        for (int idx : answer) {
            cout << idx << " ";
        }
        cout << endl;
    }
};

int main() {
    Solution obj;
    int n = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[]   = {2, 4, 5, 7, 9, 9};

    obj.maxMeetings(start, end, n);
    return 0;
}
