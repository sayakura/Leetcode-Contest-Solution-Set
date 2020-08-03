//  https://leetcode.com/contest/weekly-contest-199/problems/shuffle-string/

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ret(s);
        for (int i = 0; i < s.size(); i++) {
            ret[indices[i]] = s[i];
        }
        return ret;
    }
};