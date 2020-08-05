class Solution {
public:
    int numSub(string s) {
        long long ret = 0, count = 0, mod = 1e9 + 7;
        
        for (int i = 0; i < s.size(); i++) {
            count = s[i] == '1' ? count + 1 : 0;
            ret += count;
        }
        return ret % mod;
    }
};