class Solution {
public:
    string makeGood(string s) {
        string ret = "";
        for (char c : s) {
            if (ret.size() && abs(ret.back() - c) == 32) ret.pop_back();
            else ret.push_back(c);
        }
        return ret;
    }
};