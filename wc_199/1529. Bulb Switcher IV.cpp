// https://leetcode.com/problems/bulb-switcher-iv/

/*
Example 1:

Input: target = "10111"
Output: 3
Explanation: Initial configuration "00000".
flip from the third bulb:  "00000" -> "00111"
flip from the first bulb:  "00111" -> "11000"
flip from the second bulb:  "11000" -> "10111"
We need at least 3 flip operations to form target.
Example 2:

Input: target = "101"
Output: 3
Explanation: "000" -> "111" -> "100" -> "101".
Example 3:

Input: target = "00000"
Output: 0
Example 4:

Input: target = "001011101"
Output: 5
*/
class Solution {
public:
    int minFlips(string target) {
        int state = 0, cnt = 0;
        for (char c : target) {
            if (c - '0' != state) {
                cnt++;
                state = !state;
            }
        }
        return cnt;        
    }
};