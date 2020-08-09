class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0", t;
        for (int i = 1; i <= n; i++) {
            t = s + "1";
            for (char &c : s)
                c = '0' + '1' - c;
            reverse(s.begin(), s.end());
            s = t + s;
        }
        return t[k - 1];
    } 
};