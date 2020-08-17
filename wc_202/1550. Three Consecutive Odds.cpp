class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int odd = 0;
        for (int n : arr) {
            if (n & 1) {
                if (++odd == 3)
                    return true;
            } else odd = 0;
        }
        return false;
    }
};