#include <bits/stdc++.h>
using namespace std;

/*
    File: Check_Valid_String.cpp

    Description:
    Given a string s containing three types of characters: '(', ')' and '*',
    where '*' can represent either '(', ')' or an empty string, this function
    determines whether the string can be valid. A valid string is one where
    parentheses are balanced after choosing an interpretation for each '*'.

    Approach:
    - Maintain two counters, `minOpen` and `maxOpen`, tracking the minimum and
      maximum possible number of unmatched '(' at each step:
        • `maxOpen` assumes every '*' is '(', so it increases on '(' or '*',
          and decreases on ')'. If it ever drops below 0, no valid assignment exists.
        • `minOpen` assumes every '*' is ')', so it increases on '(' and
          decreases on ')' or '*'. We clamp `minOpen` to 0 because negative
          unmatched '(' is not possible in reality.
    - If after processing all characters `minOpen` is 0, there exists some
      assignment of '*' that balances the parentheses.

    Visualization (example: s = "(*))"):
      i=0: '(' → minOpen=1, maxOpen=1
      i=1: '*' → minOpen=0 (1−1), maxOpen=2 (1+1)
      i=2: ')' → minOpen=0 (clamped), maxOpen=1 (2−1)
      i=3: ')' → minOpen=0 (clamped), maxOpen=0 (1−1)
      End: minOpen=0 → valid.

    Time Complexity (TC): O(n)
      - Single pass through the string of length n.
    Space Complexity (SC): O(1)
      - Only two integer counters are used.

    Edge Cases:
      1. Empty string: valid (minOpen remains 0).
      2. String of only '*': valid (can treat all '*' as empty).
      3. String starts with ')' without preceding '*' or '(': invalid.
      4. String ends with '(' without trailing '*' to balance: invalid.
*/

class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0;  // Minimum possible count of unmatched '('
        int maxOpen = 0;  // Maximum possible count of unmatched '('

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                // '(' increments both counters
                minOpen++;
                maxOpen++;
            }
            else if (s[i] == ')') {
                // ')' decrements both counters
                minOpen--;
                maxOpen--;
            }
            else {
                // '*' can be '(', ')', or empty:
                //   - For maxOpen, treat '*' as '(' => increment
                //   - For minOpen, treat '*' as ')' => decrement
                minOpen--;
                maxOpen++;
            }

            // Clamp minOpen to 0 (can't have negative real opens)
            if (minOpen < 0) {
                minOpen = 0;
            }
            // If maxOpen is negative, too many ')' -> no valid interpretation
            if (maxOpen < 0) {
                return false;
            }
        }

        // If minOpen == 0, there is a valid way to balance all '('
        return (minOpen == 0);
    }
};

int main() {
    string s;
    getline(cin, s);

    Solution sol;
    bool isValid = sol.checkValidString(s);

    cout << (isValid ? "true" : "false") << endl;
    return 0;
}
